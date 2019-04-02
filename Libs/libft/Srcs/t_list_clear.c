/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 10:58:36 by adzikovs          #+#    #+#             */
/*   Updated: 2018/10/19 10:58:36 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

void		t_list_deep_clear(t_list **begin)
{
	t_list		*tmp;

	if (begin)
	{
		while (*begin)
		{
			tmp = (*begin)->next;
			if ((*begin)->data)
				free((*begin)->data);
			(*begin)->data = NULL;
			(*begin)->size = 0;
			free(*begin);
			(*begin) = tmp;
		}
	}
}

void		t_list_non_deep_clear(t_list **begin)
{
	t_list		*tmp;

	while (begin && *begin)
	{
		tmp = (*begin)->next;
		(*begin)->data = NULL;
		(*begin)->size = 0;
		free(*begin);
		(*begin) = tmp;
	}
}

void		t_list_optional_clear(t_list **begin, size_t size)
{
	t_list		*tmp;

	while (begin && *begin)
	{
		tmp = (*begin)->next;
		if ((*begin)->size == size)
			free((*begin)->data);
		(*begin)->data = NULL;
		(*begin)->size = 0;
		free(*begin);
		(*begin) = tmp;
	}
}
