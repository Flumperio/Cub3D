/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:07:38 by juasanto          #+#    #+#             */
/*   Updated: 2021/04/20 13:48:09 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		raycast_loop(t_cube *cub);
void	pl_move(t_cube *cub);

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

void	init_ray(t_cube *cub)
{
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
	cub->ray.moveSpeed = 0.035;
	cub->ray.rotSpeed = 0.035;
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
		cub->ray.sideDistX = (cub->pyr.posX - cub->ray.mapX) * \
			cub->ray.deltaDistX;
	}
	else
	{
		cub->ray.stepX = 1;
		cub->ray.sideDistX = (cub->ray.mapX + 1.0 - cub->pyr.posX) * \
			cub->ray.deltaDistX;
	}
	if (cub->ray.rayDirY < 0)
	{
		cub->ray.stepY = -1;
		cub->ray.sideDistY = (cub->pyr.posY - cub->ray.mapY) * \
			cub->ray.deltaDistY;
	}
	else
	{
		cub->ray.stepY = 1;
		cub->ray.sideDistY = (cub->ray.mapY + 1.0 - cub->pyr.posY) * \
			cub->ray.deltaDistY;
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
		if (cub->wrk_map[cub->ray.mapX][cub->ray.mapY] > '0')
			cub->ray.hit = 1;
	}
}

void	size_raydir_x_y(t_cube *cub)
{
	if (cub->ray.side == 0)
		cub->ray.perpWallDist = (cub->ray.mapX - cub->pyr.posX + \
			(1 - cub->ray.stepX) / 2) / cub->ray.rayDirX;
	else
		cub->ray.perpWallDist = (cub->ray.mapY - cub->pyr.posY + \
			(1 - cub->ray.stepY) / 2) / cub->ray.rayDirY;
	cub->ray.lineHeight = (int)(cub->resY / cub->ray.perpWallDist);
	cub->ray.drawStart = -cub->ray.lineHeight / 2 + cub->resY / 2;
	if (cub->ray.drawStart < 0)
		cub->ray.drawStart = 0;
	cub->ray.drawEnd = cub->ray.lineHeight / 2 + cub->resY / 2;
	if (cub->ray.drawEnd >= cub->resY)
		cub->ray.drawEnd = cub->resY - 1;
}

void	text_calc(t_cube *cub)
{
	int	y;

	y = cub->ray.drawStart;
	set_tex_id(cub);
	if (cub->ray.side == 0)
		cub->ptx.wallX = cub->pyr.posY + cub->ray.perpWallDist * cub->ray.rayDirY;
	else
		cub->ptx.wallX = cub->pyr.posX + cub->ray.perpWallDist * cub->ray.rayDirX;
	cub->ptx.wallX = fabs(cub->ptx.wallX);
	cub->ptx.texX = (int)(cub->ptx.wallX * TEXTWIDTH);
	if (cub->ray.side == 0 && cub->ray.rayDirX > 0)
		cub->ptx.texX = TEXTWIDTH - cub->ptx.texX - 1;
	if (cub->ray.side == 1 && cub->ray.rayDirY < 0)
		cub->ptx.texX = TEXTWIDTH - cub->ptx.texX - 1;
	/*
	** Increase Texture
	*/
	cub->ptx.step = 1.0 * TEXTHEIGHT / cub->ray.lineHeight;
	cub->ptx.textPos = (cub->ray.drawStart - cub->resY / 2 + cub->ray.lineHeight) * cub->ptx.step;
	while (y < cub->ray.drawEnd)
	{
		cub->ptx.texY = (int)cub->ptx.textPos & (TEXTHEIGHT - 1);
		cub->ptx.textPos += cub->ptx.step;
	}
}

void	print_raydir_x_y(t_cube *cub, int x)
{
	int		y;

	y = 0;
	set_color_wall(cub);
	while (y < cub->resY)
	{
		if (y < cub->ray.drawStart)
			my_mlx_pixel_put(cub, x, y, cub->c_color);
		else if (y >= cub->ray.drawStart && y <= cub->ray.drawEnd)
			my_mlx_pixel_put(cub, x, y, cub->ray.wall_color);
		else if (y > cub->ray.drawEnd)
			my_mlx_pixel_put(cub, x, y, cub->f_color);
		y++;
	}
}

int	ui_cross_exit(t_cube *cub)
{
	mlx_destroy_window(cub->mlx.mlx, cub->mlx.mlx_win);
	exit (0);
}

int	key_press(int keycode, t_cube *cub)
{
	printf("keykode: %i\n", keycode);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(cub->mlx.mlx, cub->mlx.mlx_win);
		exit (0);
	}
	if (keycode == KEY_FW)
		cub->bol.key_fw = 1;
	if (keycode == KEY_BW)
		cub->bol.key_bw = 1;
	if (keycode == KEY_RL)
		cub->bol.key_rl = 1;
	if (keycode == KEY_RR)
		cub->bol.key_rr = 1;
	if (keycode == KEY_SL)
		cub->bol.key_sl = 1;
	if (keycode == KEY_SR)
		cub->bol.key_sr = 1;
	return (0);
}

int	key_relea(int keycode, t_cube *cub)
{
	printf("keykode: %i\n", keycode);
	if (keycode == KEY_FW)
		cub->bol.key_fw = 0;
	if (keycode == KEY_BW)
		cub->bol.key_bw = 0;
	if (keycode == KEY_RL)
		cub->bol.key_rl = 0;
	if (keycode == KEY_RR)
		cub->bol.key_rr = 0;
	if (keycode == KEY_SL)
		cub->bol.key_sl = 0;
	if (keycode == KEY_SR)
		cub->bol.key_sr = 0;
	return (0);
}

void	pl_move(t_cube *cub)
{
	if (cub->bol.key_fw == 1)
		move_fw(cub);
	if (cub->bol.key_bw == 1)
		move_bw(cub);
	if (cub->bol.key_rl == 1)
		move_rl(cub);
	if (cub->bol.key_rr == 1)
		move_rr(cub);
	if (cub->bol.key_sl == 1)
		move_sl(cub);
	if (cub->bol.key_sr == 1)
		move_sr(cub);
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
	mlx_hook(cub->mlx.mlx_win, 2, 1L << 0, key_press, cub);
	mlx_hook(cub->mlx.mlx_win, 3, 1L << 1, key_relea, cub);
	mlx_hook(cub->mlx.mlx_win, 17, 1L << 17, ui_cross_exit, cub);
	mlx_loop_hook(cub->mlx.mlx, raycast_loop, cub);
	mlx_loop(cub->mlx.mlx);
}
