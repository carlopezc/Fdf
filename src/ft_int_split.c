/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:31:17 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/20 18:34:12 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

static size_t	ft_count_lines(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

void	ft_free_array(void **arr)
{
	size_t	j;

	j = 0;
	while (arr[j])
		free(arr[j++]);
	free(arr);
}

int	ft_atoi(int *i, char *s)
{
	int	sign;
	int	num;

	ft_printf("i vale: %i\n", *i);
	while (s && (s[*i] == ' ' || s[*i] == '\n'))
		(*i)++;
	sign = 1;
	if (s && (s[*i] == '-' || s[*i] == '+'))
	{
		if (s[*i] == '-')
			sign = -1;
		(*i)++;
	}
	num = 0;
	while (s && (s[*i] >= '0' && s[*i] <= '9'))
		num = num * 10 + (s[(*i)++] - '0');
	return (sign * num);
}

int	ft_count_num(char *s, char c)
{
	int	count;
	int	i;

	if (!s)
		return (-1);
	count = 0;
	i = 0;
	while (s[i] && s[i] != c)
	{
		while (s[i] && s[i] != c && (s[i] == ' ' || s[i] == '-' || s[i] == '+'))
			i++;
		if (s[i] >= '0' && s[i] <= '9')
		{
			count++;
			i++;
		}
		while (s[i] && s[i] >= '0' && s[i] <= '9')
			i++;
	}
	return (count);
}

int	*make_line(char *s, char c, int *i)
{
	int	nums;
	int	*row;
	int	j;

	nums = ft_count_num(s, c);
	ft_printf("nums son %i\n", nums);
	if (nums == 0)
		return (NULL);
	row = (int *)malloc(nums * sizeof(int));
	if (!row)
		return (NULL);
	j = 0;
	while (j < nums)
		row[j++] = ft_atoi(i, s);
	return (row);
}

int	**ft_fill_array(int **arr, char *s, char c, int len)
{
	int			j;
	int	i;

	j = 0;
	i = 0;
	ft_printf("Entra a rellenar el array \n");
	while (j < len)
	{
		ft_printf("Entra a rellenar el array \n");
		arr[j] = make_line(s, c, &i);
		if (!arr[j])
			return (ft_free_array((void **)arr), NULL);
		j++;
	}
	return (arr);
}

void	print_int_map(int **arr, int len)
{
	int	i;
	int	j;

	if (!arr)
		return ;
	i = 0;
	j = 0;
	ft_printf("va a imprimir se supone\n");
	while (arr[i])
	{
		while (j < len)
		{
			ft_printf("%i", arr[i][j]);
			j++;
		}
		j = 0;
		ft_printf("\n");
		i++;
	}
	return ;
}

int	**ft_int_split(char *s, char c)
{
	int	**arr;
	int	len;

	if (!s)
		return (NULL);
	ft_printf("s esta bien creada en int split\n");
	len = ft_count_lines(s, c);
	ft_printf("len de int split es: %i\n", len);
	arr = (int **)malloc((len + 1) * sizeof(int *));
	if (!arr)
		return (NULL);
	arr[len] = NULL;
	ft_fill_array(arr, s, c, len);
	print_int_map(arr, len);
	return (arr);
}
