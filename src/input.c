/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/06 17:46:40 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/21 14:06:37 by dloustal      ########   odam.nl         */
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

static int	validate_extension(char *file_name)
{
	int	len;
	int	valid;
	
	len = ft_strlen(file_name);
	valid = file_name[len - 4] == '.' && file_name[len - 3] == 'f'
			&& file_name[len - 2] == 'd' && file_name[len - 1] == 'f';
	if (!valid)
	{
		ft_printf("File extension invalid\n");
		exit(EXIT_FAILURE);
	}
	return (valid);
}


int	validate_map(char *file_name, int *size_x, int *size_y)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0 || !validate_extension(file_name))
	{
		perror("Error reading map");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	*size_x = num_arguments(line);
	*size_y = 0;
	while (line)
	{
		if (num_arguments(line) != *size_x)
		{
			ft_printf("The map is not rectangular\n");
			return (close(fd), free(line), 0);
		}
		free(line);
		line = get_next_line(fd);
		*size_y += 1;
	}
	return (close(fd), free(line), 1);
}
