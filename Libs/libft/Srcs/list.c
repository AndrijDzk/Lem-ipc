/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 14:40:51 by adzikovs          #+#    #+#             */
/*   Updated: 2018/10/19 10:58:10 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*new_t_list_node(void *data, size_t size)
{
	t_list	*res;

	res = (t_list*)malloc(sizeof(*res));
	res->next = NULL;
	res->data = data;
	res->size = size;
	return (res);
}

void		t_list_push_back(t_list **begin, void *data, size_t size)
{
	while (begin && *begin)
		begin = &((*begin)->next);
	if (begin)
		*begin = new_t_list_node(data, size);
}

void		t_list_delete_next_node(t_list **next)
{
	t_list	*tmp;

	if (next && *next)
	{
		tmp = *next;
		*next = (*next)->next;
		free(tmp);
	}
}

static void	save_data(t_list *tmp, void **res, size_t *i)
{
	if (tmp->data)
	{
		res[*i] = tmp->data;
		(*i)++;
	}
	free(tmp);
}

void		**t_list_to_arr(t_list **begin)
{
	t_list		*tmp;
	size_t		i;
	void		**res;

	if (begin == NULL || *begin == NULL)
		return (NULL);
	i = 0;
	tmp = *begin;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	res = (void**)malloc(sizeof(*res) * (i + 1));
	ft_bzero(res, sizeof(*res) * (i + 1));
	i = 0;
	while (*begin)
	{
		tmp = *begin;
		*begin = (*begin)->next;
		save_data(tmp, res, &i);
	}
	return (res);
}
