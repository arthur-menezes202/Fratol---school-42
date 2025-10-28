/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:34:01 by armeneze          #+#    #+#             */
/*   Updated: 2025/07/31 10:19:35 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_lstclear_for_map_failure(t_list **lst, void (*del)(void*));

static void	ft_lstclear_for_map_failure(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next_node;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		next_node = current->next;
		del(current->content);
		free(current);
		current = next_node;
	}
	*lst = NULL;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list_head;
	t_list	*new_node;
	void	*transformed_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list_head = NULL;
	while (lst)
	{
		transformed_content = f(lst->content);
		new_node = ft_lstnew(transformed_content);
		if (!new_node)
		{
			del(transformed_content);
			ft_lstclear_for_map_failure(&new_list_head, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list_head, new_node);
		lst = lst->next;
	}
	return (new_list_head);
}
