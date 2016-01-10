/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 10:18:13 by tvisenti          #+#    #+#             */
/*   Updated: 2016/01/09 10:18:14 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h"

static char		*ft_strocpy(char *str, char c)
{
	int		i;
	int		i_save;
	int		len;
	char	*str_save;

	i = 0;
	len = 0;
	while (str[i] != c)
		i++;
	i++;
	i_save = i;
	while (str[i])
	{
		i++;
		len++;
	}
	str_save = (char *)malloc(sizeof(char) * len);
	str_save = ft_strsub(str, i_save, len);
	return (str_save);
}

static int		check_backslash(char *str)
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

static int	check_save(static char *save, )
{

}

static int	read_line()
{

}

int			get_next_line(int const fd, char **line)
{
	static char	*save[BUFF_MAX];
	char		*cur;
	int			res;

	cur = ft_strnew(BUFF_SIZE);
	if (fd < 0 || line == NULL || cur == NULL || BUFF_SIZE < 1)
		return (-1);
	while ((res = read_line(fd, cur, BUFF_SIZE)) > 0)
	{
		if (*save != NULL)
			check_save(save, cur, *line)
	}
}
