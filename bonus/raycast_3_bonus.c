/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:17:15 by juasanto          #+#    #+#             */
/*   Updated: 2021/05/11 16:12:40 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

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

void	set_fc_id(t_cube *cub)
{
	if (cub->ray.side == 0 && cub->ray.rayDirX > 0)
	{
		cub->ptx.floorXWall = cub->ray.mapX;
		cub->ptx.floorYWall = cub->ray.mapY + cub->ptx.wallX;
	}
	else if (cub->ray.side == 0 && cub->ray.rayDirX < 0)
	{
		cub->ptx.floorXWall = cub->ray.mapX + 1.0;
		cub->ptx.floorYWall = cub->ray.mapY + cub->ptx.wallX;
	}
	else if (cub->ray.side == 1 && cub->ray.rayDirY > 0)
	{
		cub->ptx.floorXWall = cub->ray.mapX + cub->ptx.wallX;
		cub->ptx.floorYWall = cub->ray.mapY;
	}
	else
	{
		cub->ptx.floorXWall = cub->ray.mapX + cub->ptx.wallX;
		cub->ptx.floorYWall = cub->ray.mapY + 1.0;
	}
}

void	text_calc(t_cube *cub)
{
	set_tex_id(cub);
	if (cub->ray.side == 0)
		cub->ptx.wallX = cub->pyr.posY + cub->ray.perpWallDist
			* cub->ray.rayDirY;
	else
		cub->ptx.wallX = cub->pyr.posX + cub->ray.perpWallDist
			* cub->ray.rayDirX;
	cub->ptx.wallX -= (int)fabs(cub->ptx.wallX);
	cub->ptx.texX = (int)(cub->ptx.wallX
			* (double)cub->stx[cub->ptx.texNum].width);
	if (cub->ray.side == 0 && cub->ray.rayDirX > 0)
		cub->ptx.texX = cub->stx[cub->ptx.texNum].width - cub->ptx.texX - 1;
	if (cub->ray.side == 1 && cub->ray.rayDirY < 0)
		cub->ptx.texX = cub->stx[cub->ptx.texNum].width - cub->ptx.texX - 1;
}

int	paint_wall(t_cube *cub, int x, int y)
{
	int	color;

	text_calc(cub);
	cub->ptx.step = 1.0 * cub->stx[cub->ptx.texNum].height
		/ cub->ray.lineHeight;
	cub->ptx.textPos = (cub->ray.drawStart - cub->resY
			/ 2 + cub->ray.lineHeight / 2) * cub->ptx.step;
	while (y < cub->ray.drawEnd)
	{
		cub->ptx.texY = (int)cub->ptx.textPos
			& (cub->stx[cub->ptx.texNum].height - 1);
		cub->ptx.textPos += cub->ptx.step;
		color = my_get_color_pixel(cub, cub->ptx.texX, cub->ptx.texY);
		my_mlx_pixel_put(cub, x, y, color);
		y++;
	}
	return (y);
}

int	print_fc(t_cube *cub, int x, int y, int max_y)
{
	while (y < max_y)
	{
		cub->ptx.currentDist = cub->resY / (2.0 * y - cub->resY);
		cub->ptx.weight = (cub->ptx.currentDist - cub->ptx.distPlayer)
			/ (cub->ptx.distWall - cub->ptx.distPlayer);
		cub->ptx.currentFloorX = cub->ptx.weight * cub->ptx.floorXWall
			+ (1.0 - cub->ptx.weight) * cub->pyr.posX;
		cub->ptx.currentFloorY = cub->ptx.weight * cub->ptx.floorYWall
			+ (1.0 - cub->ptx.weight) * cub->pyr.posY;
		cub->ptx.floorTexX = (int)(cub->ptx.currentFloorX
				* cub->stx[cub->ptx.texNum].width)
			% cub->stx[cub->ptx.texNum].width;
		cub->ptx.floorTexY = (int)(cub->ptx.currentFloorY
				* cub->stx[cub->ptx.texNum].height)
			% cub->stx[cub->ptx.texNum].height;
		my_mlx_pixel_put(cub, x, y, my_get_color_pixel(cub, cub->ptx.floorTexX,
				cub->ptx.floorTexY));
		y++;
	}
	return (y);
}
