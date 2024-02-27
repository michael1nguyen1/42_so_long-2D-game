/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:53:41 by linhnguy          #+#    #+#             */
/*   Updated: 2024/02/27 15:45:40 by linhnguy         ###   ########.fr       */
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
#define WIDTH 500
#define HEIGHT 500

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
} t_coor;

bool		open_game(char **map);
int			array_len(char **a);
#endif
