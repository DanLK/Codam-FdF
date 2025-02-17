/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   paint.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/17 12:34:23 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/17 14:32:07 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void graphics_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	paint_map(t_env env)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			i;
	t_pixel		*pixel;

	mlx = mlx_init(env.width, env.height, "FdF", true);
	if (!mlx)
		graphics_error();
	img = mlx_new_image(mlx, env.width, env.height);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		graphics_error();
	i = 0;
	while (i < env.size)
	{
		pixel = scale(env.points[i], env);
		mlx_put_pixel(img, pixel->x, pixel->y, 0xFFFFFFFF);
		free(pixel);
		i++;
	}
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
