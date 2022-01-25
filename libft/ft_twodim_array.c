/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twodim_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skesuma <skesuma@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 22:07:36 by skesuma           #+#    #+#             */
/*   Updated: 2022/01/25 22:25:04 by skesuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**twodim_array(int size, char **ptr)
{
	int	y;

	y = 0;
	ptr = (char **)malloc(sizeof(ptr) * (size + 1));
	while (y < size)
	{
		ptr[y] = (char *)malloc(sizeof(char) * (size + 1));
		ptr[y++][size] = '\0';
	}
	return(ptr);
}