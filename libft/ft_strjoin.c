/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:31:00 by linhnguy          #+#    #+#             */
/*   Updated: 2024/06/27 13:12:15 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		k;
	
	k = 0;
	i = 0;
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	if (s1)
	{	
		while (s1[i])
		{
			s3[k++] = s1[i++];
		}
	}
	i = 0;
	if (s2)
	{
		while (s2[i])
		{
			s3[k++] = s2[i++];
		}
		s3[k] = '\0';
	}
	return (s3);
}
