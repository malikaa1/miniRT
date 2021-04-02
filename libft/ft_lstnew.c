/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 13:59:42 by mrahmani          #+#    #+#             */
/*   Updated: 2020/05/29 14:40:43 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newelmnt;

	if (!(newelmnt = malloc(sizeof(t_list))))
		return (NULL);
	newelmnt->content = content;
	newelmnt->next = NULL;
	return (newelmnt);
}
