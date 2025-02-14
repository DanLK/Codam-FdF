/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/06 17:39:48 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/14 14:59:49 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include "../libft/libft.h"

typedef struct s_3dpoint
{
	int	x;
	int	y;
	int	z;
	int	color;
}		t_3dpoint;

typedef struct s_pixel
{
	double	x;
	double	y;
	int		color;
}		t_pixel;

typedef struct	s_env
{
	t_pixel	**points;
	int			size;
}		t_env;

// Input handling
int			validate_map(char *file_name, int *size_x, int *size_y);
int			num_arguments(char *line);

// Memory clears
void		clear_array(char **args);
void		clear_3d_grid(t_3dpoint **points, int size);
void		clear_2d_grid(t_pixel **points, int size);

// Init points
t_3dpoint	*new_3dpoint(int x, int y, int z);
t_pixel		*new_pixel(double x, double y);
char		**get_map_line(int fd);
t_3dpoint	**get_points_3d(int fd, int size);
t_pixel	**transform_points(t_3dpoint **arr_3d, double a, int size);



// Init points utils
double		dtr(double alpha);
void		get_x_minmax(t_pixel **points, int size, double *min, double *max);
void		get_y_minmax(t_pixel **points, int size, double *min, double *max);
int			get_color(char *str);

// Debug
void		print_3d_point(t_3dpoint p);
void		print_2d_point(t_pixel p);
void		print_3d_array(t_3dpoint **p, int size);
void		print_2d_array(t_pixel **p, int size);
void		print_pixels(t_pixel **p, int size);
