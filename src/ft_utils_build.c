/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_build.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:40:17 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/27 16:48:00 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	ft_trgb_rgba(char *char_map, int *fix, matrix_point *point)
{
	uint8_t	R;
	uint8_t	G;
	uint8_t	B;
	uint8_t	A;


	point->colour = (uint8_t)ft_get_hexadecimal(char_map, fix);
	if ((point->colour & 0xFF000000) == 0)
		point->colour |= 0xFF000000;
	A = (point->colour >> 24) & 0xFF;
	R = (point->colour >> 16) & 0xFF;
	G = (point->colour >> 8) & 0xFF;
	B = point->colour & 0xFF; //Extraemos transparencia
	point->colour = (R << 24) | (G << 16) | (B << 8) | A;
	//la transparencia en TRGB es invertida, 255 transparente
	ft_printf("Colour es %x\n", point->colour);
	return ; 
}
