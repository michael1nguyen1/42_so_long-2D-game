/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:17:39 by linhnguy          #+#    #+#             */
/*   Updated: 2024/03/06 17:21:47 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_screen(void *game_data)
{
	t_data	*data;
	double	lapse_time;

	data = (t_data *)game_data;
	lapse_time = mlx_get_time();
	if (lapse_time >= data->end_time + 2 && (data->is_end))
		mlx_close_window(data->mlx);
}

void	free_images(t_data *game_data)
{
	if (game_data->grass1)
		mlx_delete_texture(game_data->grass1);
	if (game_data->slime1)
		mlx_delete_texture(game_data->slime1);
	if (game_data->potion1)
		mlx_delete_texture(game_data->potion1);
	if (game_data->tree1)
		mlx_delete_texture(game_data->tree1);
	if (game_data->exit1)
		mlx_delete_texture(game_data->exit1);
	if (game_data->end1)
		mlx_delete_texture(game_data->end1);
}

void	end_game(t_data *game_data)
{
	game_data->is_end = true;
	game_data->end_time = mlx_get_time();
	mlx_image_to_window(game_data->mlx, game_data->end, 0, 0);
}
