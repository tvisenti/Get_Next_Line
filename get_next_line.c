/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 09:58:01 by tvisenti          #+#    #+#             */
/*   Updated: 2016/01/06 09:22:34 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h"

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

static int		read_line(int fd, char **buf, char *save)
{
	int		res;

}

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
