/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:37:03 by linhnguy          #+#    #+#             */
/*   Updated: 2024/03/07 18:32:49 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	choose_image(t_data *g_data, char c, int x_coor, int y_coor)
{
	if (c == '1')
	{
		if (mlx_image_to_window(g_data->mlx, g_data->tree,
				x_coor * INDEX_WIDTH, y_coor * INDEX_HEIGHT) == -1)
			return (false);
	}
	else if (c == 'P')
	{
		if (mlx_image_to_window(g_data->mlx, g_data->slime,
				x_coor * INDEX_WIDTH, y_coor * INDEX_HEIGHT) == -1)
			return (false);
	}
	else if (c == 'C')
	{
		if (mlx_image_to_window(g_data->mlx, g_data->potion,
				x_coor * INDEX_WIDTH, INDEX_HEIGHT * y_coor) == -1)
			return (false);
	}
	else if (g_data->map[y_coor][x_coor] == 'E' && g_data->potion_count == 0)
	{
		if (mlx_image_to_window(g_data->mlx, g_data->exit,
				x_coor * INDEX_WIDTH, y_coor * INDEX_HEIGHT) == -1)
			return (false);
	}
	return (true);
}
