/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:53:41 by linhnguy          #+#    #+#             */
/*   Updated: 2024/03/02 19:57:03 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"
#define INDEX_WIDTH 60
#define INDEX_HEIGHT 60

typedef struct s_struct
{
	bool	C;
	bool	P;
	bool	E;
} t_check;

typedef struct s_coor
{
	int		cur_x;
	int		cur_y;
} t_flood;

typedef struct s_data
{
    char    **map;
    int     potion_count;
    int     exit_x;
    int     exit_y;
    int     map_width;
    int     map_height;
} t_data;

typedef struct s_images
{
    mlx_texture_t   *grass1;
    mlx_texture_t   *slime1;
    mlx_texture_t   *potion1;
    mlx_texture_t   *tree1;
    mlx_texture_t   *exit1;
    mlx_image_t     *grass;
    mlx_image_t     *slime;
    mlx_image_t     *potion;
    mlx_image_t     *tree;
    mlx_image_t     *exit;
} t_images;

bool		open_game(char **map);
int			array_len(char **a);
#endif