/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sembuf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:41:39 by adzikovs          #+#    #+#             */
/*   Updated: 2019/04/06 14:30:31 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/sem.h>

void		fill_sembuf(struct sembuf *op, unsigned short sem_num, short sem_op, short sem_flg)
{
	op->sem_num = sem_num;
	op->sem_op = sem_op;
	op->sem_flg = sem_flg;
}
