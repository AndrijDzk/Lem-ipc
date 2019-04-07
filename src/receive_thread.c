/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 09:14:27 by adzikovs          #+#    #+#             */
/*   Updated: 2019/04/07 10:00:22 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/sem.h>
#include <string.h>

#include "return_codes.h"
#include "lemipc.h"

#include "libft.h"

static int			receive_sync_point(int semid, t_lemipcSharedDB *shm, int n)
{
	struct sembuf	op;

	fill_sembuf(&op, REPLY_SEM, 1, 0);
	if (semop(semid, &op, 1))
		return (terminate(shm, WTF));
	if (n == 0)
		fill_sembuf(&op, UPDATE_SEM1, -1, 0);
	else
		fill_sembuf(&op, UPDATE_SEM2, -1, 0);
	if (semop(semid, &op, 1))
		return (terminate(shm, WTF));
	return (OK);
}

inline static void	alive_check(t_slave_param *param)
{
	int				x;
	int				y;
	unsigned 		team;

	x = param->crd->x;
	y = param->crd->y;
	team = param->team;
	if (check_adjacent_cells(x, y, team, param->lemipc->shm->pf) != ALIVE)
		(*param->alv) = 0;
}

inline static int	clear_if_dead(t_slave_param *param)
{
	int				x;
	int				y;
	int				semid;
	struct sembuf	op;

	x = param->crd->x;
	y = param->crd->y;
	if ((*param->alv) == 0 &&
		x >= 0 && x < FIELD_WIDTH &&
		y >= 0 && y < FIELD_HEIGHT)
		param->lemipc->shm->pf[y][x] = 0;
	semid = param->lemipc->semid;
	if ((*param->alv) == 0)
	{
		fill_sembuf(&op, PLR_AM_SEM, -1, 0);
		if (semop(semid, &op, 1))
			return (terminate(param->lemipc->shm, WTF));
		param->lemipc->shm->players_am--;
		fill_sembuf(&op, PLR_AM_SEM, 1, 0);
		if (semop(semid, &op, 1))
			return (terminate(param->lemipc->shm, WTF));
	}
	return (OK);
}

static inline int	receive_thread_body(t_slave_param *param)
{
	struct sembuf	op;

	while (1)
	{
		ft_printf("cycle start\n");
		fill_sembuf(&op, UPDATE_SEM1, -1, 0);
		semop(param->lemipc->semid, &op, 1);
		alive_check(param);
		ft_printf("alive_check\n");
		receive_sync_point(param->lemipc->semid, param->lemipc->shm, 1);
		clear_if_dead(param);
		ft_printf("clear_if_dead\n");
		receive_sync_point(param->lemipc->semid, param->lemipc->shm, 0);
		print_playfield(param->lemipc->shm->pf);
		fill_sembuf(&op, REPLY_SEM, 1, 0);
		semop(param->lemipc->semid, &op, 1);
		if ((*param->alv) == 0)
			return (OK);
		ft_printf("cycle end\n");
	}
}

void				*receive_thread(void *param)
{
	receive_thread_body(param);
	return (NULL);
}
