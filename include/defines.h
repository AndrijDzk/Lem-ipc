/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:01:17 by adzikovs          #+#    #+#             */
/*   Updated: 2019/04/07 08:27:55 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define IPC_KEY ftok(KEYFILE, 1)

# define ACTION_SEM 0
# define UPDATE_SEM1 1
# define UPDATE_SEM2 2
# define REPLY_SEM 3
# define PLR_AM_SEM 4
# define SEM_AM 5

# define FIELD_WIDTH 50
# define FIELD_HEIGHT 50

# define SEM 1
# define PLR_AM 2
# define ALV 4
# define CRD 8

#endif
