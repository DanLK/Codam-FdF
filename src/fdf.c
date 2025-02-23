/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/06 17:39:28 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/23 18:24:10 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define WIDTH 2048
#define HEIGHT 1536

int	main(int argc, char **argv)
{
	int		fd;
	int		size_x;
	int		size_y;
	t_env	env;

	if (argc != 2)
	{
		printf("Must pass an argument\n");
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
		return (EXIT_FAILURE);
	}
	env = init_env(fd, size_x, size_y);
	paint_map(env);
	clear_environment(env);
	return (EXIT_SUCCESS);
}
