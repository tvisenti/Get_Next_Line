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

size_t		ft_strclen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int		get_next_line(int fd, char **line)
{
	int					res;
	int					len;
	char				buff[BUFF_SIZE + 1];
	static char	**save = NULL;

	len = 0;
	if (fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	if ((save = (char **)malloc(sizeof(char *) * 257)) == NULL)
		return (-1);
	if (!save[fd] && (save[fd] = ft_strnew(BUFF_SIZE)) == NULL)
				return (-1);
	while (!(ft_strchr(save[fd], '\n')) && (res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		//buff[res] = '\0';
		save[fd] = ft_strjoin(save[fd], buff);
	}
	*line = ft_strsub(save[fd], 0, ft_strclen(save[fd], '\n'));
	if (ft_strchr(save[fd], '\n'))
	{
		save[fd] = ft_strchr(save[fd], '\n') + 1;
		return (1);
	}
	save[fd] += ft_strclen(save[fd], '\n');
	return (res ? 1 : 0);
}

/*

int			get_next_line(int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static char		**save = NULL;
	int				res;

	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	if (save == NULL || save[fd] == '\0')
		save = ft_new_fd(save, fd);
	while (!(ft_strchr(save[fd], '\n')) && (res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		save[fd] = ft_strjoin(save[fd], buff);
	}
	*line = ft_strsub(save[fd], 0, ft_cnt_chr(save[fd]));
	if (ft_strchr(save[fd], '\n'))
	{
		save[fd] = ft_strchr(save[fd], '\n') + 1;
		return (1);
	}
	save[fd] += ft_cnt_chr(save[fd]);
	return (res ? 1 : 0);
}

int		get_next_line(int fd, char **line)
{
	int					res;
	int					len;
	char				buff[BUFF_SIZE];
	static char	*save;

	len = 0;
	if (fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	while ((res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		printf("buff : %s\n", buff);
		getchar();
		len = ft_strclen(buff, '\n');
		buff[res] = '\0';
		if (len == 0 && !save)
			save = ft_strdup(buff);
		else if (len == 0 && save)
		{
			save = ft_strjoin(save, buff);
			printf("save : %s\n", save);
			getchar();
		}
		else if (len > 0)
		{
			printf("1\n");
			getchar();
			*line = ft_strncpy(*line, buff, len - 1);
			printf("here\n");
			getchar();
			save = ft_strsub(buff, len, BUFF_SIZE - len);
			printf("ca foire ici\n");
			getchar();
		}
	}
	return (res ? 1 : 0);
}

int		get_next_line(int fd, char **line)
{
	int					res;
	char				*buff;
	static char	*save = NULL;

	res = 0;
	if (fd < 0 || BUFF_SIZE < 1 || !*line || (!(buff = ft_strnew(BUFF_SIZE))))
		return (-1);
	while (res == read(fd, buff, BUFF_SIZE) > 0)
	{
		if (!save && (!(save = ft_strnew(BUFF_SIZE))))
			return (-1);
		while (*buff)
		{
			if (ft_strclen(buff, '\n') == 0)
			{
				save = ft_strdup(buff);
				break ;
			}
			if (*buff == '\n')
			{
				*line = ft_strncpy(line, buff, ft_strclen(buff, '\n'));
				save = ft_strsub(buff, ft_strclen(buff, '\n'), BUFF_SIZE);
				break ;
			}
			*buff++;
		}
		return (res > 0 ) ? d_and_d(line, save, buff, res);
		//return (res > 0) ? get_next_line(fd, line) : -1;
	}
}

static int	d_and_d(char **line, char **save, char **buff, int res)
{
	if (!(*line = ft_strdup(*save)))
		return (-1);
	ft_strdel(save);
	ft_strdel(buff);.
	return ((res == 0) ? 0 : 1);
}

int				get_next_line(int const fd, char **line)
{
	int	res;
	char	*buff;
	static char *save = NULL;

	res = 0;
	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
				buff = ft_strnew(BUFF_SIZE);
		while (res == read(fd, buff, BUFF_SIZE) < 0)
		{
			if (!save)
				save = ft_strnew(BUFF_SIZE);
			ft_bzero(buff, BUFF_SIZE);
			if (save == NULL || buff == NULL)
				return (-1);
			if (*buff != '\n' && res != 0)
				save = ft_strjoin(save, buff);
			if (*buff == '\n' || res == 0)
				d_and_d(line, &save, &buff, res);
				printf("%s\n", *line);
		}
		return (-1);
}
*/
/*
int				get_next_line(int const fd, char **line)
{
	int	cnt;
	int	res;
	char	*buff;
	static char *save = NULL;

	cnt = -1;
	res = 0;
	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	while (++cnt < BUFF_SIZE)
	{
		if (!save)
			save = ft_strnew(2);
		buff = ft_strnew(2);
		if (save == NULL || buff == NULL)
			return (-1);
		if ((res = read(fd, buff, 1)) < 0)
			return (-1);
		if (*buff != '\n' && res != 0)
			save = ft_strjoin(save, buff);
		if (*buff == '\n' || res == 0)
			return (d_and_d(line, &save, &buff, res));
	}
	return ((cnt == BUFF_SIZE) ? get_next_line(fd, line) : -1);
}
*/
