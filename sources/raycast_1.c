/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:07:38 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/31 11:51:36 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	test(t_cube *cub, t_map *map)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		size_x;
	int		size_y;
	int		color_rgb;

	size_x = 1;
	size_y = 1;
	map->temp = 0;
	cub->tmp = 0;
	color_rgb = 255000000;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, cub->p_rx, cub->p_ry, cub->f_name);

	while (size_x++ < 100)
	{
		while (size_y++ < 100)
		{
			mlx_pixel_put (mlx_ptr, win_ptr, size_x + size_y, (size_y - size_x) + 300, ((color_rgb + size_y) * size_x));
		}
		size_y = 0;
	}
	mlx_loop(mlx_ptr);
}
