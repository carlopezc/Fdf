/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:59:59 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/26 15:14:15 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

int	is_digit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_check_numbers(char **map)
{
	int	i;

	if (!map || *map)
		return (0);
	i = 0;
	while (map[i])
	{
		while (*map[i])
		{
			if (!is_digit(*map[i]))
				return (0);
			map[i]++;
		}
		i++;
	}
	return (1);
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

int	count_size(char *initial_map, int *i)
{
	int	num;

	if (!initial_map)
		return (0);
	num = 0;
	while (initial_map[*i] && initial_map[*i] != '\n')
	{
		if (initial_map[*i] && (initial_map[*i] <= '9' && initial_map[*i] >= '0'))
		{
			num++;
			(*i)++;
			while (initial_map[*i] && (initial_map[*i] <= '9' && initial_map[*i] >= '0'))
				(*i)++;
			if (initial_map[*i] && (initial_map[*i] == ','))
			{
				(*i)++;
				while (initial_map[*i] && ((initial_map[*i] <= '9' && initial_map[*i] >= '0') || (initial_map[*i] >= 'A' && initial_map[*i] <= 'Z') || (initial_map[*i] >= 'a' && initial_map[*i] <= 'z')))
					(*i)++;
			}
		}
		else
			(*i)++;
	}
	return (num);
}

int	ft_check_size(char *initial_map)
{
	int	i;
	int	num_ref;
	int	num;
	int	flag;

	if (!initial_map)
		return (0);
	i = 0;
	num_ref = 0;
	num = 0;
	flag = 1;
	while (initial_map[i])
	{
		if (flag)
		{
			num_ref = count_size(initial_map, &i);
			num = num_ref;
			flag = 0;
		}
		else
			num = count_size(initial_map, &i);
		while (initial_map[i] && (initial_map[i] == '\n' || initial_map[i] == ' '))
			i++;
		if (num != num_ref)
			return (0);
	}
	return (num_ref);
}


int	ft_check_digits(char *initial_map)
{
	int	i;
	int	j;

	if (!initial_map)
		return (0);
	i = 0;
	while (initial_map[i])
	{
		while (initial_map[i] && (initial_map[i] == ' ' || initial_map[i] == '\n'))
			i++;
		if (initial_map[i] && (initial_map[i] == '-' || initial_map[i] == '+'))
			i++;
		if (initial_map[i] && (initial_map[i] > '9' || initial_map[i] < '0'))
			return (ft_printf("Error en los primeros numeros\n"), 0);
		while (initial_map[i] && (initial_map[i] <= '9' && initial_map[i] >= '0'))
			i++;
		if (initial_map[i] && initial_map[i] == ',')
		{
			i++;
			if (initial_map[i] && initial_map[i + 1]
					&& initial_map[i] == '0' && initial_map[i + 1] == 'x')
				i = i + 2;
			else
				return (ft_error_message("Wrong colour format\n"), 0);
			j = 0;
			while ((initial_map[i] <= '9' && initial_map[i] >= '0')
					|| (initial_map[i] >= 'A' && initial_map[i] <= 'Z')
					|| (initial_map[i] >= 'a' && initial_map[i] <= 'z'))
			{
				i++;
				j++;
			}
			if (j > 8)
				return (ft_error_message("Wrong colour format\n"), 0);
		}
	}
	return (1);
}

void	print_map(matrix_map *map, int size)
{
	int	i;
	int	j;

	if (!map)
		return ;
	i = 0;
	j = 0;
	while (map->point[i])
	{
		j = 0;
		while (j < size)
		{
			ft_printf("x: %i\n", ((map->point)[i][j].x));
			ft_printf("y: %i\n", ((map->point)[i][j].y));
			ft_printf("h: %i\n", ((map->point)[i][j].h));
			ft_printf("colour: %i\n", ((map->point)[i][j].colour));
			ft_printf("\n\n");
			j++;
		}
		i++;
	}
	return ;
}
/*
matrix_map	*ft_check_format(int fd, matrix_map *map)
{
	char	*initial_map;
	int	**int_map;
	
	initial_map = NULL;
	int_map = NULL;
	get_map(fd, &initial_map);
	if (!check_digits(initial_map) || !check_size(initial_map))
		return (free(initial_map), NULL);
	int_map = ft_int_split(initial_map, '\n');
	if (!int_map)
		return (free(initial_map), NULL);
	map = ft_build_map(int_map, initial_map, map);
	return (map);
}
*/

int	ft_check_format(char *char_map)
{
	if (!char_map)
		return (0);
	if (!ft_check_digits(char_map) || !ft_check_size(char_map))
		return (free(char_map), 0);
	return (1);
}

int	ft_check_ext(char *str)
{
	if (!str)
		return (0);
	while (str)
	{
		if (*str == '.')
		{
			if (ft_strcmp(str, ".fdf") == 0)
				return (1);
		}
		str++;
	}
	return (0);
}
