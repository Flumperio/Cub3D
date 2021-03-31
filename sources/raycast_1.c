/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:07:38 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/31 14:13:28 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	deal_key(int key, void *param)
{
	key++;
	param++;
	printf("%i -- %i ", key, (int)param);
	return (0);
}
int	to_rgb(int r, int g, int b)
{
	return((b * 1) + (g * 256) + (r * 256 * 256));
}

void	test(t_cube *cub, t_map *map)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		size_x;
	int		size_y;
	int		color_f;
	int		color_c;
	int		*x = NULL;
	int		*y = NULL;

	size_x = 1;
	size_y = 1;
	*x = 1;
	*y = 1;
	map->temp = 0;
	cub->tmp = 0;
	color_f = to_rgb(cub->p_fr, cub->p_fg, cub->p_fb);
	color_c = to_rgb(cub->p_cr, cub->p_cg, cub->p_cb);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, cub->p_rx, cub->p_ry, cub->f_name);
	while (size_x++ < 100)
	{
		while (size_y++ < 100)
		{
			mlx_pixel_put (mlx_ptr, win_ptr, size_x, size_y, color_f);
		}
		size_y = 0;
	}
	size_x = 1;
	size_y = 1;
	while (size_x++ < 100)
	{
		while (size_y++ < 100)
		{
			mlx_pixel_put (mlx_ptr, win_ptr, size_x + 100, size_y + 100, color_c);
		}
		size_y = 0;
	}
	//mlx_xpm_file_to_image(mlx_ptr, cub->tex[0].path, x, y);
	//mlx_key_hook (win_ptr, deal_key, (void *) 0);
	mlx_loop(mlx_ptr);
}
