/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skesuma <skesuma@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:12:32 by skesuma           #+#    #+#             */
/*   Updated: 2022/02/21 11:56:56 by skesuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 21

# include <stdlib.h>
# include <stdio.h> //remove later?
# include <fcntl.h>
# include "libft/libft.h"

int	get_next_line(const int fd, char **line);

typedef struct s_coord
{
	size_t	x;
	size_t	y;
	char	letter;
}			t_coord;

typedef struct s_etris
{
	t_coord	**pos;
	size_t	nblock;
}			t_etris;

#endif
