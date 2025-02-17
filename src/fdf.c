/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/06 17:39:28 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/17 12:48:47 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define HEIGHT 1024
#define WIDTH 1536

int	main(int argc, char **argv)
{
	int	fd;
	int	size;
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
	if (!validate_map(argv[1], &size))
	{
		ft_printf("Invalid map\n");
		return (EXIT_FAILURE);
	}
	env = init_env(fd, size);
	paint_map(env);
	clear_environment(env);
	return (EXIT_SUCCESS);
}
