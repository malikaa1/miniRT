/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 02:19:38 by mrahmani          #+#    #+#             */
/*   Updated: 2020/05/05 02:31:12 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int ch, size_t n)
{
	unsigned char *ptr;

	ptr = (unsigned char *)str;
	while (n--)
	{
		if (*ptr == (unsigned char)ch)
			return (ptr);
		ptr++;
	}
	return (0);
}
