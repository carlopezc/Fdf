/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:16:32 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/24 15:02:38 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

int	ft_count_rows(int **int_map)
{
	int	i;

	if (!int_map || !*int_map)
		return (0);
	i = 0;
	while (int_map[i])
		i++;	
	return (i);
}

void	fill_line(int **int_map, matrix_point *map, int i, int p_size)
{
	int	j;
	int	x;

	if (!int_map || !map)
		return ;
	j = 0;
	x = 0;
	//ft_printf("Entra en fill_lines\n");
	while (j < p_size)
	{
		map[j].x = x;
		map[j].y = i;
		map[j].h = int_map[i][x];
		map[j].colour = 0; 
	//	ft_printf("rellena uno\n");
		j++;
		x++;
	}
	return ;
}

void	ft_build_lines(int **int_map, matrix_point **map, int columns, int rows)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	//ft_printf("Entra en build_lines\n");
	while (i < rows)
	{
		map[i] = (matrix_point *)malloc(columns * sizeof(matrix_point));
		if (!map[i])
			return ;
		fill_line(int_map, map[i], i, columns);
		i++;
	}
	return ;
}

matrix_map	*ft_build_map(int **int_map, char *initial_map, matrix_map *p_map)
{
	matrix_point	**map;
	int	rows;
	int	columns;


	//ft_printf("Entra en build_map\n");
	rows = ft_count_rows(int_map);
	//ft_printf("Rows son: %i\n", rows);
	map = (matrix_point **)malloc((rows + 1) * sizeof(matrix_point *));
	if (!map)
		return (ft_free_array((void **)int_map), free(initial_map), NULL);
	map[rows] = NULL;
	columns = ft_count_num(initial_map, '\n');
	//ft_printf("Columns es %i\n", columns);
	ft_build_lines(int_map, map, columns, rows);
	p_map->point = map;
	p_map->height = rows;
	p_map->width = columns;
	//print_map(p_map, columns);
	return (ft_free_array((void **)int_map), free(initial_map), p_map);
}
