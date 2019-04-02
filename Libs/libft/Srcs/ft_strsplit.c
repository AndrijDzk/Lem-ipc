/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 13:13:26 by adzikovs          #+#    #+#             */
/*   Updated: 2018/09/20 13:13:26 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *line, const char *delims)
{
	size_t	i;
	int		res;

	res = 0;
	if (line == NULL || delims == NULL)
		return (-1);
	i = 0;
	while (line[i])
	{
		while (line[i] && ft_strchr(delims, line[i]))
			i++;
		if (line[i])
			res++;
		while (line[i] && ft_strchr(delims, line[i]) == NULL)
			i++;
	}
	return (res);
}

static int	get_words(char **res, const char *line, const char *delims)
{
	size_t		i;
	size_t		ct;
	size_t		start;

	ct = 0;
	if (res == NULL || line == NULL || delims == NULL)
		return (-1);
	i = 0;
	while (line[i] && ft_strchr(delims, line[i]))
		i++;
	while (line[i])
	{
		start = i;
		while (line[i] && ft_strchr(delims, line[i]) == NULL)
			i++;
		if (i == start)
			break ;
		res[ct] = ft_strndup(line + start, i - start);
		ct++;
		while (line[i] && ft_strchr(delims, line[i]))
			i++;
	}
	return (0);
}

char		**ft_strsplit(const char *line, const char *delims)
{
	char	**res;
	int		words;

	if ((words = count_words(line, delims)) < 0)
		return (NULL);
	res = (char**)malloc(sizeof(*res) * ((size_t)words + 1));
	if (get_words(res, line, delims) < 0)
	{
		free(res);
		return (NULL);
	}
	res[words] = NULL;
	return (res);
}
