/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:32:50 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/27 20:37:01 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>
# include "../printf/ft_printf.h"
# include <unistd.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# define WIDTH 4480
# define HEIGHT 2520

typedef struct matrix_point
{
	int	x;
	int	y;
	int	h;
	uint32_t	colour;
}	matrix_point;

typedef struct	matrix_map 
{
	matrix_point	**point;
	mlx_t	*mlx;
	mlx_image_t	*img;
	int	width;
	int	height;
}	matrix_map;

char	*get_next_line(int fd);

int	ft_strcmp(char *str, char *str2);
int	ft_count_size(char *initial_map, int *i);
void	ft_zoom(matrix_point *final, matrix_point *initial, matrix_map *map);
void	bresenham_algorithm(matrix_map *map);
void	ft_isometric(matrix_point *final, matrix_point *initial);
void	ft_mlx(matrix_map *map);
void	init_algorithm(matrix_point *initial_point, matrix_point *final_point, matrix_map *map);
int	ft_strlen_gnl(char *str);
int	ft_check_ext(char *str);
int	ft_check_format(char *char_map);
matrix_map	*ft_build_map(char *char_map);
void	ft_fill_line(char *char_map, matrix_map *map, int i, int *fix);
int	ft_check_parameters(int argc, char **argv);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strjoin_gnl(char *str, char *str2);
int	**ft_int_split(char *s, char c);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *s);
void	print_map(matrix_map *map, int size);
void	ft_error_message(char *str);
void	ft_free_array(void **arr);
int	ft_count_rows(char *char_map);
int	ft_count_columns(char *char_map);
int	*ft_get_s(matrix_point initial, matrix_point final);
long	ft_get_hexadecimal(char *char_map, int *i);
void	ft_trgb_rgba(char *char_map, int *fix, matrix_point *point);
char	*get_char_map(int fd, char **final_map);
void	my_keyhook(mlx_key_data_t keydata, void *param);
void	ft_free_matrix(matrix_map *map);
void	ft_control_limit(matrix_point *point);
int	is_digit(char c);
int	ft_abs(int value);
int	ft_check_digits(char *initial_map);
int	ft_check_digits_ext(char *initial_map, int *i);
int	ft_check_size(char *initial_map);


#endif
