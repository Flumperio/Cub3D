/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:07:38 by juasanto          #+#    #+#             */
/*   Updated: 2021/05/17 16:25:33 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	init_ray(t_cube *cub)
{
	int	cnt;

	cnt = 0;
	if (cub->pyr.view == 'N')
		cub->ray.dirX = -1;
	if (cub->pyr.view == 'S')
		cub->ray.dirX = 1;
	if (cub->pyr.view == 'E')
		cub->ray.dirY = 1;
	if (cub->pyr.view == 'W')
		cub->ray.dirY = -1;
	cub->ray.planeX = (cub->ray.dirY * ((FOV * M_PI) / 180));
	cub->ray.planeY = -(cub->ray.dirX * ((FOV * M_PI) / 180));
	cub->f_color = to_rgb(cub->p_fr, cub->p_fg, cub->p_fb);
	cub->c_color = to_rgb(cub->p_cr, cub->p_cg, cub->p_cb);
	cub->ray.moveSpeed = 0.045;
	cub->ray.rotSpeed = 0.035;
	cub->ZBuffer = ft_calloc(sizeof(double *), cub->resX + 1);
	cub->spr_l = ft_calloc(sizeof(t_spr), cub->cnt_2 + 1);
	cub->spr_d = ft_calloc(sizeof(t_spr), cub->cnt_2 + 1);
	cub->wrk_map[(int)cub->pyr.posX][(int)cub->pyr.posY] = 48;
	cub->mlx.mlx = mlx_init();
	cub->mlx.mlx_win = mlx_new_window(cub->mlx.mlx, \
		cub->resX, cub->resY, cub->f_name);
}

void	init_raydir_x_y(t_cube *cub, int x)
{
	cub->ray.cameraX = 2 * x / (double)(cub->resX) - 1;
	cub->ray.rayDirX = cub->ray.dirX + cub->ray.planeX * cub->ray.cameraX;
	cub->ray.rayDirY = cub->ray.dirY + cub->ray.planeY * cub->ray.cameraX;
	cub->ray.mapX = (int)cub->pyr.posX;
	cub->ray.mapY = (int)cub->pyr.posY;
	cub->ray.deltaDistX = fabs(1 / cub->ray.rayDirX);
	cub->ray.deltaDistY = fabs(1 / cub->ray.rayDirY);
	cub->ray.hit = 0;
}

void	set_raydir_x_y(t_cube *cub)
{
	if (cub->ray.rayDirX < 0)
	{
		cub->ray.stepX = -1;
		cub->ray.sideDistX = (cub->pyr.posX - cub->ray.mapX)
			* cub->ray.deltaDistX;
	}
	else
	{
		cub->ray.stepX = 1;
		cub->ray.sideDistX = (cub->ray.mapX + 1.0 - cub->pyr.posX)
			* cub->ray.deltaDistX;
	}
	if (cub->ray.rayDirY < 0)
	{
		cub->ray.stepY = -1;
		cub->ray.sideDistY = (cub->pyr.posY - cub->ray.mapY)
			* cub->ray.deltaDistY;
	}
	else
	{
		cub->ray.stepY = 1;
		cub->ray.sideDistY = (cub->ray.mapY + 1.0 - cub->pyr.posY)
			* cub->ray.deltaDistY;
	}
}

void	hit_raydir_x_y(t_cube *cub)
{
	while (cub->ray.hit == 0)
	{
		if (cub->ray.sideDistX < cub->ray.sideDistY)
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
		if (cub->wrk_map[cub->ray.mapX][cub->ray.mapY] > '0'
				&& cub->wrk_map[cub->ray.mapX][cub->ray.mapY] < '2')
			cub->ray.hit = 1;
	}
}

void	size_raydir_x_y(t_cube *cub)
{
	if (cub->ray.side == 0)
		cub->ray.perpWallDist = (cub->ray.mapX - cub->pyr.posX
				+ (1 - cub->ray.stepX) / 2) / cub->ray.rayDirX;
	else
		cub->ray.perpWallDist = (cub->ray.mapY - cub->pyr.posY
				+ (1 - cub->ray.stepY) / 2) / cub->ray.rayDirY;
	cub->ray.lineHeight = (int)(cub->resY / cub->ray.perpWallDist);
	cub->ray.drawStart = -cub->ray.lineHeight / 2 + cub->resY / 2;
	if (cub->ray.drawStart < 0)
		cub->ray.drawStart = 0;
	cub->ray.drawEnd = cub->ray.lineHeight / 2 + cub->resY / 2;
	if (cub->ray.drawEnd >= cub->resY)
		cub->ray.drawEnd = cub->resY - 1;
}
