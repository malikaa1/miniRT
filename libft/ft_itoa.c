/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 16:25:25 by mrahmani          #+#    #+#             */
/*   Updated: 2020/05/25 20:14:41 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_nb(int n)
{
	int		i;

	i = 0;
	if (n < 0)
		i++;
	while (n / 10 != 0)
	{
		i++;
		n = n / 10;
	}
	return (i + 1);
}

char	*ft_itoa(int nb)
{
	char	*str;
	int		i;
	long	n;

	i = count_nb(nb);
	n = nb;
	str = malloc(sizeof(char) * (count_nb(nb) + 1));
	if (str != NULL)
	{
		if (n < 0)
		{
			str[0] = '-';
			n = n * -1;
		}
		while (n / 10 != 0 && i >= 0)
		{
			str[i - 1] = (n % 10) + '0';
			n = n / 10;
			i--;
		}
		str[i - 1] = n + '0';
		str[count_nb(nb)] = '\0';
	}
	return (str);
}
