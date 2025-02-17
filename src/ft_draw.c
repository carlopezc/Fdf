/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:59:02 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/17 18:35:45 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

int	abs(int 0_point, int 1_point)
{
	int	abs_point;

	abs_point = 1_point - 0_point;
	if (abs_point < 0)
		abs_point = abs_point * -1;
	return (abs_point);
}

int	get_s_value(matrix_point *0_point, matrix_point *1_point)
{
	int	s;
	//esta mal, y solo se calcula al principio, si x0 < x1 sx = 1
	//si x0 > x1 sx = -1
	//se calcula una soola vez al principio

	if (0_point->x < 1_point->x)
		s = 1;
	else
		s = -1;
	return (s);
}

void	print_line(int 0_dx, int 0_dy, int 1_dx, int 1_dy)
{
	int	dx;
	int	dy;
	int	error;
	int	dir;

	dx = abs(1_dx - 0_dx);
	dy = abs(1_dy - 0_dy);
	error = dx - dy;
	dir = 2 * error; //multiplicamos por dos para evitar fracciones
	while ()
	{
		plot(0_dx, 0_dy); //dibuja el punto
		if (0_dx == 1_dx && 0_dy == 1_dy)
			break ;
		if (dir > -dy)
		{
			error = error - dy;
			0_dx = 0_dx + get_s_value();
		}
		if (dir < dx)
		{
			error = error + dx;
			0_dy = 0_dy + get_s_value();
		}


	}
}

void	3D_to_2D(matriz_point *point, int *dx, int *dy)
{
	double angle = 30 * (M_PI / 180);

	*dx = (point->x - point->y) * cos(angle);
	*dy = (point->x - point->y) * sin(angle) - point->z;
	return ;
}
/*
void	bresenhams_algortihm()
{


}
*/
void	init_algorithm(matrix_point*	0_point, matrix_point *1_point)
{
	int	0_dx;
	int	0_dy;
	int	1_dx;
	int	1_dy;
	int	error;
/*
	dx = abs(0_point->x, 1_point->x);
	dy = abs(0_point->y, 1_point->y);
	*/
	3D_to_2D(0_point, &0_dx, &0_dy);
	3D_to_2D(1_point, &1_dx, &1_dy);
	print_line(0_dx, 0_dy, 1_dx, 1_dy);

	error = dx - dy;
	bresenhams_algorithm(dx, dy, error);

}
