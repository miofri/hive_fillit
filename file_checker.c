/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skesuma <skesuma@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:36:00 by skesuma           #+#    #+#             */
/*   Updated: 2022/02/04 14:06:44 by skesuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	format_checker(int ret, char *buf)
{
	int	i;

	buf[ret] = '\0';
	if ((ret + 1) % 21 != 0 || ret == 0 || ret == -1 || ret > 545)
		return (write(1, "Invalid no. of lines or read failed\n", 36));
	i = 0;
	if (buf[i] != '.' && buf[i] != '#')
		return (write(1, "Invalid block\n", 14));
	while (buf[++i] != '\0')
	{
		if (i % 21 == 0 && buf[i - 1] != '\n')
			return (write(1, "Invalid line break\n", 20));
		else if (i % 21 % 5 == 0 && buf[i - 1] != '\n') //\n at the end of each line
			return (write(1, "Invalid in-grid line break\n", 27));
		else if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			return (write(1, "Invalid block\n", 14));
	}
	return (i);
}

// int	touching(int i, char *buf, int x, int y) //checks 21 lines at a time
// {
// 	while (++y < i)
// 	{
// 		if (buf[y] == '#')
// 		{
// 			while (++x < 4)
// 			{
// 				if (buf[y + 1] == '#')
// 					y += 1;
// 				else if (buf[y + 5] == '#')
// 					y += 5;
// 				else if (buf[y + 1] == '#' && buf[y - 1] == '#')
// 				{
// 					y += 1;
// 					x += 2;
// 				}
// 				else if (buf[y - 1] == '#')
// 					y++;
// 				else
// 					return (write(1, "invalid tetros", 1));
// 			}
// 		}
// 		else if ((y + 1) % 21 == 0 && x != 4)
// 			return (-1);
// 	}
// 	return (0);
// }

int	touching(int touched2, char *buf, int touched1, int y) //checks 21 lines at a time
{
	while (++y < 21)
	{
		if (buf[y] == '#')
		{
			if (buf[y + 5] == '#' && buf[y - 5] == '#')
				touched2++;
			else if (buf[y + 1] == '#' && buf[y - 1] == '#')
				touched2++;
			else if ((buf[y + 1] == '#' || buf[y - 1] == '#') && (buf[y + 5] == '#' || buf[y - 5] == '#'))
				touched2++;
			else if (buf[y + 1]  == '#'|| buf[y - 1]  == '#' ||buf [y + 5]  == '#' || buf[y - 5]  == '#')
				touched1++;
			else
				return (write(1, "invalid tetros\n", 15));
		}
	}
	if (touched2 != 2 && touched1 != 2)
		return (write(1, "invalid tetros\n", 15));
	return (0);
}

int block_checker(int i, char *buf, int fd, int ret)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y <= i)
	{
		if (buf[y] == '#')
			x++;
		if ((y + 1) % 21 == 0 && x != 4)
		{
			ft_putstr("invalid number of # at line\n");
			ft_putnbr(y);
			return (-1);
		}
		else if ((y + 1) % 21 == 0 && x == 4)
			x = 0;
		y++;
	}
	y = -1;
	i = 0;
	while (read(fd, buf, 21) && ret != -1 )
		ret = touching(i, buf, x, y);
	return (ret);
}

int	main(int argc, char *argv[])
{
	int		fd;
	int		check;
	char	buf[546];
	int		ret;

	if (argc != 2)
		return (write(1, "Usage: ./fillit input_file", 26));
	fd = open(argv[1], O_RDONLY);
	ret = read(fd, buf, 546);
	if (fd == -1 || ret == -1)
			return (-1);
	check = format_checker(ret, buf);
	if (check == -1)
		return (-1);
	close(fd);
	ret = 0;
	fd = open(argv[1], O_RDONLY);
	check = block_checker(check, buf, fd, ret);
	if (check == -1)
		return (write(1, "invalid tetro\n", 14));
}