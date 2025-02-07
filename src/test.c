/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/07 14:06:13 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/07 16:54:14 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		map_valid;
	int		size_x;
	int		size_y;
	int		*p;

	if (argc != 2)
	{
		ft_printf("Must pass exactly one argument\n");
		return (EXIT_FAILURE);
	}
	map_valid = validate_map(argv[1], &size_x, &size_y);
	ft_printf("Number of points: %d\n", size_x * size_y);
	p = new_3dcoord(1, 2, 3);
	print_3d_point(p);
	free(p);
	return (0);
}