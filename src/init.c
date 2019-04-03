/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:44:10 by adzikovs          #+#    #+#             */
/*   Updated: 2019/04/03 18:53:04 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/sem.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <string.h>

#include "libft.h"

#include "return_codes.h"
#include "lemipc.h"

static int		init_error_exit(int semid, int msqid)
{
	if (semid > 0)
		semctl(semid, 0, IPC_RMID);
	if (msqid > 0)
		msgctl(msqid, IPC_RMID, NULL);
	return (WTF);
}

static int		attach_sharedDB(int shmid, void **shm)
{
	if ((*shm = shmat(shmid, NULL, 0)) == NULL)
	{
		shmctl(shmid, IPC_RMID, NULL);
		return (-1);
	}
	return (shmid);
}

static int		init_sharedDB(void **shm)
{
	int			ret;

	if ((ret = shmget(IPC_KEY, 0, 0)) >= 0)
		return (attach_sharedDB(ret, shm));
	if ((ret = shmget(IPC_KEY, sizeof(t_lemipcSharedDB), IPC_CREAT)) >= 0 &&
		attach_sharedDB(ret, shm) >= 0)
	{
		ft_bzero(*shm, sizeof(t_lemipcSharedDB));
		((t_lemipcSharedDB*)*shm)->players_am = 1;
		return (ret);
	}
	return (-1);
}

int				init(t_lemipc *lemipc)
{
	if ((lemipc->semid = semget(IPC_KEY, SEM_AM, IPC_CREAT) < 0))
		return (WTF);
	if ((lemipc->msqid = msgget(IPC_KEY, IPC_CREAT)) < 0)
		return (init_error_exit(lemipc->semid, -1));
	if ((lemipc->shmid = init_sharedDB(&lemipc->shm)) < 0)
		return (init_error_exit(lemipc->semid, lemipc->msqid));
	return (OK);
}
