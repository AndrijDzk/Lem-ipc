/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:35:42 by adzikovs          #+#    #+#             */
/*   Updated: 2019/04/06 17:46:00 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/sem.h>

#include "lemipc_typedefs.h"
#include "return_codes.h"
#include "defines.h"
#include "lemipc.h"

static int	set_start_location(t_slave_param *param)
{
	int		x;
	int		y;

	y = 0;
	while (y < FIELD_HEIGHT)
	{
		x = 0;
		while (x < FIELD_WIDTH)
		{
			if (param->lemipc->shm->pf[y][x] == 0)
			{
				param->crd->x = x;
				param->crd->y = y;
				param->lemipc->shm->pf[y][x] = param->team;
				return (OK);
			}
			x++;
		}
		y++;
	}
	return (WTF);
}

int			join_game(t_slave_param *param)
{
	struct sembuf	op;
	int				ret;
	t_lemipc		*lemipc;

	lemipc = param->lemipc;
	fill_sembuf(&op, ACTION_SEM, -1, 0);
	if (semop(lemipc->semid, &op, 1))
		return (WTF);
	ret = set_start_location(param);
	if (ret == OK)
	{
		lemipc->shm->players_am++;
		ret = update_signal(lemipc->shm, lemipc->semid, lemipc->shm->players_am);
	}
	fill_sembuf(&op, ACTION_SEM, 1, 0);
	if (semop(lemipc->semid, &op, 1))
		return (WTF);
	return (ret);
}
