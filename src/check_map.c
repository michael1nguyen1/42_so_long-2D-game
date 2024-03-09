/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:26:22 by linhnguy          #+#    #+#             */
/*   Updated: 2024/03/07 17:55:08 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_rectangle(char **a)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(a[i++]);
	while (a[i])
	{
		if (len != ft_strlen(a[i++]))
			return (false);
	}
	return (true);
}

bool	check_walls(char **a)
{
	int	i;
	int	len_array;
	int	str_len;

	str_len = ft_strlen(a[0]);
	i = 0;
	len_array = array_len(a) - 1;
	while (a[0][i])
	{
		if (a[0][i] != '1' || a[len_array][i] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (a[i])
	{
		if (a[i][0] != '1' || a[i][str_len - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	unwanted_char(char **a)
{
	int	i;
	int	j;

	i = 0;
	while (a[i])
	{
		j = 0;
		while (a[i][j])
		{
			if (a[i][j] != 'P' && a[i][j] != 'C' && a[i][j] != 'E'
				&& a[i][j] != '0' && a[i][j] != '1')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	all_char_there(char **a)
{
	int		i;
	int		j;
	t_check	check;

	check.p = false;
	check.c = false;
	check.e = false;
	i = 0;
	while (a[i])
	{
		j = 0;
		while (a[i][j])
		{
			if (a[i][j] == 'P')
				check.p = true;
			else if (a[i][j] == 'C')
				check.c = true;
			else if (a[i][j] == 'E')
				check.e = true;
			j++;
		}
		i++;
	}
	return (check.p && check.c && check.e);
}

bool	winnable(char **a)
{
	t_flood		*player;
	char		object;
	char		**copy;

	object = 'P';
	player = coordinates(a, object);
	copy = copy_array(a);
	if (!copy)
		return (false);
	floodfill(copy, player);
	if (!check_fill(copy))
	{
		free_array(copy);
		free(player);
		return (false);
	}
	free_array(copy);
	free(player);
	return (true);
}
