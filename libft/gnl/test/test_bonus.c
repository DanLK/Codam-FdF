/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/03 11:25:57 by dloustal      #+#    #+#                 */
/*   Updated: 2025/01/03 11:57:48 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int	fd1 = open("test.txt", O_RDONLY);
	int	fd2 = open("hipster.txt", O_RDONLY);

	char	*result;
	int		index;
	int		fd;
	
	fd = fd1;
	index = 1;

	while ((result = get_next_line(fd)))
	{
		printf("%d: %s", index, result);
		if (index % 2 == 0)
			fd = fd1;
		else
			fd = fd2;
		index++;
		free(result);
	}

	if (close(fd1) == -1 || close(fd2) == -1)
		printf("Closing file error\n");
		
	return (0);
}