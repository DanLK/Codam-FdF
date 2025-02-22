/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dloustal <dloustal@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/22 14:03:05 by dloustal      #+#    #+#                 */
/*   Updated: 2025/02/22 17:59:57 by dloustal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_sign(char c)
{
	return (c == '-' || c == '+');
}

int	get_color(char *str)
{
	int			color;
	char		*s;

	if (!str)
		return (-1);
	s = str;
	while (ft_isdigit(*s) || is_sign(*s))
		s++;
	if (!*s || *s == '\n')
		s = "A040FFFF";
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

/* Assuming the strign lenght is 6 or 8*/
int	str_to_color(char *str)
{
	int	r;
	int	g;
	int	b;
	int	a;

	if (!str)
		return (-1);
	if (ft_strlen(str) <= 2)
	{
		r = 0;
		g = 0;
		b = get_color_component(str, 0);
	}
	else if (ft_strlen(str) <= 4)
	{
		r = 0;
		g = get_color_component(str, 0);
		b = get_color_component(str, 2);
	}
	else
	{
		r = get_color_component(str, 0);
		g = get_color_component(str, 2);
		b = get_color_component(str, 4);
	}
	if (ft_strlen(str) <= 6 || (str[6] && str[6] == '\n'))
		a = 255;
	else
		a = get_color_component(str, 6);
	return (r << 24 | g << 16 | b << 8 | a);
}

int	get_color_component(char *str, int index)
{
	char	*color_s;
	int		color_nr;

	if (!str)
		return (-1);
	color_s = ft_substr(str, index, 2);
	if (!color_s)
		return (-1);
	color_nr = ft_atoi_base(color_s, "0123456789ABCDEF");
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
