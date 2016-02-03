/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 09:39:12 by tvisenti          #+#    #+#             */
/*   Updated: 2016/02/03 11:19:24 by tvisenti         ###   ########.fr       */
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

int			main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		code;
	int		len;
	int		i;

	i = 1;
	printf("\n___Premier FD___ \n\n");
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
