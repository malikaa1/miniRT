/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 14:53:49 by mrahmani          #+#    #+#             */
/*   Updated: 2020/05/28 01:28:15 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nb_strs(char const *str, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int		ft_str_len(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static void		*free_all(char **str, int strs)
{
	int i;

	i = 0;
	while (i < strs)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static char		**ft_split_core(char **ptr, char const *s, char c, int nb_strs)
{
	int		i;
	int		j;
	int		str_len;

	i = 0;
	while (i < nb_strs)
	{
		while (*s == c)
			s++;
		str_len = ft_str_len(s, c);
		if (!(ptr[i] = (char *)malloc(sizeof(char) * (str_len + 1))))
			return (free_all(ptr, i));
		j = 0;
		while (j < str_len)
			ptr[i][j++] = *s++;
		ptr[i][j] = '\0';
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

char			**ft_split(char const *s, char c)
{
	char	**ptr;
	int		nbr_strs;

	if (!s)
		return (NULL);
	nbr_strs = nb_strs(s, c);
	if (!(ptr = (char **)malloc(sizeof(char *) * (nbr_strs + 1))))
		return (NULL);
	ptr = ft_split_core(ptr, s, c, nbr_strs);
	return (ptr);
}
