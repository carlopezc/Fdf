/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:59:59 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/27 20:28:52 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

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

void	ft_check_size_ext(char *initial_map, int *i)
{
	while (initial_map[*i]
		&& (initial_map[*i] == '\n' || initial_map[*i] == ' '))
		(*i)++;
	return ;
}

int	ft_check_size(char *initial_map)
{
	int	i;
	int	num_ref;
	int	num;
	int	flag;

	i = 0;
	num_ref = 0;
	num = 0;
	flag = 1;
	while (initial_map && initial_map[i])
	{
		if (flag)
		{
			num_ref = ft_count_size(initial_map, &i);
			num = num_ref;
			flag = 0;
		}
		else
			num = ft_count_size(initial_map, &i);
		ft_check_size_ext(initial_map, &i);
		if (num != num_ref)
			return (0);
	}
	return (num_ref);
}

int	ft_check_digits_ext(char *initial_map, int *i)
{
	int	j;

	j = 0;
	if (initial_map[*i] && initial_map[*i] == ',')
	{
		(*i)++;
		if (initial_map[*i] && initial_map[*i + 1]
			&& initial_map[*i] == '0' && initial_map[*i + 1] == 'x')
			*i = *i + 2;
		else
			return (ft_error_message("Wrong colour format\n"), 0);
		j = *i;
		while ((initial_map[*i] <= '9' && initial_map[*i] >= '0')
			|| (initial_map[*i] >= 'A' && initial_map[*i] <= 'Z')
			|| (initial_map[*i] >= 'a' && initial_map[*i] <= 'z'))
			(*i)++;
		if (*i - j > 8)
			return (ft_error_message("Wrong colour format\n"), 0);
	}
	return (1);
}

int	ft_check_digits(char *initial_map)
{
	int	i;

	if (!initial_map)
		return (0);
	i = 0;
	while (initial_map[i])
	{
		while (initial_map[i]
			&& (initial_map[i] == ' ' || initial_map[i] == '\n'))
			i++;
		if (initial_map[i]
			&& (initial_map[i] == '-' || initial_map[i] == '+'))
			i++;
		if (initial_map[i] && (initial_map[i] > '9' || initial_map[i] < '0'))
			return (ft_printf("Error en los primeros numeros\n"), 0);
		while (initial_map[i]
			&& (initial_map[i] <= '9' && initial_map[i] >= '0'))
			i++;
		if (!ft_check_digits_ext(initial_map, &i))
			return (0);
	}
	return (1);
}
