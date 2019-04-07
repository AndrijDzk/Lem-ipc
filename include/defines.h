/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:01:17 by adzikovs          #+#    #+#             */
/*   Updated: 2019/04/07 11:27:33 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define IPC_KEY ftok(KEYFILE, 1)

# define ACTION_SEM 0
# define SYNC_SEM0 1
# define SYNC_SEM1 2
# define REPLY_SEM 3
# define PLR_AM_SEM 4
# define SEM_AM 5

# define FIELD_WIDTH 10
# define FIELD_HEIGHT 10

# define SEM 1
# define PLR_AM 2
# define ALV 4
# define CRD 8

#endif
