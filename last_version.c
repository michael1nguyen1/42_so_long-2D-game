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

void map_size(t_data *game_data, int count)
{
	int 			i;
	int 			j;

	i = 0;
	while (game_data->map[i])
	{
		j = 0;
		while (game_data->map[i][j])
		{
			if (game_data->map[i][j] == 'C')
				count++;
			else if (game_data->map[i][j] == 'E')
			{
				game_data->exit_x = j;
				game_data->exit_y = i;
			}
			else if (game_data->map[i][j] == 'P')
			{
				game_data->player_x = j;
				game_data->player_y = i;
			}
			j++;
		}
		i++;
	}
	game_data->potion_count = count;
}

void initialize_map(char **map, t_data *game_data)
{
	int		count;

	count = 0;
	game_data->map = map;
	game_data->map_width = INDEX_WIDTH * ft_strlen(map[0]);
	game_data->map_height = INDEX_HEIGHT * array_len(map);
	map_size(game_data, count);
}

void put_image(t_data *game_data)
{
	int i;
	int	j;
	
	i = 0;
	mlx_image_to_window(game_data->mlx, game_data->grass, 0, 0);
	while (game_data->map[i])
	{
		j = 0;
		while (game_data->map[i][j])
		{
			if (game_data->map[i][j] == '1')
				mlx_image_to_window(game_data->mlx, game_data->tree, j * INDEX_WIDTH, i * INDEX_HEIGHT);
			else if (game_data->map[i][j] == 'P')
				mlx_image_to_window(game_data->mlx, game_data->slime, j * INDEX_WIDTH, i * INDEX_HEIGHT);
			else if (game_data->map[i][j] == 'C')
				mlx_image_to_window(game_data->mlx, game_data->potion, j * INDEX_WIDTH, i * INDEX_HEIGHT);
			else if (game_data->map[i][j] == game_data->map[game_data->exit_x][game_data->exit_y] && game_data->potion_count == 0)
				mlx_image_to_window(game_data->mlx, game_data->exit, game_data->exit_x * INDEX_WIDTH, game_data->exit_y * INDEX_HEIGHT);
			j++;
		}
		i++;
	}
}

void my_keyhook(mlx_key_data_t keydata, void *game_data)
{
	t_data * data = (t_data *)game_data;
	int i =0;
	while(data->map[i])
	{
		printf("%s\n",data->map[i]);
		i++;
	}
	printf("starting potion left :%i\n",data->potion_count);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{	
		
		if (data->map[data->player_y - 1][data->player_x] == '0' || data->map[data->player_y - 1][data->player_x] == 'E')
			{
				data->map[data->player_y][data->player_x] = '0';
				data->map[data->player_y - 1][data->player_x] = 'P';
				data->player_y = data->player_y - 1;
				put_image (game_data);
			}
		else if(data->map[data->player_y - 1][data->player_x] == 'C')
			{
				data->map[data->player_y][data->player_x] = '0';
				data->map[data->player_y - 1][data->player_x] = 'P';
				data->player_y = data->player_y - 1;
				printf("potion left :%i\n",data->potion_count);
				data->potion_count--;
				put_image (game_data);
			}
	}	
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		if (data->map[data->player_y][data->player_x - 1] == '0' || data->map[data->player_y - 1][data->player_x] == 'E')
			{
				data->map[data->player_y][data->player_x] = '0';
				data->map[data->player_y][data->player_x - 1] = 'P';
				data->player_x = data->player_x - 1;
				put_image (game_data);
			}
		else if(data->map[data->player_y][data->player_x - 1] == 'C')
			{
				data->map[data->player_y][data->player_x] = '0';
				data->map[data->player_y][data->player_x - 1] = 'P';
				data->player_x = data->player_x - 1;
				printf("potion left :%i\n",data->potion_count);
				data->potion_count--;
				put_image (game_data);
			}
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		if (data->map[data->player_y][data->player_x + 1] == '0' || data->map[data->player_y - 1][data->player_x] == 'E')
			{
				data->map[data->player_y][data->player_x] = '0';
				data->map[data->player_y][data->player_x + 1] = 'P';
				data->player_x = data->player_x + 1;
				put_image (game_data);
			}
		else if(data->map[data->player_y][data->player_x + 1] == 'C')
			{
				data->map[data->player_y][data->player_x] = '0';
				data->map[data->player_y][data->player_x + 1] = 'P';
				data->player_x = data->player_x + 1;
				printf("potion left :%i\n",data->potion_count);
				data->potion_count--;
				put_image (game_data);
			}
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		if (data->map[data->player_y + 1][data->player_x] == '0' || data->map[data->player_y - 1][data->player_x] == 'E')
			{
				data->map[data->player_y][data->player_x] = '0';
				data->map[data->player_y + 1][data->player_x] = 'P';
				data->player_y = data->player_y + 1;
				put_image (game_data);
			}
		else if(data->map[data->player_y + 1][data->player_x] == 'C')
			{
				data->map[data->player_y][data->player_x] = '0';
				data->map[data->player_y + 1][data->player_x] = 'P';
				data->player_y = data->player_y + 1;
				printf("potion left :%i\n",data->potion_count);
				data->potion_count--;
				put_image (game_data);
			}
	}
}

void make_images(t_data *game_data)
{
	game_data->grass1 = mlx_load_png("./assets/grass.png");
	game_data->slime1 = mlx_load_png("./assets/blue_slime_big.png");
	game_data->potion1 = mlx_load_png("./assets/red_potion.png");
	game_data->tree1 = mlx_load_png("./assets/Tree2.png");
	game_data->exit1 = mlx_load_png("./assets/exit.png");
	game_data->grass = mlx_texture_to_image(game_data->mlx, game_data->grass1);
	game_data->slime = mlx_texture_to_image(game_data->mlx, game_data->slime1);
	game_data->potion = mlx_texture_to_image(game_data->mlx, game_data->potion1);
	game_data->exit = mlx_texture_to_image(game_data->mlx, game_data->exit1);
	game_data->tree = mlx_texture_to_image(game_data->mlx, game_data->tree1);
	mlx_resize_image(game_data->grass, game_data->map_width, game_data->map_height);
	mlx_resize_image(game_data->slime, INDEX_WIDTH * .7, INDEX_HEIGHT * .7);
	mlx_resize_image(game_data->potion, INDEX_WIDTH * .6, INDEX_HEIGHT * .6);
	mlx_resize_image(game_data->tree, INDEX_WIDTH * .9, INDEX_HEIGHT * .9);
	mlx_resize_image(game_data->exit, INDEX_WIDTH, INDEX_HEIGHT);
	put_image(game_data);
}

bool open_game(char **map)
{	
	t_data	game_data;

	initialize_map(map, &game_data);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game_data.mlx = mlx_init(game_data.map_width, game_data.map_height, "Slime Adventure", true);
	if (!game_data.mlx)
		ft_error();
	make_images(&game_data);
	mlx_key_hook(game_data.mlx, &my_keyhook, &game_data);
	mlx_loop(game_data.mlx);
	mlx_terminate(game_data.mlx);
	return (EXIT_SUCCESS);
}