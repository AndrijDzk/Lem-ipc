/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 11:26:30 by adzikovs          #+#    #+#             */
/*   Updated: 2017/02/02 18:03:37 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char		*ft_strjoin(const char *s1, char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!s1 && !s2)
		return (0);
	else
	{
		if (!(res = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (0);
		j = 0;
		i = 0;
		if (s1)
			while (s1[i])
				res[j++] = s1[i++];
		i = 0;
		if (s2)
			while (s2[i] && i < len)
			{
				res[j++] = s2[i];
				s2[i++] = 0;
			}
		res[j] = '\0';
		return (res);
	}
}

static int		ft_fread(char *buf, char **line)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	while (i < BUFF_SIZE && buf[i] != '\n')
		i++;
	if (buf[i] == '\n' && i < BUFF_SIZE)
		buf[i++] = 0;
	j = i;
	while (j < BUFF_SIZE && buf[j] != '\n' && buf[j] != '\0')
		j++;
	if (j > i)
	{
		temp = ft_strjoin(*line, buf + i, j - i);
		free(*line);
		*line = temp;
	}
	if (j < BUFF_SIZE && buf[j] == '\n')
		return (0);
	else if (j > i)
		return (-1);
	return (1);
}

static int		ft_read(const int fd, char *buf, char **line)
{
	size_t	i;
	char	*temp;
	int		ret;

	if ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		i = 0;
		while (i < BUFF_SIZE && buf[i] != '\n')
			i++;
		if (i)
		{
			temp = ft_strjoin(*line, buf, i);
			free(*line);
			*line = temp;
		}
		if (buf[i] == '\n')
			return (-1);
		else
			return (1);
	}
	if (ret == -1)
		return (-2);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char	buf[BUFF_SIZE];
	int			ret[3];

	if (line == 0)
		return (-1);
	ret[0] = 1;
	ret[1] = -3;
	ret[2] = 0;
	*line = (char*)malloc(sizeof(**line));
	**line = '\0';
	ret[0] = ft_fread(buf, line);
	if (ret[0] == 0 || ret[0] == -1)
		ret[2] = 1;
	while (ret[0] != 0 && (ret[1] = ft_read(fd, buf, line)) == 1)
		ret[2] = 1;
	if (ret[1] == -2)
		return (-1);
	if (ret[1] == -1)
		ret[2] = 1;
	return (ret[2]);
}
