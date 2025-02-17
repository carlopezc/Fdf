/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:59:59 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/17 10:49:40 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

char	*get_map(int fd, char **final_map)
{
	char	*line;

	*final_map = get_next_line(fd);
	if (*final_map)
	{
		line = get_next_line(fd);
		while (line)
		{
			*final_map = ft_strjoin_gnl(*final_map, line);
			line = get_next_line(fd);
		}
	}
	return (*final_map);
}

int	is_digit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	check_numbers(char **map)
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
		}
		else
			(*i)++;
	}
	return (num);
}

int	check_size(char *initial_map)
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
		if (initial_map[i] == '\n')
			i++;
		if (num != num_ref)
			return (0);
	}
	return (num_ref);
}


int	check_digits(char *initial_map)
{
	int	i;

	if (!initial_map)
		return (0);
	i = 0;
	while (initial_map[i])
	{
		if (initial_map[i] && (initial_map[i] == ' ' || initial_map[i] == '\n'))
		{
			i++;
			if (initial_map[i] && initial_map[i] == '\n')
				i++;
		}
		if (initial_map[i] && (initial_map[i] == '-' || initial_map[i] == '+'))
			i++;
		if (initial_map[i] && (initial_map[i] > '9' || initial_map[i] < '0'))
			return (0);
		while (initial_map[i] && (initial_map[i] <= '9' && initial_map[i] >= '0'))
			i++;
	}
	return (1);
}

void	print_map(matrix_point **map, int size)
{
	int	i;
	int	j;

	if (!map || !*map)
		return ;
	i = 0;
	j = 0;
	ft_printf("size es %i\n", size);
	while (map[i])
	{
		j = 0;
		while (j < size)
		{
			ft_printf("x: %i\n", (map[i][j].x));
			ft_printf("y: %i\n", (map[i][j].y));
			ft_printf("h: %i\n", (map[i][j].h));
			ft_printf("colour: %i\n", (map[i][j].colour));
			ft_printf("\n\n");
			j++;
		}
		i++;
	}
	return ;
}

matrix_map	*ft_check_format(int fd)
{
	char	*initial_map;
	int	**int_map;
	matrix_map	*map;
	
	get_map(fd, &initial_map);
	if (!check_digits(initial_map) || !check_size(initial_map))
		return (free(initial_map), NULL);
	int_map = ft_int_split(initial_map, '\n');
	if (!int_map)
		return (free(initial_map), ft_free_array((void **)int_map), NULL);
	map = ft_build_map(int_map, initial_map);
	if (!map)
		return (ft_free_array((void **)int_map), free(map), free(initial_map), NULL);
	return (free(initial_map), ft_free_array((void **)int_map), map);
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
