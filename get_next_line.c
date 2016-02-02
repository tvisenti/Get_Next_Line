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
// Probleme : lorsque la fonction est rappelee save[fd] se reinitialise
// le static ne fonctionne pas
int							get_next_line(int const fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static char		**save = NULL;
	int				res;

	if (fd < 0 || BUFF_SIZE <= 0 || !line)
		return (-1);
	if (!save)
	{
		ft_putstr("je cree save"); ft_putstr("\n");
		if ((save = (char **)malloc(sizeof(char *) * 257)) == NULL)
			return (-1);
	}
	if (!(save[fd]))
	{
		ft_putstr("je cree save[fd]"); ft_putstr("\n");
		if ((save[fd] = ft_strnew(0)) == NULL)
			return (-1);
	}
	ft_putstr("save[fd] avant la boucle:"); ft_putstr(save[fd]); ft_putstr("\n"); getchar();
	while (!(ft_strchr(save[fd], '\n')) && (res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		save[fd] = ft_strjoin(save[fd], buff);
		ft_putstr("save[fd] apres le join:"); ft_putstr(save[fd]); ft_putstr("\n"); getchar();
	}
	*line = ft_strsub(save[fd], 0, ft_strclen(save[fd]));
	if (ft_strchr(buff, '\n'))
	{
		ft_putstr("save[fd] avant le strchr:"); ft_putstr(save[fd]); ft_putstr("\n");
		save[fd] = ft_strchr(buff, '\n') + 1;
		ft_putstr("save[fd] apres le strchr:"); ft_putstr(save[fd]); ft_putstr("\n"); getchar();
		return (1);
	}
	save[fd] += ft_strclen(save[fd]);
	ft_putstr("save[fd] juste avant la fin:"); ft_putstr(save[fd]); ft_putstr("\n"); getchar();
	return (res ? 1 : 0);
}
