/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/06 17:39:48 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/23 20:09:46 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include "../libft/libft.h"

typedef struct s_3dpoint
{
	int			x;
	int			y;
	int			z;
	uint32_t	color;
}		t_3dpoint;

typedef struct s_2dpoint
{
	double			x;
	double			y;
	uint32_t		color;
}		t_2dpoint;

typedef struct s_pixel
{
	int			x;
	int			y;
	uint32_t	color;
}		t_pixel;

typedef struct s_env
{
	t_3dpoint	**map_coord;
	t_2dpoint	**points;
	t_pixel		**pixels;
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
t_3dpoint	*new_3dpoint(int x, int y, int z, uint32_t color);
t_2dpoint	*new_2dpoint(double x, double y, uint32_t color);
char		**get_map_line(int fd);
t_3dpoint	**get_points_3d(int fd, int size);
t_2dpoint	**iso_transform(t_3dpoint **arr_3d, double a, int size);

// Init points utils
double		dtr(double alpha);
void		get_x_minmax(t_2dpoint **pts, int size, double *min, double *max);
void		get_y_minmax(t_2dpoint **pts, int size, double *min, double *max);
t_env		init_env(int fd, int size_x, int size_y);
t_pixel		*new_pixel(int x, int y, uint32_t color);
t_pixel		**points_to_pixels(t_env env);

// Paint map
void		paint_map(t_env env);
void		esc_hook(mlx_key_data_t keydata, void *param);

// Draw lines
void		draw_line(t_env env, t_pixel *p0, t_pixel *p1);
void		draw_horizontal(t_env env);
void		draw_vertical(t_env env);
void		draw_grid(t_env env);

//Color
uint32_t	get_color(char *str);
uint32_t	str_to_color(char *str);
uint32_t	get_color_component(char *str, int index);
char		*str_to_upper(char *str);
uint32_t	get_mid_color(t_pixel start, t_pixel mid, t_pixel end);

//Color Utils
uint32_t	get_r(uint32_t rgba);
uint32_t	get_g(uint32_t rgba);
uint32_t	get_b(uint32_t rgba);
uint32_t	get_a(uint32_t rgba);
double		get_ratio(t_pixel start, t_pixel mid, t_pixel end);

//Utils
int			is_sign(char c);
double		dtr(double alpha);
int			rounded(double n);
t_pixel		*scale(t_2dpoint *point, t_env env);

// Memory clears
void		clear_array(char **args);
void		clear_3d_grid(t_3dpoint **points, int size);
void		clear_2d_grid(t_2dpoint **points, int size);
void		clear_pixel_grid(t_pixel **pixels, int size);
void		clear_environment(t_env env);

// Debug Utils
void		print_3d_point(t_3dpoint p);
void		print_2d_point(t_2dpoint p);
void		print_pixel(t_pixel p);

// Debug
void		print_3d_array(t_3dpoint **p, int size);
void		print_2d_array(t_2dpoint **p, int size);
void		print_pixels(t_pixel **p, int size);
