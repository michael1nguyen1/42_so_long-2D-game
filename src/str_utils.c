/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:39:57 by linhnguy          #+#    #+#             */
/*   Updated: 2024/03/06 20:40:27 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*make_string(int fd)
{
	char	*s1;
	char	*s2;
	char	*s3;

	s1 = get_next_line(fd);
	s2 = get_next_line(fd);
	while (s2)
	{
		s3 = ft_strjoin(s1, s2);
		free(s1);
		free(s2);
		s1 = ft_strdup(s3);
		free(s3);
		s2 = get_next_line(fd);
	}
	return (s1);
}
