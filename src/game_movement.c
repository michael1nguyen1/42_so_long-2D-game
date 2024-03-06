/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:01:39 by linhnguy          #+#    #+#             */
/*   Updated: 2024/03/05 13:06:57 by linhnguy         ###   ########.fr       */
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
		put_image (g_data);
	}
	else if (g_data->map[g_data->player_y - 1][g_data->player_x] == 'C')
	{
		g_data->map[g_data->player_y][g_data->player_x] = '0';
		g_data->map[g_data->player_y - 1][g_data->player_x] = 'P';
		g_data->player_y = g_data->player_y - 1;
		g_data->potion_count--;
		if (g_data->potion_count == 0)
			g_data->map[g_data->exit_y][g_data->exit_x] = 'E';
		put_image (g_data);
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
		put_image (g_data);
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
		put_image (g_data);
	}
	else if (g_data->map[g_data->player_y][g_data->player_x - 1]
		== 'E')
	{
		g_data->map[g_data->player_y][g_data->player_x] = '0';
		g_data->map[g_data->player_y][g_data->player_x - 1] = 'P';
		end_game(g_data);
	}
}

static void	move_right(t_data *game_data)
{
	if (game_data->map[game_data->player_y][game_data->player_x + 1] == '0')
	{
		game_data->map[game_data->player_y][game_data->player_x] = '0';
		game_data->map[game_data->player_y][game_data->player_x + 1] = 'P';
		game_data->player_x = game_data->player_x + 1;
		put_image (game_data);
	}
	else if (game_data->map[game_data->player_y][game_data->player_x + 1]
		== 'C')
	{
		game_data->map[game_data->player_y][game_data->player_x] = '0';
		game_data->map[game_data->player_y][game_data->player_x + 1] = 'P';
		game_data->player_x = game_data->player_x + 1;
		game_data->potion_count--;
		if (game_data->potion_count == 0)
			game_data->map[game_data->exit_y][game_data->exit_x] = 'E';
		put_image (game_data);
	}
	else if (game_data->map[game_data->player_y][game_data->player_x + 1]
		== 'E')
	{
		game_data->map[game_data->player_y][game_data->player_x] = '0';
		game_data->map[game_data->player_y][game_data->player_x + 1] = 'P';
		end_game(game_data);
	}
}

static void	move_down(t_data *game_data)
{
	if (game_data->map[game_data->player_y + 1][game_data->player_x] == '0')
	{
		game_data->map[game_data->player_y][game_data->player_x] = '0';
		game_data->map[game_data->player_y + 1][game_data->player_x] = 'P';
		game_data->player_y = game_data->player_y + 1;
		put_image (game_data);
	}
	else if (game_data->map[game_data->player_y + 1][game_data->player_x]
		== 'C')
	{
		game_data->map[game_data->player_y][game_data->player_x] = '0';
		game_data->map[game_data->player_y + 1][game_data->player_x] = 'P';
		game_data->player_y = game_data->player_y + 1;
		game_data->potion_count--;
		if (game_data->potion_count == 0)
			game_data->map[game_data->exit_y][game_data->exit_x] = 'E';
		put_image (game_data);
	}
	else if (game_data->map[game_data->player_y + 1][game_data->player_x]
		== 'E')
	{
		game_data->map[game_data->player_y][game_data->player_x] = '0';
		game_data->map[game_data->player_y + 1][game_data->player_x] = 'P';
		end_game(game_data);
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *game_data)
{
	t_data	*data;

	data = (t_data *)game_data;
	if (data->is_end == true)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_up(data);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_left(data);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_right(data);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_down(data);
}
