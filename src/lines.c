/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lines.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/17 17:17:12 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/23 19:35:39 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdio.h>

int	rounded(double n)
{
	return ((int)(n + 0.5));
}

/* Bresenham*/
void	draw_line(t_env env, t_pixel *p0, t_pixel *p1)
{
	int		err;
	t_pixel	p;

	p.x = p0->x;
	p.y = p0->y;
	err = abs(p1->x - p0->x) - abs(p1->y - p0->y);
	while (true)
	{
		mlx_put_pixel(env.img, p.x, p.y, get_mid_color(*p0, p, *p1));
		if (err * 2 > -abs(p1->y - p0->y))
		{
			if (p.x == p1->x)
				break ;
			err -= abs(p1->y - p0->y);
			p.x += (p0->x < p1->x);
			p.x -= (p0->x > p1->x);
		}
		if (err * 2 < abs(p1->x - p0->x))
		{
			if (p.y == p1->y)
				break ;
			err += abs(p1->x - p0->x);
			p.y += (p0->y < p1->y);
			p.y -= (p0->y > p1->y);
		}
	}
}

void	draw_horizontal(t_env env)
{
	int		i;
	int		j;
	t_pixel	*p0;
	t_pixel	*p1;

	i = 0;
	while (i < env.size_y)
	{
		j = 0;
		while (j < env.size_x - 1)
		{
			p0 = env.pixels[j + i * env.size_x];
			p1 = env.pixels[j + i * env.size_x + 1];
			draw_line(env, p0, p1);
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
			p0 = env.pixels[j + i * env.size_x];
			p1 = env.pixels[j + (i + 1) * env.size_x];
			draw_line(env, p0, p1);
			j++;
		}
		i++;
	}
}
