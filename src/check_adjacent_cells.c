/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_adjacent_cells.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 09:18:21 by adzikovs          #+#    #+#             */
/*   Updated: 2019/04/06 09:38:32 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "return_codes.h"
#include "defines.h"

static int	amount_of_players_from_team(const int x, const int y,
				const unsigned team,
				const unsigned playfield[FIELD_HEIGHT][FIELD_WIDTH])
{
	int		i;
	int		j;
	int		ret;

	ret = 0;
	j = y - 1;
	while (j <= (y + 1) && j < FIELD_HEIGHT)
	{
		i = x - 1;
		while (i <= (x + 1) && i < FIELD_WIDTH)
		{
			if (i >= 0 && j >= 0 && playfield[j][i] == team)
				ret++;
			i++;
		}
		j++;
	}
	return (ret);
}

int			check_adjacent_cells(const int x, const int y,
				const unsigned team,
				const unsigned pf[FIELD_HEIGHT][FIELD_WIDTH])
{
	int		i;
	int		j;

	j = y - 1;
	while (j <= (y + 1) && j < FIELD_HEIGHT)
	{
		i = x - 1;
		while (i <= (x + 1) && i < FIELD_WIDTH)
		{
			if (i >= 0 && j >= 0 &&
				pf[j][i] &&	pf[j][i] != team &&
				amount_of_players_from_team(x, y, pf[j][i], pf) > 1)
				return (DEAD);
			i++;
		}
		j++;
	}
	return (ALIVE);
}
