/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:40:22 by linhnguy          #+#    #+#             */
/*   Updated: 2024/03/02 20:07:29 by linhnguy         ###   ########.fr       */
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

void put_image(mlx_t *mlx, t_images image, t_data *game_data)
{
	int i;
	int	j;
	
	i = 0;
	mlx_image_to_window(mlx, image.grass, 0, 0);
	while (game_data->map[i])
	{
		j = 0;
		while (game_data->map[i][j])
		{
			if (game_data->map[i][j] == '1')
				mlx_image_to_window(mlx, image.tree, j * INDEX_WIDTH, i * INDEX_HEIGHT);
			else if (game_data->map[i][j] == 'P')
				mlx_image_to_window(mlx, image.slime, j * INDEX_WIDTH, i * INDEX_HEIGHT);
			else if (game_data->map[i][j] == 'C')
				mlx_image_to_window(mlx, image.potion, j * INDEX_WIDTH, i * INDEX_HEIGHT);
			else if (game_data->map[i][j] == 'E')
				mlx_image_to_window(mlx, image.exit, j * INDEX_WIDTH, i * INDEX_HEIGHT);
			j++;
		}
		i++;
	}
}

void my_keyhook(mlx_key_data_t keydata, t_data *game_data)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{	
		printf("Move up\n");
		
	}	
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		printf("Move left\n");
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		printf("Move right\n");
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		printf("Move down\n");
}

void make_images(mlx_t *mlx, t_data *game_data)
{
	t_images	image;
	image.grass1 = mlx_load_png("./assets/grass.png");
	image.slime1 = mlx_load_png("./assets/blue_slime_big.png");
	image.potion1 = mlx_load_png("./assets/red_potion.png");
	image.tree1 = mlx_load_png("./assets/Tree2.png");
	image.exit1 = mlx_load_png("./assets/exit.png");
	image.grass = mlx_texture_to_image(mlx, image.grass1);
	image.slime = mlx_texture_to_image(mlx, image.slime1);
	image.potion = mlx_texture_to_image(mlx, image.potion1);
	image.exit = mlx_texture_to_image(mlx, image.exit1);
	image.tree = mlx_texture_to_image(mlx, image.tree1);
	mlx_resize_image(image.grass, game_data->map_width, game_data->map_height);
	mlx_resize_image(image.slime, INDEX_WIDTH * .7, INDEX_HEIGHT * .7);
	mlx_resize_image(image.potion, INDEX_WIDTH * .6, INDEX_HEIGHT * .6);
	mlx_resize_image(image.tree, INDEX_WIDTH * .9, INDEX_HEIGHT * .9);
	mlx_resize_image(image.exit, INDEX_WIDTH, INDEX_HEIGHT);
	put_image(mlx, image, game_data);
}

void map_size(char **map, t_data *game_data)
{
	game_data->map_width = INDEX_WIDTH * ft_strlen(map[0]);
	game_data->map_height = INDEX_HEIGHT * array_len(map);
}

void initialize_map(char **map, t_data *game_data)
{
	int 			i;
	int 			j;
	int				count;

	i = 0;
	count = 0;
	game_data->map = map;
	while (game_data->map[i])
	{
		j = 0;
		while (game_data->map[i][j])
		{
			if (game_data->map[i][j] == 'C')
				count++;
			if (game_data->map[i][j] == 'E')
			{
				game_data->exit_x = j;
				game_data->exit_y = i;
			}
			j++;
		}
		i++;
	}
	game_data->potion_count = count;
	map_size(map, game_data);
}

bool open_game(char **map)
{	
	t_data	game_data;

	initialize_map(map, &game_data);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx_t* mlx = mlx_init(game_data.map_width, game_data.map_height, "Slime Adventure", true);
	if (!mlx)
		ft_error();
	make_images(mlx, &game_data);
	// mlx_key_hook(mlx_t* mlx, mlx_keyfunc func, void* param);
	mlx_key_hook(mlx, &my_keyhook, &game_data);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}