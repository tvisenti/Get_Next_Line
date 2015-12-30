/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 09:58:01 by tvisenti          #+#    #+#             */
/*   Updated: 2015/12/30 15:38:04 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h"


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

/*
int			get_next_line(int const fd, char **line)
{
	static char	*buf;
	char		*chr;
	int			res;
	int			i;

	while (res == read(fd, buf, BUFF_SIZE))
	{
		if (res < 0)
			return (res);
		i = ft_strclen(buf, '\n');
		chr = malloc(sizeof(char *) * i);
		chr = ft_strchr(buf, '\n');
		printf("%s\n", chr);
	}
	return (0);
}*/
