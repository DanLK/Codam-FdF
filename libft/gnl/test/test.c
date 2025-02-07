/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/02 17:56:17 by dloustal      #+#    #+#                 */
/*   Updated: 2025/01/03 12:02:33 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int	fd = open("test.txt", O_RDONLY);

	char	*result;
	int		index;

	index = 1;
	while ((result = get_next_line(fd)))
	{
		printf("%d: %s", index, result);
		free(result);
		index++;
	}

	if (close(fd) == -1)
		printf("Closing file error\n");
	return (0);
}