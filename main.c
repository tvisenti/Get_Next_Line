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
#include <stdio.h> //del
#include <fcntl.h>

void	ft_exit(const char *str)
{
	if (str)
		ft_putendl_fd(str, 2);
	exit(1);
}

int	main(int nb_arg, char **arg)
{
	char	*line;
	int		fd;
	int		code;

	if (nb_arg != 2)
		ft_exit("Error: Wrong argument number");
	if ((fd = open(arg[1], O_RDONLY)) == -1)
		ft_exit("Error: Can't open file");
	while ((code = get_next_line(fd, &line)) > 0)
	{
		printf("%d - |%s|\n", code, line);
		free(line);
	}
	printf("LAST %d - |%s|\n", code, line);
	return (0);
}
