/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 02:09:03 by mrahmani          #+#    #+#             */
/*   Updated: 2020/05/11 15:48:46 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	char *s_dest;
	char *s_src;

	s_dest = (char *)dest;
	s_src = (char *)src;
	if (!src && !dest)
		return (NULL);
	while (size--)
		*s_dest++ = *s_src++;
	return (dest);
}
