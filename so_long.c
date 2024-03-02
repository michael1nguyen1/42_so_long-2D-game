/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:51:15 by linhnguy          #+#    #+#             */
/*   Updated: 2024/03/02 17:16:57 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int array_len(char **a)
{
	int	i;
	
	i = 0;
	while (a[i])
	{
		i++;
	}
	return(i);
}

void free_array(char **array)
{
	int i;
	i = 0;
	
	while (array[i])
		free(array[i++]);
	free(array);
}

void floodfill(char **copy, t_flood *cur)
{
	if(copy[cur->cur_y][cur->cur_x] == 'F' || copy[cur->cur_y][cur->cur_x] == '1' )
		return ;
	copy[cur->cur_y][cur->cur_x] = 'F';
	floodfill(copy, &(t_flood){cur->cur_x - 1, cur->cur_y});
	floodfill(copy, &(t_flood){cur->cur_x + 1, cur->cur_y});
	floodfill(copy, &(t_flood){cur->cur_x, cur->cur_y - 1});
	floodfill(copy, &(t_flood){cur->cur_x, cur->cur_y + 1});
}

char **copy_array(char **a)
{
	int		i;
	char	**b;
	
	i = 0;
	b = malloc((array_len(a) + 1) * sizeof(char *));
	if (!b)
		return (NULL);
	while (a[i])
	{
		b[i] = ft_strdup(a[i]);
		if (!b[i])
			return(NULL);
		i++;
	}
	b[i] = NULL;
	return(b);
}

t_flood *coordinates(char **a, char object)
{
	int		i;
	int		j;
	t_flood *coor;

	i = 0;
	coor = ft_calloc(1 , sizeof(t_flood));
	while (a[i])
	{
		j = 0;
		while (a[i][j])
		{
			if (a[i][j] == object)
			{
				coor->cur_x = j;
				coor->cur_y = i;
			}
			j++;
		}
		i++;
	}
	return (coor);
}

bool check_fill(char **map)
{
	int i;
	int	j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'E' || map[i][j] == 'C')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool winnable(char **a)
{
	t_flood		*player;
	char		object;
	char		**copy;
	bool		check;

	object = 'P';
	player = coordinates(a, object);
	copy = copy_array(a);
	if (!copy)
		return (false);
	
	floodfill(copy, player);
	check = check_fill(copy);
	if (!check)
	{
		write(2, "Error\nSomething on the map is unreachable \xF0\x9F\x98\xB1\n", 39);
		return (1);
	}
	free_array(copy);
	free(player);
	return (true);
}

bool all_there(char **a)
{
	int 	i;
	int 	j;
	t_check check;
	
	check.P = false;
    check.C = false;
    check.E = false;
	i = 0;
	while(a[i])
	{
		j = 0;
		while(a[i][j])
		{
		if (a[i][j] == 'P')
				check.P = true;
		else if (a[i][j] == 'C')
				check.C = true;
		else if (a[i][j] == 'E') 
				check.E = true;
			j++;
		}
		i++;
	}
	return (check.P && check.C && check.E);
}

bool unwanted_char(char **a)
{
	int i;
	int j;

	i = 0;
	while (a[i])
	{
		j = 0;
		while(a[i][j])
		{
			if (a[i][j] != 'P' && a[i][j] != 'C' && a[i][j] != 'E' 
				&& a[i][j] != '0' && a[i][j] != '1')
				return (false);
			j++;
		}
	i++;
	}
	return (true);
}

bool is_rectangle(char **a)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(a[i++]);
	while (a[i])
	{
		if (len != ft_strlen(a[i++]))
			return (false);
	}
	return (true);
}

bool walls(char **a)
{
	int	i;
	int	len_array;
	int str_len;

	str_len = ft_strlen(a[0]);
	i = 0;
	len_array = array_len(a) - 1;
	while(a[0][i])
	{
		if (a[0][i] !=  '1' || a[len_array][i] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (a[i])
	{
		if (a[i][0] != '1' || a[i][str_len - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool check_map(char **a)
{
	if (!(is_rectangle(a)))
	{
		write(2, "Error\nRetangle map please\n", 27);
		return (false);
	}
	if (!(walls(a)))
	{
		write(2, "Error\nThe game needs walls man!\n", 33);
		return (false);
	}
	if (!(unwanted_char(a)))
	{
		write(2, "Error\nThere is a char I don't want\n", 36);
		return (false);
	}
	if (!(all_there(a)))
	{
		write(2, "Error\nSomething is missing\n", 28);
		return (false);
	}
	if (!(winnable(a)))
		return (false);
	return (true);
}

bool check_newline(char *a)
{
	int i;

	i = 1;
	while (a[i])
	{
		if(a[i] == '\n' && a[i -1] == '\n')
		{
			write(2, "Error\nEmpty newlines don't earn achievements bro!", 50);
			return (false);
		}
		i++;
	}
	return (true);
}

char **get_map(int fd)
{
	char	*s1;
	char	*s2;
	char	*s3;
	char	**array;
	bool	check;

	s1 = get_next_line(fd);
	while ((s2 = get_next_line(fd)) != NULL)
	{
		s3 = ft_strjoin(s1, s2);
		free(s1);
		free(s2);
		s1 = ft_strdup(s3);
		free(s3);
	}
	close(fd);
	check = check_newline(s1);
	if (!check)
		return (NULL);
	array = ft_split(s1, '\n');
	free(s1);
	if (!(check_map(array)))
		return (NULL);
	return(array);
}
int open_file(char *v)
{
	int 	fd;

	fd = 0;
	fd = open(v, O_RDONLY);
	if(fd == -1)
	{
		close(fd);
		return(write(2, "ERROR\nSomething wrong with the file...", 38));
	}
	return (fd);
}

int main (int c, char **v)
{
	int 	fd;
	char	**map;

	fd = 0;
	if (c == 2)
	{
		fd = open_file(v[1]);
		map = get_map(fd);
		if (map == NULL)
			return(write(2, "Error\n", 6));
		open_game(map);
		free_array(map);
	}
}