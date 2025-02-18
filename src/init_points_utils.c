/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_points_utils.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/11 18:35:45 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/18 16:31:57 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

/* Degrees to radians*/
double	dtr(double alpha)
{
	return (alpha * (M_PI / 180));
}

void	get_x_minmax(t_pixel **points, int size, double *min, double *max)
{
	int 		i;
	t_pixel	*p;

	if (!points)
		return ;
	i = 0;
	*min = 0;
	*max = 0;
	while (i < size)
	{
		p = points[i];
		if (p->x < *min)
			*min = p->x;
		if (p->x > *max)
			*max = p->x;
		i++;
	}
}

void	get_y_minmax(t_pixel **points, int size, double *min, double *max)
{
	int 		i;
	t_pixel	*p;

	if (!points)
		return ;
	i = 0;
	*min = 0;
	*max = 0;
	while (i < size)
	{
		p = points[i];
		if (p->y < *min)
			*min = p->y;
		if (p->y > *max)
			*max = p->y;
		i++;
	}
}

int	get_color(char *str)
{
	int	color;

	if (!str)
		return (-1);
	color = 0xFFFFFFFF;
	while (ft_isdigit(*str))
		str++;
	if (*str == ',')
		str++;
	else
		return (color);
	if (*str == '0')
		str++;
	else
		return (color);
	if (*str == 'x')
		str++;
	else
		return (color);
	return (ft_atoi_base(str, "0123456789abcdef"));
}

t_env	init_env(int fd, int size_x, int size_y)
{
	t_env	env;

	env.size_x = size_x;
	env.size_y = size_y;
	env.map_coord = get_points_3d(fd, size_x * size_y);
	env.points = iso_transform(env.map_coord, 30, size_x * size_y);
	get_x_minmax(env.points, size_x * size_y, &env.x_min, &env.x_max);
	get_y_minmax(env.points, size_x * size_y, &env.y_min, &env.y_max);
	env.width = 2048;
	env.height = 1024 + 521;
	return (env);
}
