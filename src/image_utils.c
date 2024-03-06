/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:37:03 by linhnguy          #+#    #+#             */
/*   Updated: 2024/03/06 20:37:34 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	choose_image(t_data *g_data, char c, int x_coor, int y_coor)
{
	if (c == '1')
		mlx_image_to_window(g_data->mlx, g_data->tree,
			x_coor * INDEX_WIDTH, y_coor * INDEX_HEIGHT);
	else if (c == 'P')
		mlx_image_to_window(g_data->mlx, g_data->slime,
			x_coor * INDEX_WIDTH, y_coor * INDEX_HEIGHT);
	else if (c == 'C')
		mlx_image_to_window(g_data->mlx, g_data->potion,
			x_coor * INDEX_WIDTH, INDEX_HEIGHT * y_coor);
	else if (c == 'E' && g_data->potion_count == 0)
		mlx_image_to_window(g_data->mlx, g_data->exit,
			x_coor * INDEX_WIDTH, y_coor * INDEX_HEIGHT);
	else if (c == 'E')
		g_data->map[y_coor][x_coor] = '0';
}
