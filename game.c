/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:40:22 by linhnguy          #+#    #+#             */
/*   Updated: 2024/03/02 16:47:15 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void ft_hook(void* param)
// {
// 	const mlx_t* mlx = param;

// 	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

	static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void put_image(mlx_t *mlx, t_images data, char **map)
{
	int i;
	int	j;
	
	i = 0;
	mlx_image_to_window(mlx, data.grass, 0, 0);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_image_to_window(mlx, data.tree, j * WIDTH, i * HEIGHT);
			else if (map[i][j] == 'P')
				mlx_image_to_window(mlx, data.slime, j * WIDTH, i * HEIGHT);
			else if (map[i][j] == 'C')
				mlx_image_to_window(mlx, data.potion, j * WIDTH, i * HEIGHT);
			else if (map[i][j] == 'E')
				mlx_image_to_window(mlx, data.exit, j * WIDTH, i * HEIGHT);
			j++;
		}
		i++;
	}
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	if (!param)
		printf("false/n");
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		printf("Move up\n");
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		printf("Move left\n");
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT)
		printf("Move right\n");
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)
		printf("Move down\n");
}

// mlx_keyfunc assign_keys(mlx_key_data_t keydata, void *param)
// {
// 	t_data	*data;

// 	data = (t_data *)param;
// }
void make_images(mlx_t *mlx, char **map)
{
	t_images	data;
	data.grass1 = mlx_load_png("./assets/grass.png");
	data.slime1 = mlx_load_png("./assets/blue_slime_big.png");
	data.potion1 = mlx_load_png("./assets/red_potion.png");
	data.tree1 = mlx_load_png("./assets/Tree2.png");
	data.exit1 = mlx_load_png("./assets/exit.png");
	data.grass = mlx_texture_to_image(mlx, data.grass1);
	data.slime = mlx_texture_to_image(mlx, data.slime1);
	data.potion = mlx_texture_to_image(mlx, data.potion1);
	data.exit = mlx_texture_to_image(mlx, data.exit1);
	data.tree = mlx_texture_to_image(mlx, data.tree1);
	mlx_resize_image(data.grass, WIDTH * (float)ft_strlen(map[0]), HEIGHT * (float)array_len (map));
	mlx_resize_image(data.slime, WIDTH * .7, HEIGHT * .7);
	mlx_resize_image(data.potion, WIDTH * .6, HEIGHT * .6);
	mlx_resize_image(data.tree, WIDTH * .9, HEIGHT * .9);
	mlx_resize_image(data.exit, WIDTH, HEIGHT);
	put_image(mlx, data, map);
}

bool open_game(char **map)
{	
	
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx_t* mlx = mlx_init(WIDTH * (float)ft_strlen(map[0]), HEIGHT * (float)array_len (map), "Slime Adventure", true);
	if (!mlx)
		ft_error();
	make_images(mlx, map);
	// mlx_key_hook(mlx_t* mlx, mlx_keyfunc func, void* param)
	mlx_key_hook(mlx, &my_keyhook, mlx_cursor_hook);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}