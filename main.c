/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 09:39:12 by tvisenti          #+#    #+#             */
/*   Updated: 2016/02/09 12:08:10 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void		ft_exit(const char *str)
{
	if (str)
		ft_putendl_fd(str, 2);
	exit(1);
}

/* Main pour STDIN */

int			main(void)
{
	char	*line;
	int		fd;
	int		code;
	int		len;

	fd = 0;
	printf("BUFF_SIZE = %d\n", BUFF_SIZE);
	printf("___FD___ \n\n");
	while ((code = get_next_line(fd, &line)) > 0)
	{
		len = ft_strlen(line);
		printf("%d - %d - |%s|\n", code, len, line);
		free(line);
	}
	return (0);
}

/* Main basique */

int			main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		code;
	int		len;
	int		i;

	i = 1;
	printf("BUFF_SIZE = %d\n", BUFF_SIZE);
	printf("___Premier FD___ \n\n");
	while (i < argc)
	{
		if ((fd = open(argv[i], O_RDONLY)) == -1)
			ft_exit("Error: Can't open file");
		while ((code = get_next_line(fd, &line)) > 0)
		{
			len = ft_strlen(line);
			printf("%d - %d - |%s|\n", code, len, line);
			free(line);
		}
		i++;
		if (i < argc)
			printf("\n___Changement de FD___ \n\n");
	}
	printf("LAST %d - |%s|\n", code, line);
	return (0);
}
