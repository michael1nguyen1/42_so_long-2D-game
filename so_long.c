/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:51:15 by linhnguy          #+#    #+#             */
/*   Updated: 2024/02/23 18:24:33 by linhnguy         ###   ########.fr       */
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
	return(i - 1);
}

// bool winnable(char **a)
// {
	
// }

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
	len_array = array_len(a);
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
	// if (!(winnable(a)))
	// {
	// 	write(2, "Error\n There is a char I don't want", 36);
	// 	return (false);
	// }
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
	s2 = get_next_line(fd);
	while (s2)
	{
		s3 = ft_strjoin(s1, s2);
		free(s1);
		free(s2);
		s1 = malloc(ft_strlen(s3) * sizeof(char) + 1);
		s1 = s3;
		s2 = get_next_line(fd);
	}
	close(fd);
	check = check_newline(s1);
	if (!check)
		return (NULL);
	array = ft_split(s1, '\n');
	if (!(check_map(array)))
		return (NULL);
	return(array);
}

int main (int c, char **v)
{
	int 	fd = 0;
	char	**map;
	if (c == 2)
	{
		fd = open(v[1], O_RDONLY);
			if(fd == -1)
			{
				close(fd);
				return(write(2, "ERROR\nSomething wrong with the file...", 38));
			}
		map = get_map(fd);
		if (map == NULL)
			return(-1);
	}
	return(0);
}
