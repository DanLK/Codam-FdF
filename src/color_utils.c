/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/23 14:58:28 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/23 18:44:09 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

uint32_t	get_r(uint32_t rgba)
{
	return ((rgba >> 24) & 0xFF);
}

uint32_t	get_g(uint32_t rgba)
{
	return ((rgba >> 16) & 0xFF);
}

uint32_t	get_b(uint32_t rgba)
{
	return ((rgba >> 8) & 0xFF);
}

uint32_t	get_a(uint32_t rgba)
{
	return (rgba & 0xFF);
}

double	get_ratio(t_pixel start, t_pixel mid, t_pixel end)
{
	double	ratio;

	if (start.x != end.x)
		ratio = (double)(mid.x - start.x) / (double)(end.x - start.x);
	else
		ratio = (double)(mid.y - start.y) / (double)(end.y - start.y);
	return (ratio);
}
