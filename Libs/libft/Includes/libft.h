/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:43:50 by adzikovs          #+#    #+#             */
/*   Updated: 2018/11/08 12:11:41 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdarg.h>
# include <inttypes.h>
# include <stdlib.h>

# include "list.h"
# include "get_next_line.h"

int		ft_tolower(int c);

int		ft_isdigit(int c);

int		ft_printf(const char *str, ...);

int		ft_atoi(const char *str);

int		ft_atoi_base(const char *str, unsigned int base);

int		ft_atoin_base(const char *str, unsigned int base, size_t n);

char	*ft_itoa(int i);

void	ft_bzero(void *addr, size_t size);

int		ft_strcmp(const char *s1, const char *s2);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strchr(const char *s, int c);

int		ft_strbegins(const char *str, char const *start);

int		ft_strdiff(const char *s1, const char *s2);

int		ft_find_char(char *str, char c);

size_t	ft_strlen(const char *str);

char	*ft_strcpy(char *dst, const char *src);

char	*ft_strncpy(char *dst, const char *src, size_t n);

char	*ft_strdup(const char *s1);

char	*ft_strndup(const char *s1, size_t n);

char	*ft_strsub(const char *s, unsigned int start, size_t len);

char	*ft_strjoin(const char *s1, const char *s2);

char	*ft_multistrjoin(char *strings[], size_t am);

char	**ft_strsplit(const char *line, const char *delims);

void	*ft_memset(void *dst, int c, size_t len);

void	*ft_memcpy(void *dst, const void *src, size_t len);

void	*ft_memmove(void *dst, void *src, size_t n);

void	*ft_memdup(const void *src, size_t size);

int		ft_count_digits(uintmax_t value, int base);

void	free_2darr(void **arr);

size_t	get_2d_arr_size(void **arr);

#endif
