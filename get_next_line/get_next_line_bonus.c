/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:18:30 by carlopez          #+#    #+#             */
/*   Updated: 2024/12/02 15:30:54 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		line = ft_strjoin(final_buffer, NULL);
		final_buffer = NULL;
	}
	return (line);
}

void	ft_fill_remainder(char **remainder, char **final, int nl, int fd)
{
	int	len;
	int	i;

	len = ft_strlen(*final) - nl;
	remainder[fd] = (char *)malloc((len + 1) * sizeof(char));
	if (!remainder[fd])
		return ;
	i = 0;
	while ((*final)[nl] != '\0')
		remainder[fd][i++] = (*final)[nl++];
	remainder[fd][i] = '\0';
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
	*final_buffer = ft_strjoin(*final_buffer, initial_buffer);
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
		if (newline > -1 && newline < ft_strlen(*final_buffer))
		{
			ft_fill_remainder(remainder_buffer, final_buffer, newline + 1, fd);
			return (ft_fill_buffer(*final_buffer, newline));
		}
		ft_read_and_join(final_buffer, fd, &bytes_read);
		if (bytes_read == -1)
			return (free(*final_buffer), NULL);
	}
	newline = ft_search_nl(*final_buffer);
	if (newline > -1 && newline < ft_strlen(*final_buffer))
		ft_fill_remainder(remainder_buffer, final_buffer, newline + 1, fd);
	return (ft_fill_buffer(*final_buffer, newline));
}

char	*get_next_line(int fd)
{
	static char	*remainder_buffer[1024];
	char		*final_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	final_buffer = NULL;
	if (remainder_buffer[fd])
		final_buffer = ft_strjoin(remainder_buffer[fd], NULL);
	remainder_buffer[fd] = NULL;
	return (ft_manage(fd, remainder_buffer, &final_buffer));
}
