/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 10:18:13 by tvisenti          #+#    #+#             */
/*   Updated: 2016/02/02 13:32:04 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static unsigned int	ft_strclen(char *tmp)
{
	unsigned int i;

	i = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	return (i);
}

int		get_next_line(int fd, char **line)
{
	static char	**save = NULL;
	char				buff[BUFF_SIZE + 1];
	int					res;

	if (fd < 0 || BUFF_SIZE < 1 || !line ||
		(save = (char **)malloc(sizeof(char *) * 257)) == NULL)
		return (-1);
		if (!(save[fd]))
		{
			if ((save[fd] = ft_strnew(0)) == NULL)
				return (-1);
		}
	while (!(ft_strchr(save[fd], '\n')) && (res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		save[fd] = ft_strjoin(save[fd], buff);
	}
	*line = ft_strsub(save[fd], 0, ft_strclen(save[fd]));
	if (ft_strchr(buff, '\n'))
	{
		save[fd] = ft_strchr(buff, '\n') + 1;
		return (1);
	}
	save[fd] += ft_strclen(save[fd]);
	return (res ? 1 : 0);
}
