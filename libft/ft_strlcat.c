/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 23:55:50 by mrahmani          #+#    #+#             */
/*   Updated: 2020/05/25 20:16:21 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	i = 0;
	if (size < len_dest + 1)
		return (size + len_src);
	if (size > len_dest + 1)
	{
		while (src[i] != '\0' && len_dest + 1 + i < size)
		{
			dest[len_dest + i] = src[i];
			i++;
		}
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}
