/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/06 17:46:40 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/07 15:29:53 by dloustal      ########   odam.nl         */
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

int	validate_map(char *file_name)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(file_name, O_RDONLY);
	if (fd < 3)
	{
		perror("Error reading map");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	len = num_arguments(line);
	while (line)
	{
		if (num_arguments(line) != len)
		{
			ft_printf("The map is not rectangular\n");
			return (close(fd), free(line), 0);
		}
		len = num_arguments(line);
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), free(line), 1);
}
