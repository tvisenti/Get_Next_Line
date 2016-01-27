/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 10:18:13 by tvisenti          #+#    #+#             */
/*   Updated: 2016/01/24 19:25:59 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	d_and_d(char **line, char **save, char **buff, int res)
{
	if (!(*line = ft_strdup(*save)))
		return (-1);
	ft_strdel(save);
	ft_strdel(buff);
	return ((res == 0) ? 0 : 1);
}

int				get_next_line(int const fd, char **line)
{
	int	res;
	char	*buff;
	static char *save = NULL;

	res = 0;
	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
		while ()
		{
			if (!save)
				save = ft_strnew(BUFF_SIZE);
			buff = ft_strnew(BUFF_SIZE);
			if (save == NULL || buff == NULL)
				return (-1);
			if ((res = read(fd, buff, BUFF_SIZE)) < 0)
				return (-1);
				if (*buff != '\n' && res != 0)
					save = ft_strjoin(save, buff);
				if (*buff == '\n' || res == 0)
					return (d_and_d(line, &save, &buff, res));
		}
}
/*

static int	d_and_d(char **line, char **save, char **buff, int res)
{
	if (!(*line = ft_strdup(*save)))
		return (-1);
	ft_strdel(save);
	ft_strdel(buff);
	return ((res == 0) ? 0 : 1);
}

int				get_next_line(int const fd, char **line)
{
	int	cnt;
	int	res;
	char	*buff;
	static char *save = NULL;

	cnt = -1;
	res = 0;
	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	while (++cnt < BUFF_SIZE)
	{
		if (!save)
			save = ft_strnew(2);
		buff = ft_strnew(2);
		if (save == NULL || buff == NULL)
			return (-1);
		if ((res = read(fd, buff, 1)) < 0)
			return (-1);
		if (*buff != '\n' && res != 0)
			save = ft_strjoin(save, buff);
		if (*buff == '\n' || res == 0)
			return (d_and_d(line, &save, &buff, res));
	}
	return ((cnt == BUFF_SIZE) ? get_next_line(fd, line) : -1);
}
*/
