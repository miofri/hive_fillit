/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skesuma <skesuma@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:39:58 by skesuma           #+#    #+#             */
/*   Updated: 2022/02/23 19:27:16 by skesuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_etris	*file_reader(char *argv[], t_etris *block, char *buf)
{
	int		fd;
	int		ret;
	int		count;

	count = 0;
	if (block == NULL)
		return (NULL);
	fd = open(argv[1], O_RDONLY);
	ret = read(fd, buf, 21);
	while (ret > 0)
	{
		count++;
		ret = read(fd, buf, 21);
	}
	printf("number of grid is %d\n", count);
	close(fd);
	block->nblock = count;
	block->pos = (t_coord **)malloc(sizeof(t_coord *) * count);
	if (block->pos == NULL)
		return (NULL);
	return (block);
}

void	take_coor(int fd, char *buf, t_etris *block)
{
	char	letter;
	int		i;
	size_t	o;
	size_t	k;

	o = 0;
	letter = 'A';
	while (read(fd, buf, 21))
	{
		block->pos[o] = (t_coord *)malloc(sizeof(t_coord) * 4);
		buf[21] = '\0';
		k = 0;
		i = -1;
		while (++i < 21)
		{
			if (buf[i] == '#')
			{
				block->pos[o][k].x = i % 5;
				block->pos[o][k].y = i / 5;
				block->pos[o][k++].letter = letter + o;
			}
		}
		o++;
	}
}

int	parse(char *argv[])
{
	t_etris	*block;
	int		fd;
	char	*buf;

	block = (t_etris *)malloc(sizeof(t_etris));
	buf = (char *)malloc(sizeof(char) * 546);
	block = file_reader(argv, block, buf);
	fd = open(argv[1], O_RDONLY);
	take_coor(fd, buf, block);
	return (0);
}

int	main(int argc, char *argv[])
{
	argc = 0;
	parse(argv);
}
