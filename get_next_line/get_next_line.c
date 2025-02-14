/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:23:01 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/13 16:27:48 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../lib/fdf.h"

char	*ft_fill_buffer(char *final_buffer, int newline)
{
	int		i;
	char	*line;

	if (!final_buffer)
		return (NULL);
	if (final_buffer[0] == '\0')
		return (free(final_buffer), NULL);
	i = -1;
	if (newline > -1)
	{
		line = (char *)malloc((newline + 2) * sizeof(char));
		if (!line)
			return (NULL);
		while (++i <= newline)
			line[i] = final_buffer[i];
		line[i] = '\0';
		ft_free(&final_buffer, NULL);
	}
	else
	{
		line = ft_strjoin_gnl(final_buffer, NULL);
		final_buffer = NULL;
	}
	return (line);
}

void	ft_fill_remainder(char **remainder_buff, char **final_buff, int nl)
{
	int	len;
	int	i;

	len = ft_strlen_gnl(*final_buff) - nl;
	*remainder_buff = (char *)malloc((len + 1) * sizeof(char));
	if (!(*remainder_buff))
		return ;
	i = 0;
	while ((*final_buff)[nl] != '\0')
		(*remainder_buff)[i++] = (*final_buff)[nl++];
	(*remainder_buff)[i] = '\0';
	return ;
}

void	ft_read_and_join(char **final_buffer, int fd, ssize_t *bytes_read)
{
	char	*initial_buffer;

	initial_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!initial_buffer)
		return ;
	*bytes_read = read(fd, initial_buffer, BUFFER_SIZE);
	if (*bytes_read == -1)
		return (free(initial_buffer));
	initial_buffer[*bytes_read] = '\0';
	*final_buffer = ft_strjoin_gnl(*final_buffer, initial_buffer);
	initial_buffer = NULL;
	return ;
}

char	*ft_manage(int fd, char **remainder_buffer, char **final_buffer)
{
	ssize_t	bytes_read;
	int		newline;

	bytes_read = BUFFER_SIZE;
	newline = -1;
	while (bytes_read == BUFFER_SIZE)
	{
		newline = ft_search_nl(*final_buffer);
		if (newline > -1 && newline < ft_strlen_gnl(*final_buffer))
		{
			ft_fill_remainder(remainder_buffer, final_buffer, newline + 1);
			return (ft_fill_buffer(*final_buffer, newline));
		}
		ft_read_and_join(final_buffer, fd, &bytes_read);
		if (bytes_read == -1)
			return (free(*final_buffer), NULL);
	}
	newline = ft_search_nl(*final_buffer);
	if (newline > -1 && newline < ft_strlen_gnl(*final_buffer))
		ft_fill_remainder(remainder_buffer, final_buffer, newline + 1);
	return (ft_fill_buffer(*final_buffer, newline));
}

char	*get_next_line(int fd)
{
	static char	*remainder_buffer;
	char		*final_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	final_buffer = NULL;
	if (remainder_buffer)
		final_buffer = ft_strjoin_gnl(remainder_buffer, NULL);
	remainder_buffer = NULL;
	return (ft_manage(fd, &remainder_buffer, &final_buffer));
}
