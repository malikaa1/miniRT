/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:10:43 by mrahmani          #+#    #+#             */
/*   Updated: 2020/05/11 15:13:37 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int ch, size_t size)
{
	char *s_dest;

	s_dest = (char*)dest;
	while (size--)
	{
		if ((*s_dest++ = *(char*)(src++)) == (char)ch)
			return (s_dest);
	}
	return (0);
}
