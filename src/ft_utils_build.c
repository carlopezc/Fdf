/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_build.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:40:17 by carlopez          #+#    #+#             */
/*   Updated: 2025/03/19 12:06:59 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	ft_control_limit(t_matrix_point *point)
{
	if (!point)
		return ;
	if (point->x >= WIDTH)
		point->x = WIDTH - 1;
	else if (point->x < 0)
		point->x = 0;
	if (point->y >= HEIGHT)
		point->y = HEIGHT - 1;
	else if (point->y < 0)
		point->y = 0;
	return ;
}

void	ft_trgb_rgba(char *char_map, int *fix, t_matrix_point *point)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	point->colour = (uint8_t)ft_get_hexadecimal(char_map, fix);
	if ((point->colour & 0xFF000000) == 0)
		point->colour |= 0xFF000000;
	a = (point->colour >> 24) & 0xFF;
	r = (point->colour >> 16) & 0xFF;
	g = (point->colour >> 8) & 0xFF;
	b = point->colour & 0xFF;
	point->colour = (r << 24) | (g << 16) | (b << 8) | a;
	return ;
}
