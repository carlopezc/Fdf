/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_algorithm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:03:56 by carlopez          #+#    #+#             */
/*   Updated: 2025/03/19 12:08:29 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

int	ft_abs(int value)
{
	if (value < 0)
		value = value * -1;
	return (value);
}

void	ft_mlx(t_matrix_map *map)
{
	mlx_image_to_window(map->mlx, map->img, 0, 0);
	mlx_key_hook(map->mlx, my_keyhook, map);
	mlx_loop(map->mlx);
	mlx_delete_image(map->mlx, map->img);
	mlx_terminate(map->mlx);
	return ;
}

void	ft_zoom(t_matrix_point *final,
		t_matrix_point *initial, t_matrix_map *map)
{
	if (final)
	{
		final->x = (((WIDTH - 100) / map->width) * final->x / 2.5);
		final->h *= 10;
		final->y = (((HEIGHT - 100) / map->height) * final->y / 2.5);
	}
	if (initial)
	{
		initial->x = (((WIDTH - 100) / map->width) * initial->x / 2.5);
		initial->h *= 10;
		initial->y = (((HEIGHT - 100) / map->height) * initial->y / 2.5);
	}
	return ;
}

void	ft_free_map(int **map)
{
	if (!map)
		return ;
	while (*map)
	{
		free(*map);
		*map = NULL;
		map++;
	}
	return ;
}

void	ft_isometric(t_matrix_point *final, t_matrix_point *initial)
{
	double	angle;
	double	prev;

	angle = 0.523599;
	if (final)
	{
		prev = final->x;
		final->x = (prev - final->y) * cos(angle) + 1000;
		final->y = (prev + final->y) * sin(angle) - final->h + 450;
	}
	if (initial)
	{
		prev = initial->x;
		initial->x = (prev - initial->y) * cos(angle) + 1000;
		initial->y = (prev + initial->y) * sin(angle) - initial->h + 450;
	}
	return ;
}
