/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 19:26:50 by adzikovs          #+#    #+#             */
/*   Updated: 2019/03/26 19:27:39 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memmove(void *dst, void *src, size_t n)
{
	size_t	start;
	size_t	end;
	int		inc;

	start = 0;
	end = n;
	inc = 1;
	if (dst > src)
	{
		start = n;
		end = 0;
		inc = -1;
	}
	while (start != end)
	{
		if (inc < 0)
			start--;
		((char*)dst)[start] = ((char*)src)[start];
		if (inc > 0)
			start++;
	}
	return (dst);
}
