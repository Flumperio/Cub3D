/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:07:38 by juasanto          #+#    #+#             */
/*   Updated: 2021/04/06 11:55:27 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include <math.h>

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
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

int	key_hook(int keycode, t_data *img)
{
	printf("Val: %i -- x: %i\n", keycode, img->x);
	mlx_do_key_autorepeaton(img->mlx);
	if (keycode == 13)
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 1, 1);
		my_mlx_pixel_put(img, img->x, img->y, 0xFFFFFF);
		img->y--;
	}
	if (keycode == 1)
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 1, 1);
				my_mlx_pixel_put(img, img->x, img->y, 0xFFFFFF);
		img->y++;
	}
	if (keycode == 0)
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 1, 1);
				my_mlx_pixel_put(img, img->x, img->y, 0xFFFFFF);
		img->x--;
	}
	if (keycode == 2)
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 1, 1);
				my_mlx_pixel_put(img, img->x, img->y, 0xFFFFFF);
		img->x++;
	}
	return (0);
}

int	mouse_hook (int x, int y, t_data *img)
{
	printf("X: %i -- Y: %i\n", x, y);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 1, 1);
	my_mlx_pixel_put(img, x, y, 0xFFFFFF);
	return (0);
}

int	close_window (int keycode, t_data *img)
{
	printf("keycode: %i\n", keycode);
	mlx_destroy_window(img->mlx, img->mlx_win);
	return (0);
}

void	test(t_cube *cub, t_map *map)
{

	int		cnt_x;
	int		cnt_y;
	int		color;
	int		val;
	t_data	img;

	map->temp = 0;
	cnt_x = 0;
	cnt_y = 0;
	img.x = 1;
	img.y = 1;
	val = 0;
	color = to_rgb(cub->p_fr, cub->p_fg, cub->p_fb);
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, cub->p_rx, cub->p_ry, cub->f_name);
	img.img = mlx_new_image(img.mlx, cub->p_rx, cub->p_ry);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (cnt_x++ < 100)
	// {
	// 	while (cnt_y++ < 100)
	// 		my_mlx_pixel_put(&img, cnt_x, cnt_y, color);
	// 	cnt_y = 0;
	// }
	mlx_do_key_autorepeaton(img.mlx);
	//mlx_key_hook(img.mlx_win, key_hook, &img);
	//mlx_mouse_hook (img.mlx_win, mouse_hook, &img);
	mlx_hook(img.mlx_win, 2, 1L<<0, key_hook, &img);
	mlx_hook(img.mlx_win, 6, 1L<<6, mouse_hook, &img);
	mlx_loop(img.mlx);
}

    // mlx = mlx_init();
    // mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    // img.img = mlx_new_image(mlx, 1920, 1080);
    // img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
    //                              &img.endian);
    // my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
    // mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    // mlx_loop(mlx);
