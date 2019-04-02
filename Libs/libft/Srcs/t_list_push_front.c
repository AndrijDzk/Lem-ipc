/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list_push_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 10:33:49 by adzikovs          #+#    #+#             */
/*   Updated: 2018/10/19 10:58:10 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void			t_list_push_front(t_list **begin, void *data, size_t size)
{
	t_list		*tmp;

	if (begin)
	{
		tmp = new_t_list_node(data, size);
		tmp->next = *begin;
		*begin = tmp;
	}
}

t_list			*t_list_non_deep_copy(t_list *list)
{
	t_list		*res;

	res = NULL;
	while (list)
	{
		t_list_push_back(&res, list->data, list->size);
		list = list->next;
	}
	return (res);
}
