/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:46:03 by adzikovs          #+#    #+#             */
/*   Updated: 2019/04/06 18:36:11 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/sem.h>
#include <stdio.h>

#include "return_codes.h"
#include "lemipc.h"


static int			error_exit(t_slave_param *param)
{
	struct sembuf	op;

	fill_sembuf(&op, ACTION_SEM, 1, 0);
	param->alive = 0;
	semop(param->lemipc->semid, &op, 1);
	return (WTF);
}

static inline int	send_thread_body(t_slave_param *param)
{
	int				c;
	struct sembuf	op;

	while((c = getchar()) != EOF)
	{
		if (c != 'w' && c != 'a' && c != 's' && c != 'd')
			continue;
		if (param->alive == 0)
			return (0);
		fill_sembuf(&op, ACTION_SEM, -1, 0);
		if (semop(param->lemipc->semid, &op, 1))
			break;
		if (move(c, param->crd, param->team, param->lemipc->shm->pf) == OK)
		{
			if (update_signal(param->lemipc->shm, param->lemipc->semid,
				param->lemipc->shm->players_am))
				return (error_exit(param));
		}
		fill_sembuf(&op, ACTION_SEM, 1, 0);
		if (semop(param->lemipc->semid, &op, 1))
			break;
	}
	param->alive = 0;
	return (0);
}

void				*send_thread(void *param)
{
	if (join_game(param))
		return (NULL);
	send_thread_body(param);
	return (NULL);
}
