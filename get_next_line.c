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

int				get_next_line(int const fd, char **line)
{
	char		buf[BUFF_SIZE];
	static char	*save;
	int			res;

	res = 0;
	while (res == read(fd, buf, BUFF_SIZE))
	{
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
