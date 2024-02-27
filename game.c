/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:40:22 by linhnguy          #+#    #+#             */
/*   Updated: 2024/02/27 15:47:16 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Print the window width and height.
static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

	static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
bool open_game(char **map)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Slime Adventure", true);
	if (!mlx)
		ft_error();

	mlx_texture_t *grass1 = mlx_load_png("./assets/grass.png");
	mlx_texture_t *slime1 = mlx_load_png("./assets/blue_slime_big.png");
	mlx_texture_t *potion1 = mlx_load_png("./assets/red_potion.png");
	mlx_image_t *grass = mlx_texture_to_image(mlx, grass1);
	mlx_image_t *slime = mlx_texture_to_image(mlx, slime1);
	mlx_image_t *potion = mlx_texture_to_image(mlx, potion1);
	mlx_resize_image(grass, WIDTH / ft_strlen(map[0]), HEIGHT / array_len(map));
	int i = 0;
	while (i <= mlx->width)
	{
	mlx_image_to_window(mlx, grass, i, 0);
	mlx_image_to_window(mlx, grass, 0, 0);
	i += 25;
	}
	mlx_image_to_window(mlx, slime, 0, 0);
	mlx_image_to_window(mlx, potion, 0, 0);
	mlx_put_pixel(grass, 0, 0, 0xFF0000FF);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}