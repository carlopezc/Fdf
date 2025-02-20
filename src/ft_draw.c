/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:59:02 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/20 18:59:08 by carlopez         ###   ########.fr       */
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
/*
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
*/
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
		mlx_put_pixel(img, initial.x, initial.y, 0xff0000);
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
		mlx_put_pixel(img, initial.x, initial.y, 0xff0000);
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

void	print_line(matrix_map *map, matrix_point initial, matrix_point final)
{
	/*
	int	dx;
	int	dy;
	int	error;
	int	dir;
	int	*s;
*/
	/*
	dx = ft_abs(final_dx - initial_dx);
	dy = ft_abs(final_dy - initial_dy);
	error = dx - dy;
	dir = 2 * error;
	s = get_s_value(initial_dx, initial_dy, final_dx, final_dy); 
	if (!s)
		return ; //gestionar este fin de programa
	*/
	//mlx_put_pixel(map->img, initial_dx, initial_dy, 0x00000); //dibuja el punto
	ft_printf("ha entrado en print line \n");
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
	return ;
}

void	bresenham_algorithm(matrix_map *map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	ft_printf("entra en bresenham algorithm \n");
	ft_printf("map width es : %i\n", map->width);
	ft_printf("map height es : %i\n", map->height);
	while (x < map->width)
	{
		while (y < map->height)
		{
			ft_printf("entra en bresenham antes de los ifs\n");
			if (x + 1 < map->width)
				print_line(map, map->point[y][x], map->point[y][x + 1]); //ft_print_line();
			if (y + 1 < map->height)
				print_line(map, map->point[y][x], map->point[y + 1][x]); //ft_print_line();
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
