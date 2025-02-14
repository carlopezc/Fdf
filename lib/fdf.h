/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:32:50 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/14 13:51:49 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <fcntl.h>
#include <stdlib.h>
//#include <stdio.h>
#include "../printf/ft_printf.h"
#include <unistd.h>
#include "../MLX42/include/MLX42/MLX42.h"
# define WIDTH 4480
# define HEIGHT 2520

typedef struct matrix_point
{
	int	x;
	int	y;
	int	h;
	int	colour;
}	matrix_point;

typedef struct	matrix_map 
{
	matrix_point	**point;
	mlx_t	*mlx;
	mlx_image_t	*img;
}	matrix_map;

char	*get_next_line(int fd);

int	ft_strcmp(char *str, char *str2);
int	ft_strlen_gnl(char *str);
int	ft_check_ext(char *str);
matrix_map	*ft_check_format(int fd);
int	ft_check_parameters(int argc, char **argv);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strjoin_gnl(char *str, char *str2);
int	**ft_int_split(char *s, char c);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *s);
void	print_map(matrix_point **map, int size);

void	ft_free_array(void **arr);
matrix_map	*ft_build_map(int **map, char *initial_map);
int	ft_count_num(char *s, char c);

#endif
