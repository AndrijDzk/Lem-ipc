/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:01:17 by adzikovs          #+#    #+#             */
/*   Updated: 2019/04/06 15:52:53 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define IPC_KEY ftok(KEYFILE, 1)

# define SEM_AM 4
# define ACTION_SEM 0
# define UPDATE_SEM 1
# define REPLY_SEM 2
# define PLR_AM_SEM 3

# define FIELD_WIDTH 50
# define FIELD_HEIGHT 50

#endif
