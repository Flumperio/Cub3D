/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:07:38 by juasanto          #+#    #+#             */
/*   Updated: 2021/04/04 13:32:45 by juasanto         ###   ########.fr       */
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
	int		cnt;
	//void	*img[5];

	size_x = 1;
	size_y = 1;
	map->temp = 0;
	cub->tmp = 0;
	cnt = -1;
	color_f = to_rgb(cub->p_fr, cub->p_fg, cub->p_fb);
	color_c = to_rgb(cub->p_cr, cub->p_cg, cub->p_cb);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, cub->p_rx, cub->p_ry, cub->f_name);

	while (cnt++ < 4)
		cub->tex[cnt].img = mlx_xpm_file_to_image(mlx_ptr, cub->tex[cnt].path, &size_x, &size_y);
	size_x = 1;
	size_y = 1;
	cnt = 0;
	while (cnt <= 4)
	{
		while (size_x < (64 * 10))
			{
				mlx_put_image_to_window(mlx_ptr, win_ptr, cub->tex[cnt].img, size_x, size_y);
				size_x += 63;
			}
		cnt++;
		size_y += 63;
		size_x = 1;
	}
	//mlx_put_image_to_window(mlx_ptr, win_ptr, img, 10, 10);
	mlx_key_hook (win_ptr, deal_key, (void *) 0);
	mlx_loop(mlx_ptr);
}
