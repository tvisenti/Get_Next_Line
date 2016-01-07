/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 15:06:47 by tvisenti          #+#    #+#             */
/*   Updated: 2015/12/30 16:20:54 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	**line;

	argc = 2;
	i = 0;
	line = NULL;
	fd = open(argv[1], O_RDONLY, 0555);
	get_next_line(fd, line);
	//ft_putstr(*line);
	return (0);
}
