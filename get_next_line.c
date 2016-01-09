/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 09:58:01 by tvisenti          #+#    #+#             */
/*   Updated: 2016/01/09 09:23:45 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h"
/*
static int		ckeck_backslash(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
*/
static int	read_line(int const fd, char *buf, char *save[fd])
{
	int				ret;
	char			*c;
	char			*tmp;

	while ((c = ft_strchr(buf, '\n')) == NULL &&
			(ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = save[fd];
		save[fd] = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
	}
	ft_strdel(&buf);
	if (ret == -1)
		return (-1);
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	static char	*save;
	char		*buf;
	int			res;
	char		*s;
	char		*tmp;

	buf = f_strnew(BUFF_SIZE);
	if (fd < 0 || line == NULL ||BUFF_SIZE < 1 || buf == NULL)
		return (-1);
	if ((res = read_line(fd, buf, save)) == -1)
		return (-1);
	if ((str = ft_strchr(save[fd], '\n')) != NULL)
	{
		*line = ft_strsub(save[fd], 0, str - save[fd]);
		tmp = save[fd];
		save[fd] = ft_strdup(str + 1);
		ft_strdel(&tmp);
		return (1);
	}
	*line = ft_strdup(save[fd]);
	save[fd] = NULL;
	return (ft_strlen(*line) > 0 ? 1 : 0);
	}
}

/*
int			get_next_line(int const fd, char **line)
{
	char		*buf;
	static char	*save;
	int		res;


	while (res == read(fd, buf, BUFF_SIZE) > 0)
	{
		*line = (char *)malloc(sizeof(char *) * BUFF_SIZE + ft_strlen(save) + 1);
		*line = ft_strcpy(*line, save);
		if (ft_strchr(buf, '\n'))
		{
			ft_strncpy(*line, buf, ft_strclen(buf, '\n'));
			save = ft_strocpy(buf, '\n');
					printf("test");
		}
	}
	return (0);
}
*/
/*
int				get_next_line(int const fd, char **line)
{
	static int	i;
	static int	index;
	char		buf[BUFF_SIZE];

	i = 0;
	index = 0;
	while (read(fd, buf, BUFF_SIZE))
	{
		while (buf[i] != '\n')
			i++;
		line[index] = strndup(buf, i);
		index++;
	}
	return (0);
}
*/
