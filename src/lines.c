/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lines.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/17 17:17:12 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/21 16:54:07 by dloustal      ########   odam.nl         */
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
	int	err;
	t_pixel	p;

	p.x = rounded(p0->x);
	p.y = rounded(p0->y);
	err = abs(rounded(p1->x) - rounded(p0->x)) -
	abs(rounded(p1->y) - rounded(p0->y));
	while (true)
	{
		mlx_put_pixel(env.img, p.x, p.y, 0xFFFFFFFF);
		if (err * 2 > - abs(rounded(p1->y) - rounded(p0->y)))
		{
			if (p.x == rounded(p1->x))
				break ;
			err -= abs(rounded(p1->y) - rounded(p0->y));
			p.x += (rounded(p0->x) < rounded(p1->x));
			p.x -= (rounded(p0->x) > rounded(p1->x));
		}
		if (err * 2 < abs(rounded(p1->x) - rounded(p0->x)))
		{
			if (p.y == rounded(p1->y))
				break ;
			err += abs(rounded(p1->x) - rounded(p0->x));
			p.y += (rounded(p0->y) < rounded(p1->y));
			p.y -= (rounded(p0->y) > rounded(p1->y));
		}
	}
}

void	dl(t_env env, t_pixel *p0, t_pixel *p1)
{
	if (!p0 || !p1)
		return ;
	// if (p0->y < p1->y)
	draw_line(env, p0, p1);
	// else
	// 	draw_line(env, p1, p0);
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
