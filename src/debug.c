/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/07 15:55:59 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/22 17:51:42 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	print_3d_point(t_3dpoint p)
{
	ft_printf("(%d, %d, %d)\n", p.x, p.y, p.z);
}

void	print_2d_point(t_pixel p)
{
	printf("(%f, %f) -- %d\n", p.x, p.y, p.color);
}

void	print_3d_array(t_3dpoint **p, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		print_3d_point(*p[i]);
		i++;
	}
}

void	print_2d_array(t_pixel **p, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		print_2d_point(*p[i]);
		i++;
	}
}

void	print_pixels(t_pixel **p, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("(%f, %f, %d)\n", p[i]->x, p[i]->y, p[i]->color);
		i++;
	}
}
