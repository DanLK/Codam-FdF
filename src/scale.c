/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scale.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/14 15:26:21 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/22 17:50:26 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

/* Scales and centers the points */
t_pixel	*scale(t_pixel *point, t_env env)
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
	new = new_pixel((point->x - env.x_min) * sf + offx, (point->y - env.y_min)
			* sf + offy, point->color);
	if (!new)
		return (NULL);
	return (new);
}
