/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:22:08 by carlopez          #+#    #+#             */
/*   Updated: 2025/02/17 12:24:15 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/fdf.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 4480, 2520, "Hello world");
	mlx_loop(mlx);
}
