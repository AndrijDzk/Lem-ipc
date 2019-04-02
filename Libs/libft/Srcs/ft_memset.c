/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:44:59 by adzikovs          #+#    #+#             */
/*   Updated: 2018/10/18 10:56:01 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *dst, int c, size_t len)
{
	unsigned char	c0;
	unsigned char	*buff;
	size_t			i;

	if (dst == NULL)
		return (NULL);
	buff = dst;
	c0 = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		buff[i] = c0;
		i++;
	}
	return (dst);
}

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char			*buff;
	const unsigned char		*buff2;
	size_t					i;

	if (dst == NULL || src == NULL)
		return (NULL);
	buff = dst;
	buff2 = src;
	i = 0;
	while (i < len)
	{
		buff[i] = buff2[i];
		i++;
	}
	return (dst);
}
