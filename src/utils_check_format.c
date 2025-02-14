/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:15:00 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/13 16:26:16 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*src_char;
	unsigned char		*dest_char;

	dest_char = (unsigned char *)dest;
	src_char = (unsigned const char *)src;
	if (!dest_char && !src_char)
		return (dest);
	i = 0;
	while (i < n)
	{
		dest_char[i] = src_char[i];
		i++;
	}
	return (dest_char);
}

char	*ft_strdup(char *s)
{
	char	*p;
	size_t	len;

	len = ft_strlen_gnl(s);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (0);
	ft_memcpy(p, s, len);
	p[len] = '\0';
	return (p);
}

char	*ft_substr(char *s, int start, int len)
{
	int	i;
	int	str_len;
	char	*p;

	i = 0;
	if (!s)
		return (NULL);
	str_len = ft_strlen_gnl(s);
	if (start >= str_len)
		return (ft_strdup(""));
	str_len -= start;
	if (str_len > len)
		str_len = len;
	p = (char *)malloc((str_len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (i < str_len && s[start])
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*p;
	char	*cs1;
	char	*cs2;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	cs1 = (char *)s1;
	cs2 = (char *)s2;
	p = (char *)malloc((ft_strlen(cs1) + ft_strlen(cs2) + 1) * sizeof(char));
	if (!p)
		return (0);
	while (i < ft_strlen(cs1))
	{
		p[i] = cs1[i];
		i++;
	}
	while (i < (ft_strlen(cs1) + ft_strlen(cs2)))
		p[i++] = cs2[j++];
	p[i] = '\0';
	return (p);
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
