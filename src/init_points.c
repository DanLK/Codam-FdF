/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_points.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/07 15:39:26 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/24 11:14:27 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
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

t_2dpoint	*new_2dpoint(double x, double y, uint32_t color)
{
	t_2dpoint	*p;

	p = (t_2dpoint *)malloc(sizeof(t_2dpoint));
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
	int			coords[2];
	char		**line;
	int			i;

	points = (t_3dpoint **)malloc(size * sizeof(t_3dpoint *));
	if (!points)
		return (NULL);
	line = get_map_line(fd);
	coords[1] = 0;
	i = 0;
	while (line)
	{
		coords[0] = -1;
		while (line[++coords[0]])
		{
			if (ft_strncmp(line[coords[0]], "\n", 1) != 0)
				points[i++] = new_3dpoint(coords[0], coords[1],
						ft_atoi(line[coords[0]]), get_color(line[coords[0]]));
		}
		coords[1]++;
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

t_2dpoint	**iso_transform(t_3dpoint **arr_3d, double a, int size)
{
	t_2dpoint	**points;
	t_3dpoint	*p;
	int			i;

	if (!arr_3d)
		return (NULL);
	points = (t_2dpoint **)malloc(size * sizeof(t_2dpoint *));
	if (!points)
		return (NULL);
	i = 0;
	while (i < size)
	{
		p = arr_3d[i];
		points[i] = new_2dpoint((p->x * cos(dtr(a))) + (p->y * cos(dtr(a) + 2))
				+ (p->z * cos(dtr(a) - 2)),
				p->x * sin(dtr(a)) + p->y * sin(dtr(a) + 2)
				+ p->z * sin(dtr(a) - 2), p->color);
		i++;
	}
	return (points);
}
