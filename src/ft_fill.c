/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:51:16 by carlopez          #+#    #+#             */
/*   Updated: 2025/03/19 12:04:35 by carlopez         ###   ########.fr       */
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

void	ft_fill_line(char *char_map, t_matrix_map *map, int i, int *fix)
{
	int	x;

	x = 0;
	while (x < map->width)
	{
		(map->point)[i][x].x = x;
		(map->point)[i][x].y = i;
		(map->point)[i][x].h = ft_fill_number(char_map, fix);
		if (char_map[*fix] && char_map[*fix] == ',')
			ft_trgb_rgba(char_map, fix, &(map->point)[i][x]);
		else
			map->point[i][x].colour = 0xFF0000FF;
		x++;
	}
	return ;
}
