/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:50:24 by mrahmani          #+#    #+#             */
/*   Updated: 2020/05/29 15:54:58 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elmnt;
	t_list	*temp;

	if (lst && *lst)
	{
		elmnt = *lst;
		*lst = NULL;
		while (elmnt)
		{
			temp = elmnt->next;
			del(elmnt->content);
			free(elmnt);
			elmnt = temp;
		}
	}
}
