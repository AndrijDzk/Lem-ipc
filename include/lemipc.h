/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:58:46 by adzikovs          #+#    #+#             */
/*   Updated: 2019/04/06 18:36:11 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIPC_H
# define LEMIPC_H

# include <sys/sem.h>

# include "defines.h"
# include "lemipc_typedefs.h"

inline void		fill_sembuf(
					struct sembuf *op,
					unsigned short sem_num,
					short sem_op,
					short sem_flg);

int				terminate(t_lemipcSharedDB *db, int ret);

int				update_signal(t_lemipcSharedDB *shm, int semid, short players_am);

int				join_game(t_slave_param *param);

void			print_playfield(unsigned playfield[FIELD_HEIGHT][FIELD_WIDTH]);

int				check_adjacent_cells(
					int x, int y,
					unsigned team,
					unsigned pf[FIELD_HEIGHT][FIELD_WIDTH]);

void			*receive_thread(void *param);

void			*send_thread(void *param);

int				move(
					int c,
					t_point *crd,
					unsigned team,
					unsigned pf[FIELD_HEIGHT][FIELD_WIDTH]);

#endif
