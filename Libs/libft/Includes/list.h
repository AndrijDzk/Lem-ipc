/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 14:37:54 by adzikovs          #+#    #+#             */
/*   Updated: 2018/10/19 10:58:10 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <string.h>

typedef struct		s_list
{
	void			*data;
	size_t			size;
	struct s_list	*next;
}					t_list;

t_list				*new_t_list_node(void *data, size_t size);

void				t_list_push_front(t_list **begin, void *data, size_t size);

void				t_list_push_back(t_list **begin, void *data, size_t size);

t_list				*t_list_non_deep_copy(t_list *list);

void				t_list_delete_next_node(t_list **next);

void				t_list_deep_clear(t_list **begin);

void				t_list_optional_clear(t_list **begin, size_t size);

void				t_list_non_deep_clear(t_list **begin);

void				**t_list_to_arr(t_list **begin);

#endif
