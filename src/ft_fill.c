/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:51:16 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/26 15:33:27 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

int	ft_fill_number(char *char_map, int *i)
{
	int	number;
	int	sign;

	sign = 1;
	number = 0;
	while (char_map[*i] && (char_map[*i] == ' ' || char_map[*i] == '\n'))
		(*i)++;
	if (char_map[*i] == '+' || char_map[*i] == '-')
	{
		if (char_map[*i] == '-')
			sign = -1;
		(*i)++;
	}
	while (char_map[*i] && char_map[*i] >= '0' && char_map[*i] <= '9')
		number = number * 10 + (char_map[(*i)++] - '0');
	return (sign * number);
}
	
uint32_t	ft_fill_colour(char *char_map, int *i)
{
	long	hex;
	uint32_t	colour;

	hex = ft_get_hexadecimal(char_map, i);
	colour = (uint32_t)hex;
	ft_hex_mlx(&colour);
	return (colour);
}

void	ft_fill_line(char *char_map, matrix_map *map, int i, int *fix)
{
	//int	j;
	int	x;

	//j = 0;
	x = 0;
	ft_printf("Entra en fill line\n");
	while (x < map->width)
	{
		(map->point)[i][x].x = x;
		(map->point)[i][x].y = i;
		ft_printf("Hasta aqui bien \n");
		(map->point)[i][x].h = ft_fill_number(char_map, fix);
		if (char_map[*fix] && char_map[*fix] == ',')
			(map->point)[i][x].colour = ft_fill_colour(char_map, fix); 
		else
		{
			map->point[i][x].colour = 0x00000000;
			ft_printf("Este colorcico majo\n");
		}
		x++;
	}
	return ;
}


