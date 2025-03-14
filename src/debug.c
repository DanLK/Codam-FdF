/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/07 15:55:59 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/23 19:07:42 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	print_2d_array(t_2dpoint **p, int size)
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
		print_pixel(*p[i]);
		i++;
	}
}
