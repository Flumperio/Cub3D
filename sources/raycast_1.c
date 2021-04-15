/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:07:38 by juasanto          #+#    #+#             */
/*   Updated: 2021/04/15 19:33:35 by juasanto         ###   ########.fr       */
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
	printf("keykode: %i\n", keycode, cub->ray.oldDirX);
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
      cub->ray.dirX = cub->ray.dirX * cos(-ray->rotSpeed) - cub->ray.dirY * sin(-ray->rotSpeed);
      cub->ray.dirY = cub->ray.oldDirX * sin(-ray->rotSpeed) + cub->ray.dirY * cos(-ray->rotSpeed);
      ray->oldPlaneX = ray->planeX;
      ray->planeX = ray->planeX * cos(-ray->rotSpeed) - ray->planeY * sin(-ray->rotSpeed);
      ray->planeY = ray->oldPlaneX * sin(-ray->rotSpeed) + ray->planeY * cos(-ray->rotSpeed);
	}
	if (keycode == 0)
	{
      cub->ray.oldDirX = cub->ray.dirX;
      cub->ray.dirX = cub->ray.dirX * cos(ray->rotSpeed) - cub->ray.dirY * sin(ray->rotSpeed);
      cub->ray.dirY = cub->ray.oldDirX * sin(ray->rotSpeed) + cub->ray.dirY * cos(ray->rotSpeed);
      ray->oldPlaneX = ray->planeX;
      ray->planeX = ray->planeX * cos(ray->rotSpeed) - ray->planeY * sin(ray->rotSpeed);
      ray->planeY = ray->oldPlaneX * sin(ray->rotSpeed) + ray->planeY * cos(ray->rotSpeed);
	}
	raycast_loop (ray);
	return (0);
}

int		raycast_loop(t_cube *cub)
{
	int	x;

	x = 0;
	cub->mlx.img = mlx_new_image(cub->mlx.mlx, ray->res_X, ray->res_Y);
	cub->mlx.addr = mlx_get_data_addr(cub->mlx.img, &cub->mlx.bits_per_pixel, &cub->mlx.line_length, &cub->mlx.endian);
	while (x < ray->res_X)
	{

		ray->cameraX = 2 * x / (double)(ray->res_X) - 1;
		ray->rayDirX = cub->ray.dirX + ray->planeX * ray->cameraX;
		ray->rayDirY = cub->ray.dirY + ray->planeY * ray->cameraX;
		ray->mapX = (int)cub->pyr.posX;
		ray->mapY = (int)cub->pyr.posY;
		ray->deltaDistX = fabs(1 / ray->rayDirX);
		ray->deltaDistY = fabs(1 / ray->rayDirY);
		ray->hit = 0;
		if(ray->rayDirX < 0)
		{
			ray->stepX = -1;
			ray->sideDistX = (cub->pyr.posX - ray->mapX) * ray->deltaDistX;
		}
		else
		{
			ray->stepX = 1;
			ray->sideDistX = (ray->mapX + 1.0 - cub->pyr.posX) * ray->deltaDistX;
		}
		if(ray->rayDirY < 0)
		{
			ray->stepY = -1;
			ray->sideDistY = (cub->pyr.posY - ray->mapY) * ray->deltaDistY;
		}
		else
		{
			ray->stepY = 1;
			ray->sideDistY = (ray->mapY + 1.0 - cub->pyr.posY) * ray->deltaDistY;
		}
		while (ray->hit == 0)
		{
			if(ray->sideDistX < ray->sideDistY)
			{
				ray->sideDistX += ray->deltaDistX;
				ray->mapX += ray->stepX;
				ray->side = 0;
			}
			else
			{
				ray->sideDistY += ray->deltaDistY;
				ray->mapY += ray->stepY;
				ray->side = 1;
			}
			if(ray->map[ray->mapX][ray->mapY] > '0')
				ray->hit = 1;
		}
		if(ray->side == 0)
			ray->perpWallDist = (ray->mapX - cub->pyr.posX + (1 - ray->stepX) / 2) / ray->rayDirX;
		else
			ray->perpWallDist = (ray->mapY - cub->pyr.posY + (1 - ray->stepY) / 2) / ray->rayDirY;
		ray->lineHeight = (int)(ray->res_Y / ray->perpWallDist);
		ray->drawStart = -ray->lineHeight / 2 + ray->res_Y / 2;
		if(ray->drawStart < 0)
			ray->drawStart = 0;
		ray->drawEnd = ray->lineHeight / 2 + ray->res_Y / 2;
		if(ray->drawEnd >= ray->res_Y)
			ray->drawEnd = ray->res_Y - 1;

		int		y;

		y = 0;
		while(y < ray->res_Y)
		{
			if (y < ray->drawStart)
				my_mlx_pixel_put(ray, x, y, ray->c_color);
			else if (y >= ray->drawStart && y <= ray->drawEnd)
				my_mlx_pixel_put(ray, x, y, 0x0000FF);
			else if (y > ray->drawEnd)
				my_mlx_pixel_put(ray, x, y, ray->f_color);
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
	cub->ray.res_X = cub->p_rx;
	cub->ray.res_Y = cub->p_ry;
	cub->ray.f_color = to_rgb(cub->p_fr, cub->p_fg, cub->p_fb);
	cub->ray.c_color = to_rgb(cub->p_cr, cub->p_cg, cub->p_cb);
	cub->ray.moveSpeed = 0.15;
	cub->ray.rotSpeed = 0.25;
	cub->wrk_map[cub->pyr.posX][cub->pyr.posY] = 48;
	time = 0;
	oldTime = 0;
	cub->mlx.mlx = mlx_init();
	cub->mlx.mlx_win = mlx_new_window(cub->mlx.mlx, cub->p_rx, cub->p_ry, cub->f_name);

	mlx_key_hook(cub->mlx.mlx_win, key_hook, &cub);

	mlx_loop_hook(cub->mlx.mlx, raycast_loop, &cub);
	mlx_loop(cub->mlx.mlx);
}
