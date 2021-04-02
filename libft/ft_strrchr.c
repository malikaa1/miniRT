/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 01:19:51 by mrahmani          #+#    #+#             */
/*   Updated: 2020/05/18 00:32:43 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	while (i >= 0)
	{
		if (s[i - 1] == c)
			return ((char *)s + (i - 1));
		i--;
	}
	return (NULL);
}
