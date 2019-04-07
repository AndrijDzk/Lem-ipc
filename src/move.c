/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:12:59 by adzikovs          #+#    #+#             */
/*   Updated: 2019/04/06 18:12:59 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "return_codes.h"
#include "lemipc_typedefs.h"

inline static int		check_crd(
							t_point *crd,
							unsigned pf[FIELD_HEIGHT][FIELD_WIDTH])
{
	if (crd->x < 0 || crd->x >= FIELD_WIDTH ||
		crd->y < 0 || crd->y >= FIELD_HEIGHT ||
		pf[crd->y][crd->x])
		return (WTF);
	return (OK);
}

inline static void		move_crd(int c, t_point *crd)
{
	if (c == 'w')
		(crd->y)--;
	else if (c == 'a')
		(crd->x)--;
	else if (c == 's')
		(crd->y)++;
	else if (c == 'd')
		(crd->x)++;
}

int						move(
							int c,
							t_point *crd,
							unsigned team,
							unsigned pf[FIELD_HEIGHT][FIELD_WIDTH])
{
	t_point		new_crd;

	new_crd.x = crd->x;
	new_crd.y = crd->y;
	move_crd(c, &new_crd);
	if (check_crd(&new_crd, pf) == OK)
	{
		pf[crd->y][crd->x] = 0;
		pf[new_crd.y][new_crd.x] = team;
		*crd = new_crd;
		return (OK);
	}
	return (WTF);
}
