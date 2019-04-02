/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 10:34:10 by adzikovs          #+#    #+#             */
/*   Updated: 2018/10/18 10:34:10 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memdup(const void *src, size_t size)
{
	void	*res;

	if (src == NULL)
		return (NULL);
	res = malloc(size);
	ft_memcpy(res, src, size);
	return (res);
}
