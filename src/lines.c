/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lines.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/17 17:17:12 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/17 17:27:53 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dda(t_env env, t_pixel *p0, t_pixel *p1)
{
	double	dx;
	double	dy;
	int		steps;

	if (!p0 || !p1)
		return ;
	dx = p1->x - p0->x;
	dy = p1->y - p0->y;
	if (abs((int)dx) > abs((int)dy))
		steps = abs((int)dx);
	else
		abs((int)dy);

}