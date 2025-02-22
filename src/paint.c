/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   paint.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/17 12:34:23 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/22 17:49:05 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void	graphics_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	paint_map(t_env env)
{
	mlx_t		*mlx;
	int			i;
	t_pixel		*pixel;

	mlx = mlx_init(env.width, env.height, "FdF", true);
	if (!mlx)
		graphics_error();
	env.img = mlx_new_image(mlx, env.width, env.height);
	if (!env.img || (mlx_image_to_window(mlx, env.img, 0, 0) < 0))
		graphics_error();
	i = 0;
	while (i < env.size_x * env.size_y)
	{
		pixel = scale(env.points[i], env);
		mlx_put_pixel(env.img, rounded(pixel->x), rounded(pixel->y),
			pixel->color);
		free(pixel);
		i++;
	}
	draw_horizontal(env);
	draw_vertical(env);
	mlx_key_hook(mlx, &esc_hook, &env);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}

void	esc_hook(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		clear_environment(*((t_env *)param));
		exit(EXIT_SUCCESS);
	}
}
