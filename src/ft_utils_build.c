/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_build.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:40:17 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/26 14:24:36 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	ft_hex_mlx(uint32_t *colour)
{
	uint8_t	A;
	uint8_t	R;
	uint8_t	G;
	uint8_t	B;

	if ((*colour & 0xFF000000) == 0)
		*colour = *colour | 0xFF000000;
	A = (*colour >> 24) & 0xFF;
	R = (*colour >> 16) & 0xFF;
	G = (*colour >> 8) & 0xFF;
	B = *colour & 0xFF;
	*colour = (R << 24) | (G << 16) | (B << 8) | A;
	return ; 
}
