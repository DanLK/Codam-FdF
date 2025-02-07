/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   practice.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/06 16:04:11 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/07 12:37:20 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define WIDTH 1024
#define HEIGHT 1024

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static void	a_hook(void *param)
{
	const mlx_t	*mlx;

	mlx = param;
	printf("Width: %d | Height: %d\n", mlx->width, mlx->height);
}

static void ft_key_hook(mlx_key_data_t keydata, void *param)
{
	const mlx_t	*mlx;

	mlx = param;
	if (keydata.action == MLX_PRESS)
		printf("%c\n", keydata.key);
	if (keydata.action == MLX_REPEAT)
		printf("You are holding the key: %c\n", keydata.key);
	if (keydata.key == MLX_KEY_SPACE)
		printf("Width: %d | Height: %d\n", mlx->width, mlx->height);
}

int32_t	main(void)
{
	mlx_t*	mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "My First Window!", true);
	if (!mlx)
		ft_error();
	mlx_key_hook(mlx, &ft_key_hook, NULL);
	mlx_loop_hook(mlx, a_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}