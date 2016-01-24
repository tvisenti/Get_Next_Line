/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 09:39:12 by tvisenti          #+#    #+#             */
/*   Updated: 2016/01/09 09:39:14 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*line;

	if (argc != 2)
		return (0);
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	i = get_next_line(fd, &line);
	while (i > 0)
	{
		printf("%s\n", line);
		i = get_next_line(fd, &line);
	}
	return (0);
}
