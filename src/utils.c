/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/23 19:03:23 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/23 20:09:34 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

int	is_sign(char c)
{
	return (c == '-' || c == '+');
}

/* Degrees to radians*/
double	dtr(double alpha)
{
	return (alpha * (M_PI / 180));
}

int	rounded(double n)
{
	return ((int)(n + 0.5));
}

/* Scales and centers the points */
t_pixel	*scale(t_2dpoint *point, t_env env)
{
	t_pixel	*new;
	double	sf;
	double	offx;
	double	offy;

	if (!point)
		return (NULL);
	sf = fmin((env.width - 1) / (env.x_max - env.x_min), (env.height - 1)
			/ (env.y_max - env.y_min));
	offx = ((env.width - 1) - (env.x_max - env.x_min) * sf) / 2;
	offy = ((env.height - 1) - (env.y_max - env.y_min) * sf) / 2;
	new = new_pixel(rounded((point->x - env.x_min) * sf + offx),
			rounded((point->y - env.y_min) * sf + offy), point->color);
	if (!new)
		return (NULL);
	return (new);
}
