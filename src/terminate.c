/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:47:20 by adzikovs          #+#    #+#             */
/*   Updated: 2019/04/06 14:47:20 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc_typedefs.h"

int		terminate(t_lemipcSharedDB *db, int ret)
{
	if (db)
		db->error = 1;
	return (ret);
}
