/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:10:26 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/27 17:28:24 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fdf.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	matrix_map	*map;

	map = (matrix_map *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(map->mlx);
		mlx_terminate(map->mlx);
		ft_free_matrix(map);
		exit(1);
	}
}
