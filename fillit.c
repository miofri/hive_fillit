/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skesuma <skesuma@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:13:42 by skesuma           #+#    #+#             */
/*   Updated: 2022/02/03 18:26:50 by skesuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
//TODO INVALID MAP CHECKER

void	print_map(char **map, int map_size)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < map_size)
	{
		while (y < map_size)
			ft_putchar(map[x][y++]);
		ft_putchar ('\n');
		y = 0;
		x++;
	}
}

char	**generate_map(int map_size, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	map = (char **)malloc(sizeof(map) * map_size + 1);
	map[map_size] = 0;
	while (y < map_size)
		map[y++] = (char *)malloc(sizeof(char) * map_size + 1);
	y = 0;
	while (x < map_size)
	{
		while (y < map_size)
		map[x][y++] = '.';
		y = 0;
		x++;
	}
	return (map);
}

int	map_gen(int map_size, char buf[BUFF_SIZE + 1])
{
	char	***map;
	int		y;

	y = 0;
	map = NULL;
	map = generate_map(map_size, map);
	print_map(map, map_size);
	return (0);
}

// int	main(int argc, char *argv[])
// {
// 	int		map_size;
// 	int		fd1;
// 	int		ret;
// 	char	buf[BUFF_SIZE + 1];

// 	if (argc != 2)
// 	{
// 		write (1, "Usage: only 1 file as argument\n", 31);
// 		return (1);
// 	}
// 	else
// 	{
// 		fd1 = open(argv[1], O_RDONLY);
// 		ret = read(fd1, buf, BUFF_SIZE);
// 		if (fd1 == -1 || ret == -1)
// 			return (-1);
// 	}
// 	map_size = 4; //make a macro for this depending on the no. of tetro
// 	ret = read(fd1, buf, BUFF_SIZE);
// 	buf[ret] = '\0';
// 	/* while (*(buf + map_size) != '\n' && *(buf + map_size) != '\0') //not needed
// 	 	map_size++; */
// 	printf ("The map size is %i\n", map_size);
// 	return (map_gen(map_size, buf));
// }
