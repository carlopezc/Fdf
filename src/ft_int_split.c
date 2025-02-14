/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:31:17 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/13 16:26:32 by carlopez         ###   ########.fr       */
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

static int	**ft_fill_array(int **arr, char *s, char c)
{
	size_t			j;
	int	i;

	j = 0;
	i = 0;
	while (arr[j])
	{
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
	while (arr[i])
	{
		j = 0;
		while (j < len)
		{
			ft_printf("%i ", arr[i][j]);
			j++;
		}
		i++;
		ft_printf("\n");
	}
	return ;
}

int	**ft_int_split(char *s, char c)
{
	int	**arr;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_count_lines(s, c);
	arr = (int **)malloc((len + 1) * sizeof(int *));
	if (!arr)
		return (NULL);
	arr[len] = NULL;
	arr = ft_fill_array(arr, s, c);
	print_int_map(arr, len);
	return (arr);
}
