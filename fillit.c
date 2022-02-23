/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skesuma <skesuma@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:13:42 by skesuma           #+#    #+#             */
/*   Updated: 2022/02/21 12:07:04 by skesuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (write(1, "Usage: ./fillit input_file\n", 27));
	if (lets_check(argv) != 0)
		return (printf("invalid file\n"));
	else
		return (printf("valid file\n"));
	parse(argv);
}
