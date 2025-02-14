/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:53:08 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/11 11:31:18 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	char	*map;
	char	*linea;
	int	fd;

	if (argc < 2)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	map = NULL;
	linea = get_next_line(fd);
	while (linea)
	{
		map = ft_strjoin_gnl(map, linea);
		linea = NULL;
		free(linea);
		linea = get_next_line(fd);
	}
	printf("%s", map);
	close(fd);
	return (0);
}
