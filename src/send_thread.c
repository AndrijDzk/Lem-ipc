/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:46:03 by adzikovs          #+#    #+#             */
/*   Updated: 2019/04/07 14:08:36 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/sem.h>
#include <sys/select.h>
#include <unistd.h>

#include "return_codes.h"
#include "lemipc.h"

static ssize_t		double_read(int fd1, int fd2, char *res)
{
	fd_set			set;

	FD_ZERO(&set);
	FD_SET(fd1, &set);
	FD_SET(fd2, &set);
	if (select(FD_SETSIZE, &set, NULL, NULL, NULL) < 0)
		return (-1);
	if (FD_ISSET(fd1, &set))
		return (read(fd1, res, 1));
	if (FD_ISSET(fd2, &set))
		return (read(fd2, res, 1));
	return (-1);
}

int					send_thread_body(t_slave_param *param)
{
	char			c;
	struct sembuf	op;

	while(double_read(0, param->lemipc->pipe[0], &c) > 0)
	{
		if (c != 'w' && c != 'a' && c != 's' && c != 'd' && c != 'q')
			continue;
		if ((*param->alv) == 0)
			return (0);
		fill_sembuf(&op, ACTION_SEM, -1, 0);
		if (semop(param->lemipc->semid, &op, 1))
			break;
		if (c == 'q')
			(*param->alv) = 0;
		if (c == 'q' ||
			move(c, param->crd, param->team, param->lemipc->shm->pf) == OK)
			update_signal(param->lemipc->shm, param->lemipc->semid,
				param->lemipc->shm->players_am);
		fill_sembuf(&op, ACTION_SEM, 1, 0);
		if (semop(param->lemipc->semid, &op, 1) ||
			c == 'q' || (*param->alv) == 0)
			break;
	}
	(*param->alv) = 0;
	return (0);
}
