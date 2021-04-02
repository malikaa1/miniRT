/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 17:12:25 by mrahmani          #+#    #+#             */
/*   Updated: 2020/05/10 01:18:02 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned int		result;
	int					sign;

	sign = 1;
	result = 0;
	while (*str == '\f' || *str == '\t' || *str == '\v'
			|| *str == '\r' || *str == '\n' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = 10 * result + (*str - 48);
		str++;
		if (result > INT_MAX)
			break ;
	}
	if ((result == (unsigned int)INT_MAX + 1 && sign == -1)
			|| result <= INT_MAX)
		return (sign * result);
	return (sign == 1 ? -1 : 0);
}
