/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:22:35 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/27 16:25:16 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

char	*get_char_map(int fd, char **final_map)
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

int	*ft_get_s(matrix_point initial, matrix_point final)
{
	int	*s;

	s = (int *)malloc(2 * sizeof(int));
	if (!s)
		return (NULL);
	if (initial.x < final.x)
		s[0] = 1;
	else
		s[0] = -1;
	if (initial.y < final.y)
		s[1] = 1;
	else
		s[1] = -1;
	return (s);
}

long	ft_get_hexadecimal(char *char_map, int *i)
{
	long	hex;
	int	sign;

	hex = 0;
	sign = 1;
	if (char_map[*i] && char_map[*i] == ',')
		(*i)++;
	if (char_map[*i] && char_map[*i] == '0')
		(*i)++;
	if (char_map[*i] && char_map[*i] == 'x')
		(*i)++;
	if (char_map[*i] && (char_map[*i] == '-' || char_map[*i] == '+'))
	{
		if (char_map[*i] == '-')
			sign = -1;
		(*i)++;
	}
	while (char_map[*i] && ((char_map[*i] >= '0' && char_map[*i] <= '9') || (char_map[*i] >= 'A' && char_map[*i] <= 'Z') || (char_map[*i] >= 'a' && char_map[*i] <= 'z')))
	{
		if (char_map[*i] >= '0' && char_map[*i] <= '9')
			hex = hex * 16 + (char_map[*i] - '0');
		else if (char_map[*i] >= 'A' && char_map[*i] <= 'F')
			hex = hex * 16 + (char_map[*i] - 'A' + 10);
		else
			hex = hex * 16 + (char_map[*i] - 'a' + 10);
		(*i)++;
	}
	ft_printf("El hexadecimal es %x\n", hex * sign);
	return (hex * sign);
}
