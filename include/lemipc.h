/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:58:46 by adzikovs          #+#    #+#             */
/*   Updated: 2019/04/07 08:44:34 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIPC_H
# define LEMIPC_H

# include <pthread.h>
# include <sys/sem.h>

# include "defines.h"
# include "lemipc_typedefs.h"

int				init(t_lemipc *lemipc);

void			fill_sembuf(
					struct sembuf *op,
					unsigned short sem_num,
					short sem_op,
					short sem_flg);

int				terminate(t_lemipcSharedDB *db, int ret);

int				update_signal(t_lemipcSharedDB *shm, int semid, short players_am);

int				join_game(t_slave_param *param, pthread_t *rcv_thread_id);

void			print_playfield(unsigned playfield[FIELD_HEIGHT][FIELD_WIDTH]);

int				check_adjacent_cells(
					int x, int y,
					unsigned team,
					unsigned pf[FIELD_HEIGHT][FIELD_WIDTH]);

void			*receive_thread(void *param);

int				send_thread_body(t_slave_param *param);

int				move(
					int c,
					t_point *crd,
					unsigned team,
					unsigned pf[FIELD_HEIGHT][FIELD_WIDTH]);

#endif
