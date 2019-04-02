/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:58:46 by adzikovs          #+#    #+#             */
/*   Updated: 2019/04/02 19:59:23 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIPC_H
# define LEMIPC_H

# include <sys/ipc.h>

# include "defines.h"

typedef struct
{
	int			semid;
	int			msgqid;
	unsigned	players_am;
	unsigned	playfield[FIELD_HEIGHT][FIELD_WIDTH];
}				t_lemipcSharedDB;

#endif
