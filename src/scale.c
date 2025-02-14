/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scale.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/14 15:26:21 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/14 15:36:05 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel *scale(t_pixel *point, int w, int h)
{
	t_pixel	*new;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;

	if (!point)
		return (NULL);
	get_x_minmax
	new = new_pixel((point->x - x_min) * ((w - 1) / (x_max - x_min)),
		(point->y - y_min) * (h/(y_max - y_min)));
	if (!new)
		return (NULL);
	
}