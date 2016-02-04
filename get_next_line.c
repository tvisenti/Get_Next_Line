/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 10:18:13 by tvisenti          #+#    #+#             */
/*   Updated: 2016/02/04 17:03:48 by tvisenti         ###   ########.fr       */
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
	char			**new_save;

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

static char			*ft_chrandcpy(char *save)
{
	if (ft_strchr(save, '\n'))
	{
		ft_strcpy(save, ft_strchr(save, '\n') + 1);
		return (save);
	}
	if (ft_strclen(save) > 0)
	{
		ft_strcpy(save, ft_strchr(save, '\0'));
		return (save);
	}
	return (NULL);
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
	if (ft_chrandcpy(save[fd]) == NULL)
		return (0);
	return (1);
}
/*
static char			*ft_chrandcpy(char *save)
{
	char	*new;

	if (ft_strchr(save, '\n'))
	{
		new = malloc(sizeof(char *) * ft_strclen(save) + 1);
		ft_strcpy(new, ft_strchr(save, '\n') + 1);
		free(save);
		return (new);
	}
	if (ft_strclen(save) > 0)
	{
		new = malloc(sizeof(char *) * ft_strclen(save));
		ft_strcpy(new, ft_strchr(save, '\0'));
		free(save);
		return (new);
	}
	return (NULL);
}*/