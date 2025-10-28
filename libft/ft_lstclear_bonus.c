/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:35:18 by armeneze          #+#    #+#             */
/*   Updated: 2025/07/30 15:48:27 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*list;

	if (!lst || !*lst)
		return ;
	list = *lst;
	while (list != NULL)
	{
		del(list->content);
		*lst = lst[0]->next;
		free(list);
		list = *lst;
	}
	lst = NULL;
}
