/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memory_clears.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/07 15:18:54 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/14 14:17:49 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_array(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	clear_3d_grid(t_3dpoint **points, int size)
{
	t_3dpoint	*p;
	int			i;

	if (!points)
		return ;
	i = 0;
	p = points[i];
	while (i < size)
	{
		free(p);
		i++;
		if (i == size)
			break ;
		p = points[i];
	}
	free(points);
}

void	clear_2d_grid(t_pixel **points, int size)
{
	t_pixel	*p;
	int			i;

	if (!points)
		return ;
	i = 0;
	p = points[i];
	while (i < size)
	{
		free(p);
		i++;
		if (i == size)
			break ;
		p = points[i];
	}
	free(points);
}
