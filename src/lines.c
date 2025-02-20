/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lines.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/17 17:17:12 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/20 15:46:43 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdio.h>

/* Bresenham*/
void	draw_line(t_env env, t_pixel *p0, t_pixel *p1)
{
	double	err;
	double	sx;
	double	sy;
	t_pixel	p;

	p.x = p0->x;
	p.y = p0->y;
	err = fabs(p1->x - p0->x) - fabs(p1->y - p0->y);
	if (p0->x < p1->x)
		sx = 1;
	else
		sx = -1;
	if (p0->y < p1->y)
		sy = 1;
	else
		sy = -1;
	while (true)
	{
		if (p.y < p0->y)
			break ;
		mlx_put_pixel(env.img, p.x, p.y, 0xFFFFFFFF);
		if (err * 2 >= - fabs(p1->y - p0->y))
		{
			if (sx * p.x >= p1->x)
				break ;
			err += - fabs(p1->y - p0->y);
			p.x += sx;
		}
		if (err * 2 <= fabs(p1->x - p0->x))
		{
			if (sy * p.y >= p1->y)
				break ;
			err += fabs(p1->x - p0->x);
			p.y += sy;
		}
	}
}

void	dl(t_env env, t_pixel *p0, t_pixel *p1)
{
	if (!p0 || !p1)
		return ;
	if (p0->x < p1->x || p0->y < p1->y)
		draw_line(env, p0, p1);
	else
		draw_line(env, p1, p0);
}

void	draw_horizontal(t_env env)
{
	int		i;
	int		j;
	t_pixel *p0;
	t_pixel	*p1;

	i = 0;
	while (i < env.size_y)
	{
		j = 0;
		while (j < env.size_x - 1)
		{
			p0 = scale(env.points[j + i * env.size_x], env);
			p1 = scale(env.points[j + i * env.size_x + 1], env); // PROTECT!??
			dl(env, p0, p1);
			// ft_printf("(%d, %d)\n", j + i * env.size_x, j + i * env.size_x + 1);
			free(p0);
			free(p1);
			j++;
		}
		i++;
	}
}

void	draw_vertical(t_env env)
{
	int		i;
	int		j;
	t_pixel	*p0;
	t_pixel	*p1;

	i = 0;
	while (i < env.size_y -1)
	{
		j = 0;
		while (j < env.size_x)
		{
			p0 = scale(env.points[j + i * env.size_x], env);
			p1 = scale(env.points[j + (i + 1) * env.size_x], env);
			dl(env, p0, p1);
			// ft_printf("(%d, %d)\n", j + i * env.size_x, j + (i + 1) * env.size_x);
			free(p0);
			free(p1);
			j++;
		}
		i++;
	}
}
