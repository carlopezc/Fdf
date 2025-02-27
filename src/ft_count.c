/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:25:06 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/27 20:49:56 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	ft_count_size_ext(char *initial_map, int *i)
{
	while (initial_map[*i] && (initial_map[*i] <= '9'
			&& initial_map[*i] >= '0'))
		(*i)++;
	if (initial_map[*i] && (initial_map[*i] == ','))
	{
		(*i)++;
		while (initial_map[*i] && ((initial_map[*i] <= '9'
					&& initial_map[*i] >= '0') || (initial_map[*i] >= 'A'
					&& initial_map[*i] <= 'Z') || (initial_map[*i] >= 'a'
					&& initial_map[*i] <= 'z')))
			(*i)++;
	}
	return ;
}

int	ft_count_size(char *initial_map, int *i)
{
	int	num;

	if (!initial_map)
		return (0);
	num = 0;
	while (initial_map[*i] && initial_map[*i] != '\n')
	{
		if (initial_map[*i] && (initial_map[*i] <= '9'
				&& initial_map[*i] >= '0'))
		{
			num++;
			(*i)++;
			ft_count_size_ext(initial_map, i);
		}
		else
			(*i)++;
	}
	return (num);
}

int	ft_count_columns(char *char_map)
{
	int	columns;
	int	i;

	if (!char_map)
		return (0);
	columns = 0;
	i = 0;
	while (char_map[i] && char_map[i] != '\n')
	{
		if (char_map[i] != ' ')
			columns++;
		while (char_map[i] && char_map[i] != ' ' && char_map[i] != '\n')
			i++;
		if (char_map[i] && char_map[i] == ' ')
			i++;
	}
	return (columns);
}

int	ft_count_rows(char *char_map)
{
	int	i;
	int	rows;

	if (!char_map)
		return (0);
	i = 0;
	rows = 0;
	while (char_map[i])
	{
		if (char_map[i] != '\n')
		{
			rows++;
			ft_printf("Rows es %i\n", rows);
			i++;
		}
		while (char_map[i] && char_map[i] != '\n')
			i++;
		if (char_map[i] && char_map[i] == '\n')
			i++;
	}
	return (rows);
}
