/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc_typedefs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:44:27 by adzikovs          #+#    #+#             */
/*   Updated: 2019/04/07 08:27:55 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIPC_TYPEDEFS_H
# define LEMIPC_TYPEDEFS_H

# include "defines.h"

typedef struct
{
	short					players_am;
	char					error;
	unsigned				pf[FIELD_HEIGHT][FIELD_WIDTH];
}							t_lemipcSharedDB;

typedef struct
{
	int						semid;
	int						shmid;
	t_lemipcSharedDB		*shm;
	int						pipe[2];
}							t_lemipc;

typedef struct
{
	int						x;
	int						y;
}							t_point;

typedef struct
{
	char					*alv;
	t_point					*crd;
	unsigned				team;
	t_lemipc				*lemipc;
}							t_slave_param;

#endif
