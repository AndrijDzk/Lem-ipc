/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:44:10 by adzikovs          #+#    #+#             */
/*   Updated: 2019/04/07 09:13:57 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/sem.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <string.h>
#include <stdio.h>

#include "libft.h"

#include "return_codes.h"
#include "lemipc_typedefs.h"
#include "lemipc.h"

static int			init_sem(void)
{
	int				ret;
	struct sembuf	op;

	if ((ret = semget(IPC_KEY, SEM_AM, 0)) > 0)
		return (ret);
	if ((ret = semget(IPC_KEY, SEM_AM, IPC_CREAT | 0777)) < 0)
		return (-1);
	fill_sembuf(&op, ACTION_SEM, 1, 0);
	if (semop(ret, &op, 1))
	{
		semctl(ret, 0, IPC_RMID);
		return (-1);
	}
	fill_sembuf(&op, PLR_AM_SEM, 1, 0);
	if (semop(ret, &op, 1))
	{
		semctl(ret, 0, IPC_RMID);
		return (-1);
	}
	return (ret);
}

static int			attach_sharedDB(int shmid, void **shm)
{
	if ((*shm = shmat(shmid, NULL, 0)) == (void*)-1)
	{
		perror("shmat");
		shmctl(shmid, IPC_RMID, NULL);
		return (-1);
	}
	return (shmid);
}

static int			init_sharedDB(void **shm)
{
	int			ret;

	if ((ret = shmget(IPC_KEY, 0, 0)) >= 0)
		return (attach_sharedDB(ret, shm));
	if ((ret = shmget(IPC_KEY, sizeof(t_lemipcSharedDB), IPC_CREAT | 0777)) >= 0 &&
		attach_sharedDB(ret, shm) >= 0)
	{
		ft_bzero(*shm, sizeof(t_lemipcSharedDB));
		return (ret);
	}
	return (-1);
}

int					init(t_lemipc *lemipc)
{
	if ((lemipc->semid = init_sem()) < 0)
		return (WTF);
	if ((lemipc->shmid = init_sharedDB((void**)&lemipc->shm)) < 0)
		return (semctl(lemipc->semid, 0, IPC_RMID));
	return (OK);
}
