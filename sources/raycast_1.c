/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:07:38 by juasanto          #+#    #+#             */
/*   Updated: 2021/04/09 13:52:38 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include <math.h>

typedef struct s_ray
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
}			t_ray;

int	to_rgb(int r, int g, int b)
{
	return ((b * 1) + (g * 256) + (r * 256 * 256));
}

void	my_mlx_pixel_put(t_ray *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_ray *img)
{
	printf("Val: %i -- x: %i\n", keycode, img->x);
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->mlx_win);
		exit (0);
	}
	// if (keycode == 1)
	// {
	// 	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 1, 1);
	// 			my_mlx_pixel_put(img, img->x, img->y, 0xFFFFFF);
	// 	img->y++;
	// }
	// if (keycode == 0)
	// {
	// 	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 1, 1);
	// 			my_mlx_pixel_put(img, img->x, img->y, 0xFFFFFF);
	// 	img->x--;
	// }
	// if (keycode == 2)
	// {
	// 	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 1, 1);
	// 			my_mlx_pixel_put(img, img->x, img->y, 0xFFFFFF);
	// 	img->x++;
	// }
	return (0);
}

int	mouse_hook (int x, int y, t_ray *img)
{
	printf("X: %i -- Y: %i\n", x, y);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 1, 1);
	my_mlx_pixel_put(img, x, y, 0xFFFFFF);
	return (0);
}

void	test(t_cube *cub, t_map *map)
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	time;
	double	oldTime;
	t_ray	ray;

	map->temp = 0;
	posX = cub->pl_posx;
	posY = cub->pl_posy;
	dirX = -1;
	dirY = 0;
	planeX = 0;
	planeY = 0.66;
	time = 0;
	oldTime = 0;
	ray.mlx = mlx_init();
	ray.mlx_win = mlx_new_window(ray.mlx, cub->p_rx, cub->p_ry, cub->f_name);
	ray.img = mlx_new_image(ray.mlx, cub->p_rx, cub->p_ry);
	ray.addr = mlx_get_data_addr(ray.img, &ray.bits_per_pixel, &ray.line_length, &ray.endian);

	mlx_loop(ray.mlx);
}
