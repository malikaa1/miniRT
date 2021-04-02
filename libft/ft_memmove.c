/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 18:33:05 by mrahmani          #+#    #+#             */
/*   Updated: 2020/05/11 16:14:12 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s_dst;
	char	*s_src;
	size_t	i;

	i = 0;
	s_dst = (char *)dst;
	s_src = (char *)src;
	if (s_src > s_dst)
	{
		while (i < len)
		{
			s_dst[i] = s_src[i];
			i++;
		}
	}
	else if (s_dst > s_src)
	{
		while (len--)
			s_dst[len] = s_src[len];
	}
	return (dst);
}
