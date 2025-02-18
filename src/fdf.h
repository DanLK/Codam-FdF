/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/06 17:39:48 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/18 17:46:53 by dloustal      ########   odam.nl         */
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
	t_3dpoint	**map_coord;
	t_pixel		**points;
	int			size_x;
	int			size_y;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	int			height;
	int			width;
	mlx_image_t	*img;
}		t_env;

// Input validation
int			validate_map(char *file_name, int *size_x, int *size_y);
int			num_arguments(char *line);

// Init points
t_3dpoint	*new_3dpoint(int x, int y, int z);
t_pixel		*new_pixel(double x, double y);
char		**get_map_line(int fd);
t_3dpoint	**get_points_3d(int fd, int size);
t_pixel		**iso_transform(t_3dpoint **arr_3d, double a, int size);

// Init points utils
double		dtr(double alpha);
void		get_x_minmax(t_pixel **points, int size, double *min, double *max);
void		get_y_minmax(t_pixel **points, int size, double *min, double *max);
int			get_color(char *str);
t_env		init_env(int fd, int size_x, int size_y);

// Scale points
t_pixel 	*scale(t_pixel *point, t_env env);

// Paint map
void		paint_map(t_env env);

// Draw lines
// void		dda(t_env env, t_pixel *p0, t_pixel *p1);
void		draw_line(t_env env, t_pixel *p0, t_pixel *p1);
void		dl(t_env env, t_pixel *p0, t_pixel *p1);
void		draw_horizontal(t_env env);
void		draw_vertical(t_env env);

// Memory clears
void		clear_array(char **args);
void		clear_3d_grid(t_3dpoint **points, int size);
void		clear_2d_grid(t_pixel **points, int size);
void		clear_environment(t_env env);

// Debug
void		print_3d_point(t_3dpoint p);
void		print_2d_point(t_pixel p);
void		print_3d_array(t_3dpoint **p, int size);
void		print_2d_array(t_pixel **p, int size);
void		print_pixels(t_pixel **p, int size);
