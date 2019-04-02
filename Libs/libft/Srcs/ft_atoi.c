/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 10:14:04 by adzikovs          #+#    #+#             */
/*   Updated: 2018/11/08 12:11:41 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	int x;
	int	i;
	int	s;

	x = 0;
	if (str)
	{
		i = 0;
		s = 1;
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' ||
				str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
			i++;
		if (str[i] == '-')
		{
			s = -1;
			i++;
		}
		else if (str[i] == '+')
			i++;
		while (str[i] >= '0' && str[i] <= '9')
			x = x * 10 + s * (str[i++] - '0');
	}
	return (x);
}

static int		char_into_int(int c, unsigned int base)
{
	static char		*vocabulary = "0123456789abcdef";
	unsigned char	i;

	c = ft_tolower(c);
	i = 0;
	while (i < base)
	{
		if (c == vocabulary[i])
			return (i);
		i++;
	}
	return (-1);
}

int				ft_atoi_base(const char *str, unsigned int base)
{
	int x;
	int	i;
	int	s;

	x = 0;
	if (str)
	{
		i = 0;
		s = 1;
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' ||
				str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
			i++;
		if (str[i] == '-')
		{
			s = -1;
			i++;
		}
		else if (str[i] == '+')
			i++;
		while (char_into_int(str[i], base) >= 0)
			x = x * base + s * char_into_int(str[i++], base);
	}
	return (x);
}

int				ft_atoin_base(const char *str, unsigned int base, size_t n)
{
	int x;
	int	i;
	int	s;

	x = 0;
	if (str)
	{
		i = 0;
		s = 1;
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' ||
				str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
			i++;
		if (str[i] == '-')
		{
			s = -1;
			i++;
		}
		else if (str[i] == '+')
			i++;
		n++;
		while (char_into_int(str[i], base) >= 0 && --n > 0)
			x = x * base + s * char_into_int(str[i++], base);
	}
	return (x);
}
