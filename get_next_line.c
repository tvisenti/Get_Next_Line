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

static unsigned int	ft_strclen(char *save)
{
	unsigned int	i;

	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	return (i);
}

static char			**ft_allocate(char **save, int fd)
{
	char	**new_save;

	new_save = save;
	if (!new_save)
	{
		if ((new_save = (char **)malloc(sizeof(char *) * 257)) == NULL)
			return (NULL);
	}
	if (!(new_save[fd]))
	{
		if ((new_save[fd] = ft_strnew(0)) == NULL)
			return (NULL);
	}
	return (new_save);
}

int					get_next_line(int const fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	**save = NULL;
	int			res;

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!(save = ft_allocate(save, fd)))
		return (-1);
	while (!(ft_strchr(save[fd], '\n')) &&
	(res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		save[fd] = ft_strjoin(save[fd], buff);
	}
	*line = ft_strsub(save[fd], 0, ft_strclen(save[fd]));
	if (ft_strchr(save[fd], '\n'))
	{
		save[fd] = ft_strcpy(save[fd], ft_strchr(save[fd], '\n') + 1);
		return (1);
	}
	save[fd] = save[fd] + ft_strclen(save[fd]);
	return (res ? 1 : 0);
}
