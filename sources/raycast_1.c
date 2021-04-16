/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:07:38 by juasanto          #+#    #+#             */
/*   Updated: 2021/04/16 11:53:01 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		raycast_loop(t_cube *cub);

int	to_rgb(int r, int g, int b)
{
	return ((b * 1) + (g * 256) + (r * 256 * 256));
}

void	my_mlx_pixel_put(t_cube *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->mlx.addr + (y * cub->mlx.line_length + x * (cub->mlx.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_cube *cub)
{
	printf("keykode: %i\n", keycode);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(cub->mlx.mlx, cub->mlx.mlx_win);
		exit (0);
	}
	if (keycode == KEY_FW)
		move_fw(cub);
	if (keycode == KEY_BW)
		move_bw(cub);
	if (keycode == KEY_RL)
		move_rl(cub);
	if (keycode == KEY_RR)
		move_rr(cub);
	if (keycode == KEY_SL)
		move_sl(cub);
	if (keycode == KEY_SR)
		move_sr(cub);
	raycast_loop (cub);
	return (0);
}
void	set_raydir_x_y(t_cube *cub)
{
	if(cub->ray.rayDirX < 0)
	{
		cub->ray.stepX = -1;
		cub->ray.sideDistX = (cub->pyr.posX - cub->ray.mapX) * cub->ray.deltaDistX;
	}
	else
	{
		cub->ray.stepX = 1;
		cub->ray.sideDistX = (cub->ray.mapX + 1.0 - cub->pyr.posX) * cub->ray.deltaDistX;
	}
	if(cub->ray.rayDirY < 0)
	{
		cub->ray.stepY = -1;
		cub->ray.sideDistY = (cub->pyr.posY - cub->ray.mapY) * cub->ray.deltaDistY;
	}
	else
	{
		cub->ray.stepY = 1;
		cub->ray.sideDistY = (cub->ray.mapY + 1.0 - cub->pyr.posY) * cub->ray.deltaDistY;
	}

}

int		raycast_loop(t_cube *cub)
{
	int	x;

	x = 0;
	cub->mlx.img = mlx_new_image(cub->mlx.mlx, cub->resX, cub->resY);
	cub->mlx.addr = mlx_get_data_addr(cub->mlx.img, &cub->mlx.bits_per_pixel, &cub->mlx.line_length, &cub->mlx.endian);
	while (x < cub->resX)
	{

		cub->ray.cameraX = 2 * x / (double)(cub->resX) - 1;
		cub->ray.rayDirX = cub->ray.dirX + cub->ray.planeX * cub->ray.cameraX;
		cub->ray.rayDirY = cub->ray.dirY + cub->ray.planeY * cub->ray.cameraX;
		cub->ray.mapX = (int)cub->pyr.posX;
		cub->ray.mapY = (int)cub->pyr.posY;
		cub->ray.deltaDistX = fabs(1 / cub->ray.rayDirX);
		cub->ray.deltaDistY = fabs(1 / cub->ray.rayDirY);
		cub->ray.hit = 0;
		set_raydir_x_y(cub);
		while (cub->ray.hit == 0)
		{
			if(cub->ray.sideDistX < cub->ray.sideDistY)
			{
				cub->ray.sideDistX += cub->ray.deltaDistX;
				cub->ray.mapX += cub->ray.stepX;
				cub->ray.side = 0;
			}
			else
			{
				cub->ray.sideDistY += cub->ray.deltaDistY;
				cub->ray.mapY += cub->ray.stepY;
				cub->ray.side = 1;
			}
			if(cub->wrk_map[cub->ray.mapX][cub->ray.mapY] > '0')
				cub->ray.hit = 1;
		}
		if(cub->ray.side == 0)
			cub->ray.perpWallDist = (cub->ray.mapX - cub->pyr.posX + (1 - cub->ray.stepX) / 2) / cub->ray.rayDirX;
		else
			cub->ray.perpWallDist = (cub->ray.mapY - cub->pyr.posY + (1 - cub->ray.stepY) / 2) / cub->ray.rayDirY;
		cub->ray.lineHeight = (int)(cub->resY / cub->ray.perpWallDist);
		cub->ray.drawStart = -cub->ray.lineHeight / 2 + cub->resY / 2;
		if(cub->ray.drawStart < 0)
			cub->ray.drawStart = 0;
		cub->ray.drawEnd = cub->ray.lineHeight / 2 + cub->resY / 2;
		if(cub->ray.drawEnd >= cub->resY)
			cub->ray.drawEnd = cub->resY - 1;

		int		y;

		y = 0;
		while(y < cub->resY)
		{
			if (y < cub->ray.drawStart)
				my_mlx_pixel_put(cub, x, y, cub->c_color);
			else if (y >= cub->ray.drawStart && y <= cub->ray.drawEnd)
				my_mlx_pixel_put(cub, x, y, 0x0000FF);
			else if (y > cub->ray.drawEnd)
				my_mlx_pixel_put(cub, x, y, cub->f_color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.mlx_win, cub->mlx.img, 0, 0);
	mlx_destroy_image(cub->mlx.mlx, cub->mlx.img);
	return(0);
}

void	test(t_cube *cub)
{
	cub->ray.dirX = -1;
	cub->ray.dirY = 0;
	cub->ray.planeX = 0;
	cub->ray.planeY = 0.66;
	cub->f_color = to_rgb(cub->p_fr, cub->p_fg, cub->p_fb);
	cub->c_color = to_rgb(cub->p_cr, cub->p_cg, cub->p_cb);
	cub->ray.moveSpeed = 0.15;
	cub->ray.rotSpeed = 0.25;
	cub->wrk_map[(int)cub->pyr.posX][(int)cub->pyr.posY] = 48;
	cub->mlx.mlx = mlx_init();
	cub->mlx.mlx_win = mlx_new_window(cub->mlx.mlx, cub->resX, cub->resY, cub->f_name);
	mlx_key_hook(cub->mlx.mlx_win, key_hook, cub);
	mlx_loop_hook(cub->mlx.mlx, raycast_loop, cub);
	mlx_loop(cub->mlx.mlx);
}
