/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:51:15 by linhnguy          #+#    #+#             */
/*   Updated: 2024/02/21 18:07:22 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int array_len(char **a)
{
	int	i;
	int	counter;
	
	i = 0;
	counter = 0;

	while (a[i])
	{
		counter++;
		i++;
	}
	printf("%i", counter);
	return(counter);
}

bool is_rectangle(char **a)
{
	size_t	len;
	int		i;

	i = 0;
	len = 0;
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
	int	j;
	int	len_array;

	j = 0;
	len_array = array_len(a);
	
	while(a[0][j])
	{
		if(a[0][j] !=  '1' || a[4][j] != '1')
			return (false);
		j++;
	}
	return (true);
}
bool check_map(char **a)
{
	if (!(is_rectangle(a)))
		return (false);
	if (!(walls(a)))
		return (false);
	// if (!(winnable(a)))
	// 	return (false);
	// if (!(all_there(a)))
	// 	return (false);
	return (true);
}

char **get_map(int fd)
{
	char	*s1;
	char	*s2;
	char	*s3;
	char	**array;

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
				return(write(2, "ERROR1\n", 6));
			}
		map = get_map(fd);
		if (map == NULL)
			return(write(2, "ERROR2\n", 6));
	}
	return(0);
}
