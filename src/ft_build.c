/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:16:32 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/27 20:42:31 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	ft_build_lines(char *char_map, matrix_map *map)
{
	int	j;
	int	fix;

	j = 0;
	fix = 0;
	while (j < map->height)
	{
		(map->point)[j] = (matrix_point *)
			malloc(map->width * sizeof(matrix_point));
		if (!(map->point)[j])
			return ;
		ft_fill_line(char_map, map, j, &fix);
		j++;
	}
	return ;
}

matrix_map	*ft_build_map(char *char_map)
{
	matrix_point	**map_points;
	matrix_map		*map;
	int				rows;
	int				columns;

	map = (matrix_map *)malloc(sizeof(matrix_map));
	if (!map)
		return (free(char_map), NULL);
	rows = ft_count_rows(char_map);
	map_points = (matrix_point **)malloc((rows + 1) * sizeof(matrix_point *));
	if (!map_points)
		return (free(char_map), NULL);
	map_points[rows] = NULL;
	columns = ft_count_columns(char_map);
	map->point = map_points;
	map->height = rows;
	map->width = columns;
	ft_build_lines(char_map, map);
	return (free(char_map), map);
}
