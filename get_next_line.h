/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 10:58:06 by tvisenti          #+#    #+#             */
/*   Updated: 2016/01/03 10:31:43 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct		s_listfd
{
	int				fd;
	char			*buf;
	struct s_listfd	*next;
}					t_listfd;

int		get_next_line(int const fd, char **line);

#endif
