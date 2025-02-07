/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/06 17:39:28 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/06 17:50:08 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	fd;
	if (argc != 2)
	{
		printf("Must pass an argument\n");
		return (EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	printf("%d\n", fd);
	return (EXIT_SUCCESS);
}