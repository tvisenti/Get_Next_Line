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

static unsigned int			ft_strclen(char *save)
{
	unsigned int	i;

	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	return (i);
}

int							get_next_line(int const fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static char		**save = NULL;
	int				res;

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!save)
	{
		if ((save = (char **)malloc(sizeof(char *) * 257)) == NULL)
			return (-1);
	}
	if (!(save[fd]))
	{
		if ((save[fd] = ft_strnew(0)) == NULL)
			return (-1);
	}
//	ft_putstr("save[fd] avant la boucle:"); ft_putstr("\n"); ft_putstr(save[fd]); ft_putstr("\n"); getchar();
	while (!(ft_strchr(save[fd], '\n')) && (res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
//		ft_putstr("save[fd] avant le join:"); ft_putstr("\n"); ft_putstr(save[fd]);
		save[fd] = ft_strjoin(save[fd], buff);
//		ft_putstr("save[fd] apres le join:"); ft_putstr("\n"); ft_putstr(save[fd]); ft_putstr("\n"); getchar();
	}
//	ft_putstr("save[fd] avant le sub:"); ft_putstr("\n"); ft_putstr(save[fd]); getchar();
	*line = ft_strsub(save[fd], 0, ft_strclen(save[fd]));
//	ft_putstr("line apres le sub:"); ft_putstr("\n"); ft_putstr(*line); ft_putstr("\n"); getchar();
	if (ft_strchr(save[fd], '\n'))
	{
//		ft_putstr("buff avant le strchr:"); ft_putstr("\n"); ft_putstr(buff); ft_putstr("\n");
//		ft_putstr("save[fd] avant le strchr:"); ft_putstr("\n"); ft_putstr(save[fd]); ft_putstr("\n");
			save[fd] = ft_strcpy(save[fd], ft_strchr(save[fd], '\n') + 1);
	//	ft_putstr("save[fd] apres le strchr:"); ft_putstr("\n"); ft_putstr(save[fd]); ft_putstr("\n"); getchar();
		return (1);
	}
	save[fd] += ft_strclen(save[fd] + 1);
//	ft_putstr("save[fd] juste avant la fin:"); ft_putstr("\n"); ft_putstr(save[fd]); ft_putstr("\n"); getchar();
	return (res ? 1 : 0);
}
