/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_points_utils.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/11 18:35:45 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/23 19:09:09 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_x_minmax(t_2dpoint **pts, int size, double *min, double *max)
{
	int			i;
	t_2dpoint	*p;

	if (!pts)
		return ;
	i = 0;
	*min = 0;
	*max = 0;
	while (i < size)
	{
		p = pts[i];
		if (p->x < *min)
			*min = p->x;
		if (p->x > *max)
			*max = p->x;
		i++;
	}
}

void	get_y_minmax(t_2dpoint **pts, int size, double *min, double *max)
{
	int			i;
	t_2dpoint	*p;

	if (!pts)
		return ;
	i = 0;
	*min = 0;
	*max = 0;
	while (i < size)
	{
		p = pts[i];
		if (p->y < *min)
			*min = p->y;
		if (p->y > *max)
			*max = p->y;
		i++;
	}
}

t_pixel	*new_pixel(int x, int y, uint32_t color)
{
	t_pixel	*p;

	p = (t_pixel *)malloc(sizeof(t_pixel));
	if (!p)
		return (NULL);
	p->x = x;
	p->y = y;
	p->color = color;
	return (p);
}

t_pixel	**points_to_pixels(t_env env)
{
	t_pixel	**pixels;
	t_pixel	*p;
	int		i;

	pixels = (t_pixel **)malloc((env.size_x * env.size_y) * sizeof(t_pixel *));
	if (!pixels)
		return (NULL);
	i = 0;
	while (i < env.size_x * env.size_y)
	{
		p = scale(env.points[i], env);
		pixels[i] = new_pixel(rounded(p->x), rounded(p->y), p->color);
		free(p);
		i++;
	}
	return (pixels);
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
	env.height = 1024 + 512;
	return (env);
}
