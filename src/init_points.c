/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_points.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/07 15:39:26 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/22 17:53:02 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

t_3dpoint	*new_3dpoint(int x, int y, int z, uint32_t color)
{
	t_3dpoint	*p;

	p = (t_3dpoint *)malloc(sizeof(t_3dpoint));
	if (!p)
		return (NULL);
	p->x = x;
	p->y = y;
	p->z = z;
	p->color = color;
	return (p);
}

t_pixel	*new_pixel(double x, double y, uint32_t color)
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

t_3dpoint	**get_points_3d(int fd, int size)
{
	t_3dpoint	**points;
	int			coord_x;
	int			coord_y;
	char		**line;
	int			i;

	points = (t_3dpoint **)malloc(size * sizeof(t_3dpoint *));
	if (!points)
		return (NULL);
	line = get_map_line(fd);
	coord_y = 0;
	i = 0;
	while (line)
	{
		coord_x = 0;
		while (line[coord_x])
		{
			points[i++] = new_3dpoint(coord_x, coord_y, ft_atoi(line[coord_x]),
					get_color(line[coord_x]));
			coord_x++;
		}
		coord_y++;
		clear_array(line);
		line = get_map_line(fd);
	}
	return (clear_array(line), points);
}

char	**get_map_line(int fd)
{
	char	*line;
	char	**coord_line;

	line = get_next_line(fd);
	coord_line = ft_split(line, ' ');
	free(line);
	return (coord_line);
}

t_pixel	**iso_transform(t_3dpoint **arr_3d, double a, int size)
{
	t_pixel		**points;
	t_3dpoint	*p;
	int			i;

	if (!arr_3d)
		return (NULL);
	points = (t_pixel **)malloc(size * sizeof(t_pixel *));
	if (!points)
		return (NULL);
	i = 0;
	while (i < size)
	{
		p = arr_3d[i];
		points[i] = new_pixel((p->x * cos(dtr(a))) + (p->y * cos(dtr(a) + 2))
				+ (p->z * cos(dtr(a) - 2)),
				p->x * sin(dtr(a)) + p->y * sin(dtr(a) + 2)
				+ p->z * sin(dtr(a) - 2), p->color);
		i++;
	}
	return (points);
}
