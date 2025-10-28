/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:24:03 by armeneze          #+#    #+#             */
/*   Updated: 2025/07/30 18:18:50 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!list)
		return ((void *) 0);
	list->content = content;
	list->next = NULL;
	return (list);
}
