/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_check_ext.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:06:26 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/27 20:35:31 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

int	is_digit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_strcmp(char *str, char *str2)
{
	int	i;

	if (!str || !str2)
		return (-1);
	i = 0;
	while (str[i] && str2[i])
	{
		if (str[i] != str2[i])
			return (str[i] - str2[i]);
		i++;
	}
	return (str[i] - str2[i]);
}

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
