/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:01:56 by adzikovs          #+#    #+#             */
/*   Updated: 2018/11/08 12:02:01 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_tolower(int c)
{
	unsigned char	buff;

	buff = (unsigned char)c;
	if ('A' <= buff && buff <= 'Z')
		return ('a' + (buff - 'A'));
	else
		return (buff);
}
