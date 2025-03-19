/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:00:06 by carlopez          #+#    #+#             */
/*   Updated: 2025/03/19 12:00:06 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

int	ft_check_parameters(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (ft_error_message("Wrong number of arguments\n"), -1);
	if (!ft_check_ext(argv[1]))
		return (ft_error_message("Wrong file extension\n"), -1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_error_message("Error while opening file\n"), -1);
	return (fd);
}

void	ft_error_message(char *str)
{
	if (!str)
		return ;
	ft_printf("%s", str);
	return ;
}

void	ft_free_matrix(t_matrix_map *map)
{
	t_matrix_point	**point;
	int				i;

	if (!map)
		return ;
	point = map->point;
	i = 0;
	while (i < map->height)
	{
		free(point[i]);
		i++;
	}
	free(point);
	free(map);
	return ;
}

int	main(int argc, char **argv)
{
	int			fd;
	t_matrix_map	*map;
	char		*char_map;

	map = NULL;
	fd = ft_check_parameters(argc, argv);
	if (fd == -1)
		return (-1);
	get_char_map(fd, &char_map);
	if (!ft_check_format(char_map))
		return (ft_error_message("Error in map format\n"), -1);
	map = ft_build_map(char_map);
	if (!map)
		return (ft_error_message("Error while creating map\n"), -1);
	map->mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	map->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	if (map->mlx)
		bresenham_algorithm(map);
	return (ft_free_matrix(map), 0);
}
