/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:40:07 by linhnguy          #+#    #+#             */
/*   Updated: 2024/03/05 13:00:14 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_flood	*coordinates(char **a, char object)
{
	int		i;
	int		j;
	t_flood	*coor;

	i = 0;
	coor = malloc(sizeof(t_flood));
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

char	**copy_array(char **a)
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
			return (NULL);
		i++;
	}
	b[i] = NULL;
	return (b);
}

void	floodfill(char **copy, t_flood *cur)
{
	if (copy[cur->cur_y][cur->cur_x] == 'F'
		|| copy[cur->cur_y][cur->cur_x] == '1')
		return ;
	copy[cur->cur_y][cur->cur_x] = 'F';
	floodfill(copy, &(t_flood){cur->cur_x - 1, cur->cur_y});
	floodfill(copy, &(t_flood){cur->cur_x + 1, cur->cur_y});
	floodfill(copy, &(t_flood){cur->cur_x, cur->cur_y - 1});
	floodfill(copy, &(t_flood){cur->cur_x, cur->cur_y + 1});
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

int	array_len(char **a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		i++;
	}
	return (i);
}
