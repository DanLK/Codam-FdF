/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/06 17:39:48 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/07 16:54:01 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include "../libft/libft.h"

typedef struct s_3dpoint
{
	int	x;
	int	y;
	int	z;
}		t_3dpoint;


// Input handling
int	validate_map(char *file_name, int *size_x, int *size_y);
int num_arguments(char *line);

// Memory clears
void	clear_array(char **args);

// Init points
int	*new_3dcoord(int x, int y, int z);

// Debug
void	print_3d_point(int *p);
