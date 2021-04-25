/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:07:38 by juasanto          #+#    #+#             */
/*   Updated: 2021/04/25 13:46:30 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	to_rgb(int r, int g, int b)
{
	return ((b * 1) + (g * 256) + (r * 256 * 256));
}

void	my_mlx_pixel_put(t_cube *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->mlx.addr + (y * cub->mlx.line_length + \
		x * (cub->mlx.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	my_get_color_pixel(t_cube *cub, int x, int y)
{
	char	*dst;

	dst = cub->stx[cub->ptx.texNum].addr + (y * cub->stx[cub->ptx.texNum].ll + x * (cub->stx[cub->ptx.texNum].bpp / 8));
	return (*(unsigned int*)dst);
}

void	stg_tex(t_cube *cub)
{
	int	cnt;

	cnt = 0;
	while (cnt <= 5)
	{
		cub->stx[cnt].img = mlx_xpm_file_to_image(cub->mlx.mlx, cub->tex[cnt].path, &cub->stx[cnt].width, &cub->stx[cnt].height);
		cub->stx[cnt].addr = mlx_get_data_addr(cub->stx[cnt].img, &cub->stx[cnt].bpp, &cub->stx[cnt].ll, &cub->stx[cnt].e);
		cnt++;
	}
}


void	set_color_wall(t_cube *cub)
{
	if (cub->ray.side == 0 && cub->ray.rayDirX > 0)
		cub->ray.wall_color = to_rgb(153, 0, 0); /** Norte **/
	if (cub->ray.side == 0 && cub->ray.rayDirX <= 0)
		cub->ray.wall_color = to_rgb(0, 153, 0); /** Sur **/
	if (cub->ray.side == 1 && cub->ray.rayDirY > 0)
		cub->ray.wall_color = to_rgb(0, 0, 153); /** Este **/
	if (cub->ray.side == 1 && cub->ray.rayDirY <= 0)
		cub->ray.wall_color = to_rgb(153, 153, 153); /** Oeste **/
}

void	set_tex_id(t_cube *cub)
{
	if (cub->ray.side == 0 && cub->ray.rayDirX > 0)
		cub->ptx.texNum = NO;
	if (cub->ray.side == 0 && cub->ray.rayDirX <= 0)
		cub->ptx.texNum = SO;
	if (cub->ray.side == 1 && cub->ray.rayDirY > 0)
		cub->ptx.texNum = EA;
	if (cub->ray.side == 1 && cub->ray.rayDirY <= 0)
		cub->ptx.texNum = WE;
}

void	text_calc(t_cube *cub)
{
	set_tex_id(cub);
	if (cub->ray.side == 0)
		cub->ptx.wallX = cub->pyr.posY + cub->ray.perpWallDist * cub->ray.rayDirY;
	else
		cub->ptx.wallX = cub->pyr.posX + cub->ray.perpWallDist * cub->ray.rayDirX;
	cub->ptx.wallX -= floor(cub->ptx.wallX);
	cub->ptx.texX = (int)(cub->ptx.wallX * (double)cub->stx[cub->ptx.texNum].width);
	if (cub->ray.side == 0 && cub->ray.rayDirX > 0)
		cub->ptx.texX = cub->stx[cub->ptx.texNum].width - cub->ptx.texX - 1;
	if (cub->ray.side == 1 && cub->ray.rayDirY < 0)
		cub->ptx.texX = cub->stx[cub->ptx.texNum].width - cub->ptx.texX - 1;
}

int	paint_wall(t_cube *cub, int x, int y)
{
	int	color;

	cub->ptx.step = 1.0 * cub->stx[cub->ptx.texNum].height / cub->ray.lineHeight;
	cub->ptx.textPos = (cub->ray.drawStart - cub->resY / 2 + cub->ray.lineHeight / 2) * cub->ptx.step;
	while (y < cub->ray.drawEnd)
	{
		color = my_get_color_pixel(cub, cub->ptx.texX, cub->ptx.texY);
		if(cub->ray.side == 1)
			color = (color >> 1) & 8355711;
		cub->ptx.texY = (int)cub->ptx.textPos & (cub->stx[cub->ptx.texNum].height - 1);
		cub->ptx.textPos += cub->ptx.step;
		my_mlx_pixel_put(cub, x, y, color);
		y++;
	}
	return (y);
}

