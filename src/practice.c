/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   practice.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/06 16:04:11 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/17 14:06:09 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#define WIDTH 1024
#define HEIGHT 512

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// static void	a_hook(void *param)
// {
// 	const mlx_t	*mlx;

// 	mlx = param;
// 	printf("Width: %d | Height: %d\n", mlx->width, mlx->height);
// }

static void ft_key_hook(mlx_key_data_t keydata, void *param)
{
	const mlx_t	*mlx;

	mlx = param;
	if (keydata.action == MLX_PRESS)
		printf("%c\n", keydata.key);
	if (keydata.action == MLX_REPEAT)
		printf("You are holding the key: %c\n", keydata.key);
	// if (keydata.key == MLX_KEY_SPACE)
	// 	printf("Width: %d | Height: %d\n", mlx->width, mlx->height);
}

int32_t	main(int argc, char **argv)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			size;
	t_3dpoint	**points;
	t_pixel	**arr_2d;
	int			i = 0;
	int			fd;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;

	if (argc != 2)
	{
		ft_printf("Must pass exactly one argument\n");
		return (EXIT_FAILURE);
	}
	mlx = mlx_init(WIDTH, HEIGHT, "My First Window!", true);
	if (!mlx)
		ft_error();
	img = mlx_new_image(mlx, 1024, 1024);
	mlx_key_hook(mlx, &ft_key_hook, NULL);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	fd = open(argv[1], O_RDONLY);
	if (fd < 3)
	{
		perror("Error reading the file");
		exit(EXIT_FAILURE);
	}
	if (!validate_map(argv[1], &size))
	{
		ft_printf("Invalid map\n");
		exit(EXIT_FAILURE);
	}
	ft_printf("Number of points: %d\n", size);
	points = get_points_3d(fd, size);
	print_3d_array(points, size);
	arr_2d = iso_transform(points, 30, size);
	ft_printf("\n");
	print_2d_array(arr_2d, size);
	get_x_minmax(arr_2d, size, &x_min, &x_max);
	get_y_minmax(arr_2d, size, &y_min, &y_max);
	printf("x_min: %f    x_max: %f\n", x_min, x_max);
	printf("y_min: %f    y_max: %f\n", y_min, y_max);
	ft_printf("\nScaled points:\n");
	while (i < size)
	{
		mlx_put_pixel(img, (arr_2d[i]->x - x_min) * ((WIDTH - 1) / (x_max - x_min)), (arr_2d[i]->y - y_min) * ((HEIGHT - 1)/(y_max - y_min)), 0xFFFFFFFF);
		printf("(%f, %f)\n", (arr_2d[i]->x - x_min) * (WIDTH - 1 ) / (x_max - x_min), (arr_2d[i]->y - y_min) * ((HEIGHT - 1)/(y_max - y_min)));
		i++;
	}
	clear_2d_grid(arr_2d, size);
	clear_3d_grid(points, size);
	// mlx_loop_hook(mlx, a_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}


// int scaled_x = (x - min_x) * (width / (max_x - min_x));
// int scaled_y = (y - min_y) * (height / (max_y - min_y));
