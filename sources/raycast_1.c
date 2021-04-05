/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:07:38 by juasanto          #+#    #+#             */
/*   Updated: 2021/04/05 13:59:35 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include <math.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

int	to_rgb(int r, int g, int b)
{
	return ((b * 1) + (g * 256) + (r * 256 * 256));
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	test(t_cube *cub, t_map *map)
{
	void	*mlx;
	void	*mlx_win;
	int		cnt_x;
	int		cnt_y;
	int		radius;
	int		color;
	t_data	img;

	map->temp = 0;
	cnt_x = 0;
	cnt_y = 0;
	radius = 10;
	color = to_rgb(cub->p_fr, cub->p_fg, cub->p_fb);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, cub->p_rx, cub->p_ry, cub->f_name);
	img.img = mlx_new_image(mlx, cub->p_rx, cub->p_ry);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (cnt_x++ < 100)
	{
		while (cnt_y++ < 100)
			my_mlx_pixel_put(&img, cnt_x, cnt_y, color);
		cnt_y = 0;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

    // mlx = mlx_init();
    // mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    // img.img = mlx_new_image(mlx, 1920, 1080);
    // img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
    //                              &img.endian);
    // my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
    // mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    // mlx_loop(mlx);
