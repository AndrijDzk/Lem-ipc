/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:54:10 by adzikovs          #+#    #+#             */
/*   Updated: 2019/04/07 08:56:50 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/shm.h>

#include "return_codes.h"
#include "lemipc.h"
#include "libft.h"

int					deinit(t_lemipc *lemipc)
{
	semctl(lemipc->semid, 0, IPC_RMID);
	shmdt(lemipc->shm);
	shmctl(lemipc->shmid, IPC_RMID, NULL);
	return (0);
}

int					play(t_slave_param *param)
{
	pthread_t		rcv_thread_id;
	struct sembuf	op;

	if (join_game(param, &rcv_thread_id))
	{
		perror("join_game: ");
		return (WTF);
	}
	send_thread_body(param);
	pthread_join(rcv_thread_id, NULL);
	fill_sembuf(&op, ACTION_SEM, -1, 0);
	semop(param->lemipc->semid, &op, 1);
	if (param->lemipc->shm->players_am == 0)
		deinit(param->lemipc);
	fill_sembuf(&op, ACTION_SEM, 1, 0);
	semop(param->lemipc->semid, &op, 1);
	return (0);
}

int					main(int argc, char **argv)
{
	char			alive;
	t_point			crd;
	t_lemipc		lemipc;
	t_slave_param	param;

	if (argc != 2)
	{
		ft_printf("Usage: %s team\n", argv[0]);
		return (0);
	}
	if (ft_atoin_base(argv[1], 10, 9) < 0)
	{
		ft_printf("0 < team < 100\n");
		return (0);
	}
	param.alv = &alive;
	param.crd = &crd;
	param.team = (unsigned)ft_atoin_base(argv[1], 10, 9);
	param.lemipc = &lemipc;
	if (init(&lemipc))
		return (0);
	alive = 1;
	play(&param);
	return (0);
}
