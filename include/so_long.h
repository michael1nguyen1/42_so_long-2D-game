/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:53:41 by linhnguy          #+#    #+#             */
/*   Updated: 2024/03/06 20:40:56 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# define INDEX_WIDTH 100
# define INDEX_HEIGHT 100

typedef struct s_struct
{
	bool	c;
	bool	p;
	bool	e;
}	t_check;

typedef struct s_coor
{
	int		cur_x;
	int		cur_y;
}	t_flood;

typedef struct s_data
{
	char			**map;
	int				potion_count;
	int				exit_x;
	int				exit_y;
	int				map_width;
	int				map_height;
	int				player_x;
	int				player_y;
	bool			is_end;
	double			end_time;
	mlx_texture_t	*grass1;
	mlx_texture_t	*slime1;
	mlx_texture_t	*potion1;
	mlx_texture_t	*tree1;
	mlx_texture_t	*exit1;
	mlx_texture_t	*end1;
	mlx_image_t		*end;
	mlx_image_t		*grass;
	mlx_image_t		*slime;
	mlx_image_t		*potion;
	mlx_image_t		*tree;
	mlx_image_t		*exit;
	mlx_t			*mlx;
}	t_data;

// Map creation and validation

bool		is_rectangle(char **a);
bool		check_walls(char **a);
bool		unwanted_char(char **a);
bool		all_char_there(char **a);
bool		right_size_map(char **map);
bool		winnable(char **a);
t_flood		*coordinates(char **a, char object);
void		floodfill(char **copy, t_flood *cur);
bool		check_duplicates(char *a);
bool		check_player_exit_dup(char *a);
bool		check_fill(char **map);
void		initialize_map(char **map, t_data *game_data);

// Array Utils

char		**copy_array(char **a);
void		free_array(char **array);
int			array_len(char **a);

// String Utils

int			array_len(char **a);
char		*make_string(int fd);

// Key and Loop Hooking

void		my_keyhook(mlx_key_data_t keydata, void *game_data);

// Images
void		put_image(t_data *g_data);
bool		make_images(t_data *g_data);
void		free_images(t_data *game_data);
void		end_screen(void *game_data);
void		choose_image(t_data *g_data, char c, int x_coor, int y_coor);

// Game operations
void		end_game(t_data *game_data);

// Error handling
bool		print_error(char *str);

#endif