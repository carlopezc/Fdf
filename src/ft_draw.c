/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:59:02 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/24 15:39:48 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

int	ft_abs(int value)
{
	if (value < 0)
		value = value * -1;
	return (value);
}

int	*get_s_value(matrix_point initial, matrix_point final)
{
	int	*s;

	s = (int *)malloc(2 * sizeof(int));
	if (!s)
		return (NULL);
	if (initial.x < final.x)
		s[0] = 1;
	else
		s[0] = -1;
	if (initial.y < final.y)
		s[1] = 1;
	else
		s[1] = -1;
	return (s);
}

void	draw_horizontal(mlx_image_t *img, matrix_point initial, matrix_point final)
{
	int	*s;
	int	error;
	int	dx;
	int	dy;
	int	i;

	dx = ft_abs(final.x - initial.x);
	dy = ft_abs(final.y - initial.y);
	s = get_s_value(initial, final);
	error = (2 * dy) - dx;
	i = 0;
	while (i <= dx)
	{
		mlx_put_pixel(img, initial.x, initial.y, 0xFFFFFFFF);
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

void	draw_vertical(mlx_image_t *img, matrix_point initial, matrix_point final)
{
	int	*s;
	int	error;
	int	dx;
	int	dy;
	int	i;

	dx = ft_abs(final.x - initial.x);
	dy = ft_abs(final.y - initial.y);
	s = get_s_value(initial, final);
	error = (2 * dx) - dy;
	i = 0;
	while (i <= dy)
	{
		mlx_put_pixel(img, initial.x, initial.y, 0xFFFFFFFF);
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

void	ft_zoom(matrix_point *final, matrix_map *map)
{
	final->x = (((WIDTH - 100)/map->width) * final->x/2.5);
	final->h *= 10;
	final->y = (((HEIGHT - 100)/map->height) * final->y/2.5);
}

void	ft_isometric(matrix_point *final)
{
	double	angle = 0.523599; // 30° en radianes
	double	prev_x = final->x;

	final->x = (prev_x - final->y) * cos(angle) + 1000;
	final->y = (prev_x + final->y) * sin(angle) - final->h + 450;
}

void	ft_print_line(matrix_map *map, matrix_point initial, matrix_point final)
{
	ft_zoom(&final, map);
	ft_zoom(&initial, map);
	ft_isometric(&final);
	ft_isometric(&initial);
	if (ft_abs(final.y - initial.y) < ft_abs(final.x - initial.x))
	{
		//si es mas ancho que alto el recorrido
		if (initial.x > final.x)
			draw_horizontal(map->img, final, initial);
		else
			draw_horizontal(map->img, initial, final);
	}
	else
	{
		//si es mas alto que ancho el recorrido
		if (initial.y > final.y)
			draw_vertical(map->img, final, initial);
		else
			draw_vertical(map->img, initial, final);
	}
	//ft_printf("ha recorrido toda la linea yuhu!\n");
	return ;
}

void	bresenham_algorithm(matrix_map *map)
{
	int	x;
	int	y;
	matrix_point	**point;

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
	mlx_image_to_window(map->mlx, map->img, 0, 0);
	mlx_loop(map->mlx);
	mlx_delete_image(map->mlx, map->img);
	mlx_terminate(map->mlx);
	return ;
}

/*
void	to_perspective(matrix_point *point, int *dx, int *dy)
{
	double angle;
       
	angle = 30 * (M_PI / 180);
	*dx = (point->x - point->y) * cos(angle);
	*dy = (point->x - point->y) * sin(angle) - point->h;
	return ;
}

void	init_algorithm(matrix_point initial_point, matrix_point final_point, matrix_map *map)
{
	//podria meter los puntos en array 
	//to_perspective(initial_point, &initial_dx, &initial_dy);
	//to_perspective(final_point, &final_dx, &final_dy);
	print_line(map, initial_dx, initial_dy, final_dx, final_dy);
	return ;
}
*/
