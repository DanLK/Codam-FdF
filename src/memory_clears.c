/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memory_clears.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/07 15:18:54 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/07 15:20:42 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_array(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}