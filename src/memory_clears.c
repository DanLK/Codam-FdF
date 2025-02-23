/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memory_clears.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/07 15:18:54 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/23 17:50:11 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_array(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	clear_3d_grid(t_3dpoint **points, int size)
{
	t_3dpoint	*p;
	int			i;

	if (!points)
		return ;
	i = 0;
	p = points[i];
	while (i < size)
	{
		free(p);
		i++;
		if (i == size)
			break ;
		p = points[i];
	}
	free(points);
}

void	clear_2d_grid(t_2dpoint **points, int size)
{
	t_2dpoint	*p;
	int			i;

	if (!points)
		return ;
	i = 0;
	p = points[i];
	while (i < size)
	{
		free(p);
		i++;
		if (i == size)
			break ;
		p = points[i];
	}
	free(points);
}

void	clear_pixel_grid(t_pixel **pixels, int size)
{
	t_pixel	*p;
	int		i;

	if (!pixels)
		return ;
	i = 0;
	p = pixels[i];
	while (i < size)
	{
		free(p);
		i++;
		if (i == size)
			break ;
		p = pixels[i];
	}
	free(pixels);
}

void	clear_environment(t_env env)
{
	clear_3d_grid(env.map_coord, env.size_x * env.size_y);
	clear_2d_grid(env.points, env.size_x * env.size_y);
	clear_pixel_grid(env.pixels, env.size_x * env.size_y);
}
