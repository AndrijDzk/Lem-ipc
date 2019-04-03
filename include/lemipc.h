/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:58:46 by adzikovs          #+#    #+#             */
/*   Updated: 2019/04/03 18:53:04 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIPC_H
# define LEMIPC_H

# include "defines.h"

typedef struct
{
	unsigned	players_am;
	unsigned	playfield[FIELD_HEIGHT][FIELD_WIDTH];
}				t_lemipcSharedDB;

typedef struct
{
	int			semid;
	int			msqid;
	int			shmid;
	void		*shm;
}				t_lemipc;

#endif
