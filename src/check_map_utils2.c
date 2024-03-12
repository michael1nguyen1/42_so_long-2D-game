/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:47:06 by linhnguy          #+#    #+#             */
/*   Updated: 2024/03/12 21:22:23 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_duplicates(char *a)
{
	int	i;

	i = 1;
	while (a[i])
	{
		if ((a[i] == '\n' && a[i -1] == '\n') || a[0] == '\n'
			|| a[ft_strlen (a) - 1] == '\n')
			return (print_error
				("Error\nEmpty newlines don't earn achievements bro!🤬\n"));
		i++;
	}
	if (!check_player_exit_dup(a))
		return (false);
	return (true);
}

bool	check_player_exit_dup(char *a)
{
	int	i;
	int	player;
	int	exit;

	i = 0;
	player = 0;
	exit = 0;
	while (a[i++])
	{
		if (a[i] == 'P')
			player++;
		else if (a[i] == 'E')
			exit++;
	}
	if (player > 1)
	{
		write(2, "Error\nToo many heroes\n", 22);
		return (false);
	}
	else if (exit > 1)
	{
		write(2, "Error\nToo many exits\n", 21);
		return (false);
	}
	return (true);
}

bool	check_fill(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'E' || map[i][j] == 'C')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static void	map_size(t_data *g_data, int count)
{
	int	i;
	int	j;

	i = 0;
	while (g_data->map[i] != NULL)
	{
		j = 0;
		while (g_data->map[i][j++])
		{
			if (g_data->map[i][j] == 'C')
				count++;
			else if (g_data->map[i][j] == 'E')
			{
				g_data->exit_x = j;
				g_data->exit_y = i;
			}
			else if (g_data->map[i][j] == 'P')
			{
				g_data->player_x = j;
				g_data->player_y = i;
			}
		}
		i++;
	}
	g_data->potion_count = count;
}

void	initialize_map(char **map, t_data *game_data)
{
	int		count;

	count = 0;
	game_data->movements = 1;
	game_data->is_end = false;
	game_data->map = map;
	game_data->map_width = INDEX_WIDTH * ft_strlen(map[0]);
	game_data->map_height = INDEX_HEIGHT * array_len(map);
	map_size(game_data, count);
}
