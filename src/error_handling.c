/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:32:00 by linhnguy          #+#    #+#             */
/*   Updated: 2024/03/12 22:13:47 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	print_error(char *str)
{
	ft_printf("%s", str);
	return (false);
}

void	*print_error_ptr(char *str)
{
	ft_printf("%s", str);
	return (NULL);
}

bool	right_size_map(char **map)
{
	int	width;
	int	height;

	width = ft_strlen(map[0]);
	height = array_len(map);
	if (width > 150 || height > 150)
		return (false);
	return (true);
}
