/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:01:39 by linhnguy          #+#    #+#             */
/*   Updated: 2024/03/12 21:56:56 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_data *g_data)
{
	if (g_data->map[g_data->player_y - 1][g_data->player_x] == '0')
	{
		g_data->map[g_data->player_y][g_data->player_x] = '0';
		g_data->map[g_data->player_y - 1][g_data->player_x] = 'P';
		g_data->player_y = g_data->player_y - 1;
		put_image (g_data, 1);
	}
	else if (g_data->map[g_data->player_y - 1][g_data->player_x] == 'C')
	{
		g_data->map[g_data->player_y][g_data->player_x] = '0';
		g_data->map[g_data->player_y - 1][g_data->player_x] = 'P';
		g_data->player_y = g_data->player_y - 1;
		g_data->potion_count--;
		if (g_data->potion_count == 0)
			g_data->map[g_data->exit_y][g_data->exit_x] = 'E';
		put_image (g_data, 1);
	}
	else if (g_data->map[g_data->player_y - 1][g_data->player_x] == 'E')
	{
		g_data->map[g_data->player_y][g_data->player_x] = '0';
		g_data->map[g_data->player_y - 1][g_data->player_x] = 'P';
		end_game(g_data);
	}
}

static void	move_left(t_data *g_data)
{
	if (g_data->map[g_data->player_y][g_data->player_x - 1] == '0')
	{
		g_data->map[g_data->player_y][g_data->player_x] = '0';
		g_data->map[g_data->player_y][g_data->player_x - 1] = 'P';
		g_data->player_x = g_data->player_x - 1;
		put_image (g_data, 1);
	}
	else if (g_data->map[g_data->player_y][g_data->player_x - 1]
		== 'C')
	{
		g_data->map[g_data->player_y][g_data->player_x] = '0';
		g_data->map[g_data->player_y][g_data->player_x - 1] = 'P';
		g_data->player_x = g_data->player_x - 1;
		g_data->potion_count--;
		if (g_data->potion_count == 0)
			g_data->map[g_data->exit_y][g_data->exit_x] = 'E';
		put_image (g_data, 1);
	}
	else if (g_data->map[g_data->player_y][g_data->player_x - 1]
		== 'E')
	{
		g_data->map[g_data->player_y][g_data->player_x] = '0';
		g_data->map[g_data->player_y][g_data->player_x - 1] = 'P';
		end_game(g_data);
	}
}

static void	move_right(t_data *g_data)
{
	if (g_data->map[g_data->player_y][g_data->player_x + 1] == '0')
	{
		g_data->map[g_data->player_y][g_data->player_x] = '0';
		g_data->map[g_data->player_y][g_data->player_x + 1] = 'P';
		g_data->player_x = g_data->player_x + 1;
		put_image (g_data, 1);
	}
	else if (g_data->map[g_data->player_y][g_data->player_x + 1]
		== 'C')
	{
		g_data->map[g_data->player_y][g_data->player_x] = '0';
		g_data->map[g_data->player_y][g_data->player_x + 1] = 'P';
		g_data->player_x = g_data->player_x + 1;
		g_data->potion_count--;
		if (g_data->potion_count == 0)
			g_data->map[g_data->exit_y][g_data->exit_x] = 'E';
		put_image (g_data, 1);
	}
	else if (g_data->map[g_data->player_y][g_data->player_x + 1]
		== 'E')
	{
		g_data->map[g_data->player_y][g_data->player_x] = '0';
		g_data->map[g_data->player_y][g_data->player_x + 1] = 'P';
		end_game(g_data);
	}
}

static void	move_down(t_data *g_data)
{
	if (g_data->map[g_data->player_y + 1][g_data->player_x] == '0')
	{
		g_data->map[g_data->player_y][g_data->player_x] = '0';
		g_data->map[g_data->player_y + 1][g_data->player_x] = 'P';
		g_data->player_y = g_data->player_y + 1;
		put_image (g_data, 1);
	}
	else if (g_data->map[g_data->player_y + 1][g_data->player_x]
		== 'C')
	{
		g_data->map[g_data->player_y][g_data->player_x] = '0';
		g_data->map[g_data->player_y + 1][g_data->player_x] = 'P';
		g_data->player_y = g_data->player_y + 1;
		g_data->potion_count--;
		if (g_data->potion_count == 0)
			g_data->map[g_data->exit_y][g_data->exit_x] = 'E';
		put_image (g_data, 1);
	}
	else if (g_data->map[g_data->player_y + 1][g_data->player_x]
		== 'E')
	{
		g_data->map[g_data->player_y][g_data->player_x] = '0';
		g_data->map[g_data->player_y + 1][g_data->player_x] = 'P';
		end_game(g_data);
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *game_data)
{
	t_data			*data;

	data = (t_data *)game_data;
	if (data->is_end == true)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(data->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		move_up(data);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		move_left(data);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		move_right(data);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		move_down(data);
}
