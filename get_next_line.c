/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 10:18:13 by tvisenti          #+#    #+#             */
/*   Updated: 2016/01/24 11:07:27 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		dupanddel(char **line, char **save, char **buff, int res)
{
	if (!(*line = ft_strdup(*save)))
		return (-1);
	ft_strdel(&*save);
	ft_strdel(&*buff);
	if (res == 0 || res == EOF)
		return (0);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	int			cnt;
	int			res;
	char		*buff;
	static char	*save = NULL;

	cnt = 0;
	res = 0;
	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	while (cnt < BUFF_SIZE)
	{
		if (!save)
			save = ft_strnew(2);
		buff = ft_strnew(2);
		if ((res = read(fd, buff, 1)) < 0)
			return (-1);
		if (*buff != '\n' && (res != 0 || res != EOF))
			save = ft_strjoin(save, buff);
		if (*buff == '\n' || res == 0 || res == EOF)
			return (dupanddel(line, &save, &buff, res));
		cnt++;
	}
	if (cnt == BUFF_SIZE)
		return (get_next_line(fd, line));
	return (-1);
}
