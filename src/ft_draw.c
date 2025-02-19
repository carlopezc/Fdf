/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:59:02 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/19 15:51:52 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

int	ft_abs(int value)
{
	if (value < 0)
		value = value * -1;
	return (value);
}

int	*get_s_value(int initial_dx, int initial_dy, int final_dx, int final_dy)
{
	int	*s;

	s = (int *)malloc(2 * sizeof(int));
	if (!s)
		return (NULL);
	if (initial_dx < final_dx)
		s[0] = 1;
	else
		s[0] = -1;
	if (initial_dy < final_dy)
		s[1] = 1;
	else
		s[1] = -1;
	return (s);
}

void	draw_1(mlx_image_t *img, t_point initial, t_point final)
{
	int	dx;
	int	dy;
	int	error;
	int	sx;
	int	sy;

	dx = ft_abs(final_dx - initial_dx);
	dy = ft_abs(final_dy - initial_dy);
	s = get_s_value(initial_dx, initial_dy, final_dx, final_dy);
	error = (2 * dy) - dx;
}

void	print_line(matrix_map *map, int initial_dx, int initial_dy, int final_dx, int final_dy)
{
	int	dx;
	int	dy;
	int	error;
	int	dir;
	int	*s;

	/*
	dx = ft_abs(final_dx - initial_dx);
	dy = ft_abs(final_dy - initial_dy);
	error = dx - dy;
	dir = 2 * error;
	s = get_s_value(initial_dx, initial_dy, final_dx, final_dy); 
	if (!s)
		return ; //gestionar este fin de programa
	*/
	mlx_put_pixel(map->img, initial_dx, initial_dy, 0x00000); //dibuja el punto
	if (ft_abs(initial_dy - final_dy) < ft_abs(initial_dx - final_dx))
	{
		//si es mas ancho que alto el recorrido
		if (initial_dx > final_dx)
			draw_1();
		else
			draw_1();
	}
	else
	{
		//si es mas alto que ancho el recorrido
		if ()
			draw_2();
		else
			draw_2();
	}
	/*
	if (dir > -dy)
		{
			error = error - dy;
			initial_dx = initial_dx + s[0];
		}
		if (dir < dx)
		{
			error = error + dx;
			initial_dy = initial_dy + s[1];
		}
	}
	*/
	ft_printf("ha recorrido toda la linea yuhu!\n");
	return (free(s));
}

void	bresenham_algorithm(matrix_map *map)
{
	matrix_point	**point;

	y = 0;
	x = 0;
	point = map->point;
	while (point[y][x])
	{
		while (point[y])
		{
			if (point[y][x] && point[y][x + 1])
				init_algorithm(point[y][x], point[y][x + 1], map); //ft_print_line();
			if (point[y][x] && point[y + 1][x])
				init_algorithm(point[y][x], point[y + 1][x], map); //ft_print_line();
			y++;
		}
		ft_printf("primera linea i=0 recorrida\n");
		y = 0;
		x = x + 1;
	}
	ft_printf("ya ha recorrido todo \n");
	/*
	init_algorithm(point[1], point[1] + 1, map);
	init_algorithm(point[1] + 2, point[1] + 3, map);
	//mlx_key_hook(map->mlx, , map);
	*/
	mlx_image_to_window(map->mlx, map->img, 0, 0);
	mlx_loop(map->mlx);
	mlx_delete_image(map->mlx, map->img);
	mlx_terminate(map->mlx);
	return ;
}

void	to_perspective(matrix_point *point, int *dx, int *dy)
{
	double angle;
       
	angle = 30 * (M_PI / 180);
	*dx = (point->x - point->y) * cos(angle);
	*dy = (point->x - point->y) * sin(angle) - point->h;
	return ;
}

void	init_algorithm(matrix_point *initial_point, matrix_point *final_point, matrix_map *map)
{
	int	initial_dx;
	int	initial_dy;
	int	final_dx;
	int	final_dy;

	//podria meter los puntos en array 
	to_perspective(initial_point, &initial_dx, &initial_dy);
	to_perspective(final_point, &final_dx, &final_dy);
	print_line(map, initial_dx, initial_dy, final_dx, final_dy);
	return ;
}
