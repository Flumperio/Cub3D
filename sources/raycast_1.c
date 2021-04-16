/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:07:38 by juasanto          #+#    #+#             */
/*   Updated: 2021/04/16 09:16:58 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
#include <math.h>

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
	printf("keykode: %i\n", keycode, cub->ray.planeX);
	if (keycode == 53)
	{
		mlx_destroy_window(cub->mlx.mlx, cub->mlx.mlx_win);
		exit (0);
	}
	if (keycode == 1)
	{
		cub->pyr.posX -= cub->ray.dirX * cub->ray.moveSpeed;
		cub->pyr.posY -= cub->ray.dirY * cub->ray.moveSpeed;
	}
	if (keycode == 13)
	{
		cub->pyr.posX += cub->ray.dirX * cub->ray.moveSpeed;
		cub->pyr.posY += cub->ray.dirY * cub->ray.moveSpeed;
	}
	if (keycode == 12)
	{
		cub->pyr.posX -= cub->ray.dirY * cub->ray.moveSpeed;
		cub->pyr.posY += cub->ray.dirX * cub->ray.moveSpeed;
	}
	if (keycode == 14)
	{
		cub->pyr.posX += cub->ray.dirY * cub->ray.moveSpeed;
		cub->pyr.posY -= cub->ray.dirX * cub->ray.moveSpeed;
	}
	if (keycode == 2)
	{
      cub->ray.oldDirX = cub->ray.dirX;
      cub->ray.dirX = cub->ray.dirX * cos(-cub->ray.rotSpeed) - cub->ray.dirY * sin(-cub->ray.rotSpeed);
      cub->ray.dirY = cub->ray.oldDirX * sin(-cub->ray.rotSpeed) + cub->ray.dirY * cos(-cub->ray.rotSpeed);
      cub->ray.oldPlaneX = cub->ray.planeX;
      cub->ray.planeX = cub->ray.planeX * cos(-cub->ray.rotSpeed) - cub->ray.planeY * sin(-cub->ray.rotSpeed);
      cub->ray.planeY = cub->ray.oldPlaneX * sin(-cub->ray.rotSpeed) + cub->ray.planeY * cos(-cub->ray.rotSpeed);
	}
	if (keycode == 0)
	{
      cub->ray.oldDirX = cub->ray.dirX;
      cub->ray.dirX = cub->ray.dirX * cos(cub->ray.rotSpeed) - cub->ray.dirY * sin(cub->ray.rotSpeed);
      cub->ray.dirY = cub->ray.oldDirX * sin(cub->ray.rotSpeed) + cub->ray.dirY * cos(cub->ray.rotSpeed);
      cub->ray.oldPlaneX = cub->ray.planeX;
      cub->ray.planeX = cub->ray.planeX * cos(cub->ray.rotSpeed) - cub->ray.planeY * sin(cub->ray.rotSpeed);
      cub->ray.planeY = cub->ray.oldPlaneX * sin(cub->ray.rotSpeed) + cub->ray.planeY * cos(cub->ray.rotSpeed);
	}
	raycast_loop (cub);
	return (0);
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
				my_mlx_pixel_put(cub, x, y, ray->f_color);
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
	double	time;
	double	oldTime;
	int		cnt;
	t_ray	rayyy;

	cnt = 0;
	ft_bzero(&rayyy, sizeof(t_ray));
	// ray.map = ft_calloc(cub->cnt_map + 1, sizeof(char **));
	// while (cub->wrk_map[cnt] != NULL)
	// {
	// 	ray.map[cnt] = ft_strdup(cub->wrk_map[cnt]);
	// 	cnt++;
	// }

	// ray.posX = cub->pl_posx + 0.5;
	// ray.posY = cub->pl_posy + 0.5;
	cub->ray.dirX = -1;
	cub->ray.dirY = 0;
	cub->ray.planeX = 0;
	cub->ray.planeY = 0.66;
	// cub->ray.res_X = cub->p_rx;
	// cub->ray.res_Y = cub->p_ry;
	cub->ray.f_color = to_rgb(cub->p_fr, cub->p_fg, cub->p_fb);
	cub->ray.c_color = to_rgb(cub->p_cr, cub->p_cg, cub->p_cb);
	cub->ray.moveSpeed = 0.15;
	cub->ray.rotSpeed = 0.25;
	cub->wrk_map[(int)cub->pyr.posX][(int)cub->pyr.posY] = 48;
	time = 0;
	oldTime = 0;
	cub->mlx.mlx = mlx_init();
	cub->mlx.mlx_win = mlx_new_window(cub->mlx.mlx, cub->resX, cub->resY, cub->f_name);

	mlx_key_hook(cub->mlx.mlx_win, key_hook, &cub);

	mlx_loop_hook(cub->mlx.mlx, raycast_loop, &cub);
	mlx_loop(cub->mlx.mlx);
}
