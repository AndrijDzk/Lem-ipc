/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:35:42 by adzikovs          #+#    #+#             */
/*   Updated: 2019/04/07 08:14:59 by adzikovs         ###   ########.fr       */
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

static int	error_exit(t_slave_param *param, char flag)
{
	struct sembuf	op;
	int				x;
	int				y;

	x = param->crd->x;
	y = param->crd->y;
	fill_sembuf(&op, ACTION_SEM, 1, 0);
	if (flag & SEM)
		semop(param->lemipc->semid, &op, 1);
	if ((flag & PLR_AM) && param->lemipc->shm->players_am)
		(param->lemipc->shm->players_am)--;
	if (flag & ALV)
		(*param->alv) = 0;
	if (flag & CRD)
		param->lemipc->shm->pf[y][x] = 0;
	return (WTF);
}

int			join_game(t_slave_param *param, pthread_t *rcv_thread_id)
{
	struct sembuf		op;
	t_lemipc			*lemipc;
	t_lemipcSharedDB	*shm;

	lemipc = param->lemipc;
	shm = lemipc->shm;
	fill_sembuf(&op, ACTION_SEM, -1, 0);
	if (semop(lemipc->semid, &op, 1))
		return (WTF);
	if (set_start_location(param))
		return (error_exit(param, SEM));
	lemipc->shm->players_am++;
	if (pthread_create(rcv_thread_id, NULL, &receive_thread, param))
		return (error_exit(param, SEM | PLR_AM | CRD));
	if (update_signal(lemipc->shm, lemipc->semid, lemipc->shm->players_am))
		return (error_exit(param, SEM | PLR_AM | ALV | CRD));
	fill_sembuf(&op, ACTION_SEM, 1, 0);
	if (semop(lemipc->semid, &op, 1))
		return (WTF);
	return (OK);
}
