/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 17:49:03 by mrahmani          #+#    #+#             */
/*   Updated: 2020/05/25 20:23:39 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ptr;

	if (!s || !(ptr = (char*)malloc(ft_strlen(s) + 1)))
		return (NULL);
	i = -1;
	while (s[++i] != '\0')
		ptr[i] = f(i, s[i]);
	ptr[i] = '\0';
	return (ptr);
}
