/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:59:02 by carlopez          #+#    #+#             */
/*   Updated: 2025/03/19 12:08:45 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	draw_horizontal(mlx_image_t *img,
	t_matrix_point initial, t_matrix_point final)
{
	int	*s;
	int	error;
	int	dx;
	int	dy;
	int	i;

	dx = ft_abs(final.x - initial.x);
	dy = ft_abs(final.y - initial.y);
	s = ft_get_s(initial, final);
	error = (2 * dy) - dx;
	i = 0;
	while (i <= dx)
	{
		ft_control_limit(&initial);
		mlx_put_pixel(img, initial.x, initial.y, initial.colour);
		if (error > 0)
		{
			initial.y += s[1];
			error -= (2 * dx);
		}
		error += (2 * dy);
		initial.x += s[0];
		i++;
	}
	return (free(s));
}

void	draw_vertical(mlx_image_t *img,
	t_matrix_point initial, t_matrix_point final)
{
	int	*s;
	int	error;
	int	dx;
	int	dy;
	int	i;

	dx = ft_abs(final.x - initial.x);
	dy = ft_abs(final.y - initial.y);
	s = ft_get_s(initial, final);
	error = (2 * dx) - dy;
	i = 0;
	while (i <= dy)
	{
		ft_control_limit(&initial);
		mlx_put_pixel(img, initial.x, initial.y, initial.colour);
		if (error > 0)
		{
			initial.x += s[0];
			error -= (2 * dy);
		}
		error += (2 * dx);
		initial.y += s[1];
		i++;
	}
	return (free(s));
}

void	ft_print_line(t_matrix_map *map,
		t_matrix_point initial, t_matrix_point final)
{
	ft_zoom(&final, &initial, map);
	ft_isometric(&final, &initial);
	ft_control_limit(&initial);
	ft_control_limit(&final);
	if (ft_abs(final.y - initial.y) < ft_abs(final.x - initial.x))
	{
		if (initial.x > final.x)
			draw_horizontal(map->img, final, initial);
		else
			draw_horizontal(map->img, initial, final);
	}
	else
	{
		if (initial.y > final.y)
			draw_vertical(map->img, final, initial);
		else
			draw_vertical(map->img, initial, final);
	}
	return ;
}

void	bresenham_algorithm(t_matrix_map *map)
{
	int				x;
	int				y;
	t_matrix_point	**point;

	y = 0;
	x = 0;
	point = map->point;
	while (x < map->width)
	{
		while (y < map->height)
		{
			if (x + 1 < map->width)
				ft_print_line(map, point[y][x], point[y][x + 1]);
			if (y + 1 < map->height)
				ft_print_line(map, point[y][x], point[y + 1][x]);
			y++;
		}
		y = 0;
		x = x + 1;
	}
	ft_mlx(map);
	return ;
}
