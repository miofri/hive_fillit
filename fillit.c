/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skesuma <skesuma@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:13:42 by skesuma           #+#    #+#             */
/*   Updated: 2022/01/25 16:25:27 by skesuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void print_map(char **map, int x, int y, int map_size)
{
	while(x < map_size)
	{
		while (y < map_size)
			ft_putchar(map[x][y++]);
		ft_putchar ('\n');
		y = 0;
		x++;
	}
}

int main()
{
	int x = 0;
	int y = 0;
	int map_size = 4;
	char **map;

	map = (char **)malloc(sizeof(map) * map_size + 1);
	map[map_size] = 0;
	while(y < map_size)
		map[y++] = (char *)malloc(sizeof(char) * map_size + 1);
	y = 0;
	while(x < map_size)
	{
		while (y < map_size)
		map[x][y++] = '.';
		y = 0;
		x++;
	}
	x = 0;
	y = 0;
	print_map(map, x, y, map_size);

	return 0;
}