/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/07 14:06:13 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/07 15:32:06 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		map_valid;

	if (argc != 2)
	{
		ft_printf("Must pass exactly one argument\n");
		return (EXIT_FAILURE);
	}
	map_valid = validate_map(argv[1]);
	ft_printf("%d\n", map_valid);
	return (0);
}