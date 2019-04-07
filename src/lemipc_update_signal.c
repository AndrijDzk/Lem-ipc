/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc_update_signal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:07:05 by adzikovs          #+#    #+#             */
/*   Updated: 2019/04/07 11:41:02 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/sem.h>
#include <sys/msg.h>

#include "return_codes.h"
#include "defines.h"
#include "lemipc_typedefs.h"
#include "lemipc.h"


static int	update_pulse(int semid, short players_am, int n)
{
	struct sembuf	op;

	fill_sembuf(&op, REPLY_SEM, -players_am, 0);
	if (semop(semid, &op, 1))
		return (WTF);
	if (n == 0)
		fill_sembuf(&op, SYNC_SEM0, players_am, 0);
	else
		fill_sembuf(&op, SYNC_SEM1, players_am, 0);
	if (semop(semid, &op, 1))
		return (WTF);
	return (OK);
}

int			update_signal(t_lemipcSharedDB *shm, int semid, short players_am)
{
	struct sembuf	op;

	fill_sembuf(&op, SYNC_SEM0, players_am, 0);
	if (semop(semid, &op, 1))
		return (terminate(shm, WTF));
	if (update_pulse(semid, players_am, 1))
		return (terminate(shm, WTF));
	if (update_pulse(semid, players_am, 0))
		return (terminate(shm, WTF));
	if (update_pulse(semid, players_am, 1))
		return (terminate(shm, WTF));
	fill_sembuf(&op, REPLY_SEM, -(players_am), 0);
	if (semop(semid, &op, 1))
		return (terminate(shm, WTF));
	return (OK);
}
