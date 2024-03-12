/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:15:01 by linhnguy          #+#    #+#             */
/*   Updated: 2024/03/12 22:15:06 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*make_string(int fd)
{
	char	*line;
	char	*next_line;
	char	*temp;

	line = NULL;
	next_line = get_next_line(fd);
	if (!next_line)
		return (NULL);
	while (next_line)
	{
		temp = ft_strjoin(line, next_line);
		free(line);
		line = temp;
		free(next_line);
		if (!line)
			return (NULL);
		next_line = get_next_line(fd);
		if (!next_line)
			break ;
	}
	return (line);
}
