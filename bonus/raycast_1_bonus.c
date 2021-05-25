/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:07:38 by juasanto          #+#    #+#             */
/*   Updated: 2021/05/25 11:27:35 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d_bonus.h"

int	raycast_loop(t_cube *cub)
{
	int	x;

	x = 0;
	pl_move(cub);
	cub->mlx.img = mlx_new_image(cub->mlx.mlx, cub->resX, cub->resY);
	cub->mlx.addr = mlx_get_data_addr(cub->mlx.img, &cub->mlx.bits_per_pixel,
			&cub->mlx.line_length, &cub->mlx.endian);
	while (x < cub->resX)
	{
		init_raydir_x_y(cub, x);
		set_raydir_x_y(cub);
		hit_raydir_x_y(cub);
		size_raydir_x_y(cub);
		print_raydir_x_y(cub, x);
		x++;
	}
	sprites_print(cub);
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.mlx_win, cub->mlx.img, 0, 0);
	if (cub->save_parm == 1)
		main_bmp(cub);
	mlx_destroy_image(cub->mlx.mlx, cub->mlx.img);
	return (0);
}

void	raycast(t_cube *cub)
{
	if (cub->save_parm == 1 && (cub->resX > 16384 || cub->resY > 16384))
		ft_msgerror("Max. resolution for BMP is exceeded.", 6);
	init_ray(cub);
	stg_tex(cub);
	sprites(cub);
	mlx_hook(cub->mlx.mlx_win, 2, 1L << 0, key_press, cub);
	mlx_hook(cub->mlx.mlx_win, 3, 1L << 1, key_relea, cub);
	mlx_hook(cub->mlx.mlx_win, 17, 1L << 17, ui_cross_exit, cub);
	mlx_loop_hook(cub->mlx.mlx, raycast_loop, cub);
	mlx_loop(cub->mlx.mlx);
}
