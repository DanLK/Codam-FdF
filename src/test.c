/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/07 14:06:13 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/14 15:00:46 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

int	main(int argc, char **argv)
{
	int	fd;
	int	size_x;
	int	size_y;
	t_3dpoint	**points;
	t_pixel	**arr_2d;

	if (argc != 2)
	{
		ft_printf("Must pass exactly one argument\n");
		return (EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 3)
	{
		perror("Error reading the file");
		exit(EXIT_FAILURE);
	}
	if (!validate_map(argv[1], &size_x, &size_y))
	{
		ft_printf("Invalid map\n");
		exit(EXIT_FAILURE);
	}
	ft_printf("Number of points: %d\n", size_x * size_y);
	points = get_points_3d(fd, size_x * size_y);
	print_3d_array(points, size_x * size_y);
	arr_2d = transform_points(points, 30, size_x * size_y);
	ft_printf("\n");
	print_2d_array(arr_2d, size_x * size_y);
	clear_2d_grid(arr_2d, size_x * size_y);
	ft_printf("\n");
	return (0);
}