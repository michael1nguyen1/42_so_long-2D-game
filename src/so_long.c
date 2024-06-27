/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:51:15 by linhnguy          #+#    #+#             */
/*   Updated: 2024/06/27 13:01:21 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	check_map(char **a)
{
	if (!(right_size_map(a)))
		return (print_error("Error\nSmaller map gives better xperience!\n"));
	if (!(is_rectangle(a)))
		return (print_error("Error\nRetangle map please\n"));
	if (!(check_walls(a)))
		return (print_error("Error\nThe game needs walls man!\n"));
	if (!(unwanted_char(a)))
		return (print_error("Error\nThere is a char I don't want\n"));
	if (!(all_char_there(a)))
		return (print_error("Error\nSomething is missing\n"));
	if (!(winnable(a)))
		return (print_error("Error\nSomething on the map is unreachable 😱\n"));
	return (true);
}

static char	**get_map(int fd)
{
	char	*str;
	char	**array;

	str = make_string(fd);
	if (!str)
		return (print_error_ptr("Error\nInvalid map!\n"));
	close(fd);
	if (!check_duplicates(str))
	{
		free(str);
		return (NULL);
	}
	array = ft_split(str, '\n');
	free(str);
	if (!array)
	{
		ft_printf("ERROR\nSplit has failed");
		return (NULL);
	}
	if (!check_map(array))
	{
		free_array(array);
		return (NULL);
	}
	return (array);
}

static int	open_file(char *v)
{
	int	fd;

	if ((ft_strncmp(&v[ft_strlen(v) - 4], ".ber", 4)) != 0)
	{
		ft_printf("ERROR\nNeeds a .ber file to work\n");
		return (-1);
	}
	fd = open(v, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nOpening file failed\n");
		close(fd);
		return (-1);
	}
	return (fd);
}

static bool	open_game(char **map)
{
	t_data	game_data;

	initialize_map(map, &game_data);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game_data.mlx = mlx_init(game_data.map_width,
			game_data.map_height, "Slime Adventure", true);
	if (!game_data.mlx)
		return (false);
	if (!make_images(&game_data))
		return (false);
	mlx_key_hook(game_data.mlx, &my_keyhook, &game_data);
	mlx_loop_hook(game_data.mlx, &end_screen, &game_data);
	free_images(&game_data);
	mlx_loop(game_data.mlx);
	mlx_terminate(game_data.mlx);
	return (true);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	**map;

	if (argc != 2)
	{
		write(2, "ERROR\nWhat is wrong with you? 1 map only!\n", 42);
		return (EXIT_FAILURE);
	}
	fd = open_file(argv[1]);
	if (fd == -1)
		return (EXIT_FAILURE);
	map = get_map(fd);
	if (map == NULL)
		return (EXIT_FAILURE);
	if (!open_game(map))
	{
		free_array(map);
		return (EXIT_FAILURE);
	}
	free_array(map);
	return (EXIT_SUCCESS);
}
