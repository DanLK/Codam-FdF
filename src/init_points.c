/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_points.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/07 15:39:26 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/07 17:00:13 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

// t_3dpoint	*new_point(int x, int y, int z)
// {
// 	t_3dpoint	*p;

// 	p = (t_3dpoint *)malloc(sizeof(t_3dpoint));
// 	if (!p)
// 		return (NULL);
// 	p->x = x;
// 	p->y = y;
// 	p->z = z;
// 	return (p);
// }

int	*new_3dcoord(int x, int y, int z)
{
	int	*p;

	p = (int *)malloc(3 * sizeof(int));
	if (!p)
		return (NULL);
	p[0] = x;
	p[1] = y;
	p[2] = z;
	return (p);
}

int	**get_points_3d(char *file_name, int size_x, int size_y)
{
	int	**points;
	int			fd;

	if (!file_name)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd < 3)
	{
		perror("Error reading map");
		exit(EXIT_FAILURE);
	}
	points = (int **)malloc((size_x * size_y) * sizeof(int *));
	if (!points)
		return (NULL);
	
}


