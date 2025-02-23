/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/22 14:03:05 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/23 19:24:53 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

uint32_t	get_color(char *str)
{
	uint32_t	color;
	char		*s;

	if (!str)
		return (-1);
	s = str;
	while (ft_isdigit(*s) || is_sign(*s))
		s++;
	if (!*s || *s == '\n')
		s = "FFFFFFFF";
	else if (*s == ',')
	{
		s++;
		if (*s == '0')
			s++;
		if (*s == 'x')
			s++;
		if (!*s)
			return (-1);
	}
	s = str_to_upper(s);
	color = str_to_color(s);
	free(s);
	return (color);
}

/* Assuming the string lenght is 6 or 8*/
uint32_t	str_to_color(char *str)
{
	int	r;
	int	g;
	int	b;
	int	a;

	r = 0;
	g = 0;
	a = 255;
	if (ft_strlen(str) <= 2)
		b = get_color_component(str, 0);
	else if (ft_strlen(str) <= 4)
	{
		g = get_color_component(str, 0);
		b = get_color_component(str, 2);
	}
	else
	{
		r = get_color_component(str, 0);
		g = get_color_component(str, 2);
		b = get_color_component(str, 4);
	}
	if (ft_strlen(str) == 8)
		a = get_color_component(str, 6);
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	get_color_component(char *str, int index)
{
	char		*color_s;
	uint32_t	color_nr;

	if (!str)
		return (-1);
	color_s = ft_substr(str, index, 2);
	if (!color_s)
		return (-1);
	color_nr = ft_atoi_base(color_s, "0123456789ABCDEF");
	free(color_s);
	return (color_nr);
}

char	*str_to_upper(char *str)
{
	int		len;
	int		i;
	char	*upper;

	if (!str)
		return (NULL);
	i = 0;
	len = ft_strlen(str);
	upper = ft_strdup(str);
	if (!upper)
		return (NULL);
	while (i < len)
	{
		upper[i] = ft_toupper(str[i]);
		i++;
	}
	return (upper);
}

uint32_t	get_mid_color(t_pixel start, t_pixel mid, t_pixel end)
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
	uint32_t	a;

	r = rounded(get_r(start.color) * (1 - get_ratio(start, mid, end))
			+ get_r(end.color) * (get_ratio(start, mid, end)));
	g = rounded(get_g(start.color) * (1 - get_ratio(start, mid, end))
			+ get_g(end.color) * (get_ratio(start, mid, end)));
	b = rounded(get_b(start.color) * (1 - get_ratio(start, mid, end))
			+ get_b(end.color) * (get_ratio(start, mid, end)));
	a = rounded(get_a(start.color) * (1 - get_ratio(start, mid, end))
			+ get_a(end.color) * (get_ratio(start, mid, end)));
	return (r << 24 | g << 16 | b << 8 | a);
}
