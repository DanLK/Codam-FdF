/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/06 17:46:40 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/14 17:30:04 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


int num_arguments(char *line)
{
	int		i;
	char	**points;

	i = 0;
	points = ft_split(line, ' ');
	while (points[i])
		i++;
	clear_array(points);
	return (i);
}

int	validate_map(char *file_name, int *size)
{
	int		fd;
	char	*line;
	int		line_size;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		perror("Error reading map");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	line_size = num_arguments(line);
	*size = 0;
	while (line)
	{
		if (num_arguments(line) != line_size)
		{
			ft_printf("The map is not rectangular\n");
			return (close(fd), free(line), 0);
		}
		free(line);
		line = get_next_line(fd);
		*size += line_size;
	}
	return (close(fd), free(line), 1);
}
