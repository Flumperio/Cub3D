/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:07:38 by juasanto          #+#    #+#             */
/*   Updated: 2021/04/13 11:58:28 by juasanto         ###   ########.fr       */
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
	/* LODEV Variables */
	double	posX;
	double	posY;
	int		res_X;
	int		res_Y;
	int		mapX;
	int		mapY;
	int		pl_X;
	int		pl_Y;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	double	rotSpeed;
	double	moveSpeed;
	double	oldDirX;
	double	oldPlaneX;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	char	**map;
	int		f_color;
	int		c_color;

}			t_ray;

int		raycast_loop(t_ray *ray);

int	to_rgb(int r, int g, int b)
{
	return ((b * 1) + (g * 256) + (r * 256 * 256));
}

void	my_mlx_pixel_put(t_ray *ray, int x, int y, int color)
{
	char	*dst;

	dst = ray->addr + (y * ray->line_length + x * (ray->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_ray *ray)
{
	printf("keykode: %i\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(ray->mlx, ray->mlx_win);
		exit (0);
	}
	if (keycode == 1)
	{
		ray->posX -= ray->dirX * ray->moveSpeed;
		ray->posY -= ray->dirY * ray->moveSpeed;
	}
	if (keycode == 13)
	{
		ray->posX += ray->dirX * ray->moveSpeed;
		ray->posY += ray->dirY * ray->moveSpeed;
	}
	if (keycode == 14)
		ray->posY += 0.10;
	if (keycode == 12)
	{
		ray->posY -= ray->posY * ray->moveSpeed;
	}
	if (keycode == 2)
	{
      ray->oldDirX = ray->dirX;
      ray->dirX = ray->dirX * cos(-ray->rotSpeed) - ray->dirY * sin(-ray->rotSpeed);
      ray->dirY = ray->oldDirX * sin(-ray->rotSpeed) + ray->dirY * cos(-ray->rotSpeed);
      ray->oldPlaneX = ray->planeX;
      ray->planeX = ray->planeX * cos(-ray->rotSpeed) - ray->planeY * sin(-ray->rotSpeed);
      ray->planeY = ray->oldPlaneX * sin(-ray->rotSpeed) + ray->planeY * cos(-ray->rotSpeed);
	}
	if (keycode == 0)
	{
      ray->oldDirX = ray->dirX;
      ray->dirX = ray->dirX * cos(ray->rotSpeed) - ray->dirY * sin(ray->rotSpeed);
      ray->dirY = ray->oldDirX * sin(ray->rotSpeed) + ray->dirY * cos(ray->rotSpeed);
      ray->oldPlaneX = ray->planeX;
      ray->planeX = ray->planeX * cos(ray->rotSpeed) - ray->planeY * sin(ray->rotSpeed);
      ray->planeY = ray->oldPlaneX * sin(ray->rotSpeed) + ray->planeY * cos(ray->rotSpeed);
	}
	raycast_loop (ray);
	return (0);
}

int		raycast_loop(t_ray *ray)
{
	int	x;

	x = 0;
	ray->img = mlx_new_image(ray->mlx, ray->res_X, ray->res_Y);
	ray->addr = mlx_get_data_addr(ray->img, &ray->bits_per_pixel, &ray->line_length, &ray->endian);
	while (x < ray->res_X)
	{

		ray->cameraX = 2 * x / (double)(ray->res_X) - 1;
		ray->rayDirX = ray->dirX + ray->planeX * ray->cameraX;
		ray->rayDirY = ray->dirY + ray->planeY * ray->cameraX;
		ray->mapX = (int)ray->posX;
		ray->mapY = (int)ray->posY;
		ray->deltaDistX = fabs(1 / ray->rayDirX);
		ray->deltaDistY = fabs(1 / ray->rayDirY);
		ray->hit = 0;
		if(ray->rayDirX < 0)
		{
			ray->stepX = -1;
			ray->sideDistX = (ray->posX - ray->mapX) * ray->deltaDistX;
		}
		else
		{
			ray->stepX = 1;
			ray->sideDistX = (ray->mapX + 1.0 - ray->posX) * ray->deltaDistX;
		}
		if(ray->rayDirY < 0)
		{
			ray->stepY = -1;
			ray->sideDistY = (ray->posY - ray->mapY) * ray->deltaDistY;
		}
		else
		{
			ray->stepY = 1;
			ray->sideDistY = (ray->mapY + 1.0 - ray->posY) * ray->deltaDistY;
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
			ray->perpWallDist = (ray->mapX - ray->posX + (1 - ray->stepX) / 2) / ray->rayDirX;
		else
			ray->perpWallDist = (ray->mapY - ray->posY + (1 - ray->stepY) / 2) / ray->rayDirY;
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
	mlx_put_image_to_window(ray->mlx, ray->mlx_win, ray->img, 0, 0);
	mlx_destroy_image(ray->mlx, ray->img);
	return(0);
}

void	test(t_cube *cub, t_map *map)
{
	double	time;
	double	oldTime;
	int		cnt;
	t_ray	ray;

	map->temp = 0;
	cnt = 0;
	ft_bzero(&ray, sizeof(t_ray));
	ray.map = ft_calloc(cub->cnt_map + 1, sizeof(char **));
	while (cub->wrk_map[cnt] != NULL)
	{
		ray.map[cnt] = ft_strdup(cub->wrk_map[cnt]);
		cnt++;
	}
	ray.posX = cub->pl_posx + 0.5;
	ray.posY = cub->pl_posy + 0.5;
	ray.dirX = -1;
	ray.dirY = 0;
	ray.planeX = 0;
	ray.planeY = 0.66;
	ray.res_X = cub->p_rx;
	ray.res_Y = cub->p_ry;
	ray.f_color = to_rgb(cub->p_fr, cub->p_fg, cub->p_fb);
	ray.c_color = to_rgb(cub->p_cr, cub->p_cg, cub->p_cb);
	ray.moveSpeed = 0.15;
	ray.rotSpeed = 0.25;
	cub->wrk_map[cub->pl_posx][cub->pl_posy] = 48;
	time = 0;
	oldTime = 0;
	ray.mlx = mlx_init();
	ray.mlx_win = mlx_new_window(ray.mlx, cub->p_rx, cub->p_ry, cub->f_name);

	mlx_key_hook(ray.mlx_win, key_hook, &ray);

	mlx_loop_hook(ray.mlx, raycast_loop, &ray);
	mlx_loop(ray.mlx);
}
