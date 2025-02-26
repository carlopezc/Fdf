/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:25:06 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/26 14:47:44 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

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