int	paint_floor(t_cube *cub, int x, int y)
{
	if (cub->ray.side == 0 && cub->ray.rayDirX > 0)
	{
		cub->ptx.floorXWall = cub->ray.mapX;
        cub->ptx.floorYWall = cub->ray.mapY + cub->ptx.wallX;
	}
	if (cub->ray.side == 0 && cub->ray.rayDirX <= 0)
	{
		cub->ptx.floorXWall = cub->ray.mapX + 1.0;
        cub->ptx.floorYWall = cub->ray.mapY + cub->ptx.wallX;
	}
	if (cub->ray.side == 1 && cub->ray.rayDirY > 0)
	{
		cub->ptx.floorXWall = cub->ray.mapX + cub->ptx.wallX;
        cub->ptx.floorYWall = cub->ray.mapY;
	}
	if (cub->ray.side == 1 && cub->ray.rayDirY <= 0)
	{
		cub->ptx.floorXWall = cub->ray.mapX + cub->ptx.wallX;
        cub->ptx.floorYWall = cub->ray.mapY + 1.0;
	}
	cub->ptx.distWall = cub->ray.perpWallDist;
    cub->ptx.distPlayer = 0.0;
	// if (cub->ray.drawEnd < 0)
	// 	cub->ray.drawEnd = cub->resY;
	while (y < cub->resY)
	{
	cub->ptx.currentDist = cub->resY / (2.0 * y - cub->resY); //you could make a small lookup table for this instead

	cub->ptx.weight = (cub->ptx.currentDist - cub->ptx.distPlayer) / (cub->ptx.distWall - cub->ptx.distPlayer);

	cub->ptx.currentFloorX = cub->ptx.weight * cub->ptx.floorXWall + (1.0 - cub->ptx.weight) * cub->pyr.posX;
	cub->ptx.currentFloorY = cub->ptx.weight * cub->ptx.floorYWall + (1.0 - cub->ptx.weight) * cub->pyr.posY;

	cub->ptx.floorTexX = (int)(cub->ptx.currentFloorX * cub->stx[cub->ptx.texNum].width) % cub->stx[cub->ptx.texNum].width;
	cub->ptx.floorTexY = (int)(cub->ptx.currentFloorY * cub->stx[cub->ptx.texNum].height) % cub->stx[cub->ptx.texNum].height;
	my_mlx_pixel_put(cub, x, y, my_get_color_pixel(cub, cub->ptx.floorTexX, cub->ptx.floorTexY));
	y++;
	}
	return (y);
}

void	print_raydir_x_y(t_cube *cub, int x)
{
	int		y;

	y = 0;

	text_calc(cub);
	while (y < cub->resY)
	{
		if (y < cub->ray.drawStart)
			my_mlx_pixel_put(cub, x, y, (int)(cub->c_color + cos(y)));
		else if (y >= cub->ray.drawStart && y <= cub->ray.drawEnd)
			y = paint_wall(cub, x, y);
		else if (y > cub->ray.drawEnd)
		{
			cub->ptx.texNum = 5;
			y = paint_floor(cub, x, y);
		}
		y++;
	}
}

int	raycast_loop(t_cube *cub)
{
	int	x;

	x = 0;
	pl_move(cub);
	cub->mlx.img = mlx_new_image(cub->mlx.mlx, cub->resX, cub->resY);
	cub->mlx.addr = mlx_get_data_addr(cub->mlx.img, &cub->mlx.bits_per_pixel, \
		&cub->mlx.line_length, &cub->mlx.endian);
	while (x < cub->resX)
	{
		init_raydir_x_y(cub, x);
		set_raydir_x_y(cub);
		hit_raydir_x_y(cub);
		size_raydir_x_y(cub);
		print_raydir_x_y(cub, x);
		x++;
	}
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.mlx_win, cub->mlx.img, 0, 0);
	mlx_destroy_image(cub->mlx.mlx, cub->mlx.img);
	return (0);
}

void	test(t_cube *cub)
{
	init_ray(cub);
	stg_tex(cub);
	mlx_hook(cub->mlx.mlx_win, 2, 1L << 0, key_press, cub);
	mlx_hook(cub->mlx.mlx_win, 3, 1L << 1, key_relea, cub);
	mlx_hook(cub->mlx.mlx_win, 17, 1L << 17, ui_cross_exit, cub);
	mlx_loop_hook(cub->mlx.mlx, raycast_loop, cub);
	mlx_loop(cub->mlx.mlx);
}
