/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lines.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/17 17:17:12 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/18 17:58:01 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdio.h>

// void	dda(t_env env, t_pixel *p0, t_pixel *p1)
// {
// 	double	dx;
// 	double	dy;
// 	int		steps;
// 	double	x;
// 	double	y;

// 	if (!p0 || !p1)
// 		return ;
// 	dx = p1->x - p0->x;
// 	dy = p1->y - p0->y;
// 	if (abs((int)dx) > abs((int)dy))
// 		steps = abs((int)dx);
// 	else
// 		steps = abs((int)dy);
// 	x = p0->x;
// 	y = p0->y;
// 	while (steps > 0)
// 	{
// 		mlx_put_pixel(env.img, x, y, 0xFFFFFFFF);
// 		x += dx / steps;
// 		y += dy / steps;
// 		steps--;
// 	}
// }

/* Bresenham*/
void	draw_line(t_env env, t_pixel *p0, t_pixel *p1)
{
	double	dx;
	double	dy;
	double	err;
	double	sx;
	double	sy;
	double	x;
	double	y;

	x = p0->x;
	y = p0->y;
	dx = fabs(p1->x - p0->x);
	dy = - fabs(p1->y - p0->y);
	if (p0->x < p1->x)
		sx = 1;
	else
		sx = -1;
	if (p0->y < p1->y)
		sy = 1;
	else
		sy = -1;
	err = dx + dy;
	while (true)
	{
		mlx_put_pixel(env.img, x, y, 0xFFFFFFFF);
		if (err * 10 >= dy)
		{
			if (sx * x >= p1->x)
				break ;
			err += dy;
			x += sx;
		}
		if (err * 10 <= dx)
		{
			if (sy * y >= p1->y)
				break ;
			err += dx;
			y += sy;
		}
	}
}

void	dl(t_env env, t_pixel *p0, t_pixel *p1)
{
	if (!p0 || !p1)
	{
		ft_printf("One of the points is null\n");
		return ;
	}
	if (p0->x > p1->x && p0->y > p1->y)
		draw_line(env, p1, p0);
	else
		draw_line(env, p0, p1);
}

void	draw_horizontal(t_env env)
{
	int	i;
	int	j;

	i = 0;
	while (i < env.size_y)
	{
		j = 0;
		while (j < env.size_x - 1)
		{
		// dl(env, scale(env.points[j + i * env.size_y], env), scale(env.points[j + i * env.size_y + 1], env));
			ft_printf("(%d, %d)\n", j + i * env.size_y, j + i * env.size_y + 1);
			j++;
		}
		i++;
	}
}

void	draw_vertical(t_env env)
{
	int	i;
	int	j;

	i = 0;
	while (i < env.size_y -1)
	{
		j = 0;
		while (j < env.size_x)
		{
			dl(env, scale(env.points[j + i * env.size_x], env),
				scale(env.points[j + (i + 1) * env.size_x], env));
			j++;
		}
		i++;
	}
}
