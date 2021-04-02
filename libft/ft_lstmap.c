/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:58:30 by mrahmani          #+#    #+#             */
/*   Updated: 2020/05/29 17:55:17 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*elmnt;

	if (lst == NULL || !(new = ft_lstnew((*f)(lst->content))))
		return (NULL);
	lst = lst->next;
	elmnt = new;
	while (lst)
	{
		ft_lstadd_back(&new, ft_lstnew((*f)(lst->content)));
		if (!(elmnt = elmnt->next))
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (new);
}
