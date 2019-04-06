/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_playfield.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:02:51 by adzikovs          #+#    #+#             */
/*   Updated: 2019/04/06 16:08:15 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemipc_typedefs.h"

void	print_playfield(unsigned playfield[FIELD_HEIGHT][FIELD_WIDTH])
{
	size_t		y;
	size_t		x;

	y = 0;
	while (y < FIELD_HEIGHT)
	{
		x = 0;
		while (x < (FIELD_WIDTH - 1))
		{
			ft_printf("%u ", playfield[y][x]);
			x++;
		}
		ft_printf("%u\n", playfield[y][x]);
		y++;
	}
	ft_printf("-----\n");
}
