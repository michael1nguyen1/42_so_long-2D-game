/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:18:12 by linhnguy          #+#    #+#             */
/*   Updated: 2024/06/27 13:09:14 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*d;

	d = (const unsigned char*) s;
	i = 0;
	while (i < n)
	{
		if (d[i] == (unsigned char) c)
			return ((void*)&d[i]);
		i++;
	}
	return (NULL);
}
