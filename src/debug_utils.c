/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/23 19:06:22 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/23 19:07:51 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	print_3d_point(t_3dpoint p)
{
	ft_printf("(%d, %d, %d)\n", p.x, p.y, p.z);
}

void	print_2d_point(t_2dpoint p)
{
	printf("(%f, %f) -- %d\n", p.x, p.y, p.color);
}

void	print_pixel(t_pixel p)
{
	ft_printf("(%d, %d)\n", p.x, p.y);
}
