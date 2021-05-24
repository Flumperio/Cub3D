/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 10:19:53 by juasanto          #+#    #+#             */
/*   Updated: 2021/05/17 17:21:46 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	sprites(t_cube *cub)
{
	int	cnt;
	int	max;

	cnt = -1;
	max = cub->cnt_2;
	while (++cnt < max)
		cub->osp[cnt].spriteDistance = ((cub->pyr.posX - cub->osp[cnt].x_pos)
				* (cub->pyr.posX - cub->osp[cnt].x_pos)
				+ (cub->pyr.posY - cub->osp[cnt].y_pos)
				* (cub->pyr.posY - cub->osp[cnt].y_pos));
	sprites_sort (cub, 0, max - 1);
	cnt = 0;
}

void	sprites_calc(t_cube *cub, int cnt)
{
	cub->spr.uDiv = 1;
	cub->spr.vDiv = 1;
	cub->spr.vMove = 0;
	cub->spr.spriteX = cub->osp[cnt].x_pos - cub->pyr.posX;
	cub->spr.spriteY = cub->osp[cnt].y_pos - cub->pyr.posY;
	cub->spr.invDet = 1.0 / (cub->ray.planeX * cub->ray.dirY
			- cub->ray.dirX * cub->ray.planeY);
	cub->spr.transformX = cub->spr.invDet * (cub->ray.dirY
			* cub->spr.spriteX - cub->ray.dirX * cub->spr.spriteY);
	cub->spr.transformY = cub->spr.invDet * (-cub->ray.planeY
			* cub->spr.spriteX + cub->ray.planeX * cub->spr.spriteY);
	cub->spr.vMoveScreen = (int)(cub->spr.vMove / cub->spr.transformY);
	cub->spr.spriteScreenX = (int)((cub->resX / 2)
			* (1 + cub->spr.transformX / cub->spr.transformY));
	cub->spr.spriteHeight = abs((int)(cub->resY
				/ (cub->spr.transformY))) / cub->spr.vDiv;
	cub->spr.drawStartY = -cub->spr.spriteHeight
		/ 2 + cub->resY / 2 + cub->spr.vMoveScreen;
	if (cub->spr.drawStartY < 0)
		cub->spr.drawStartY = 0;
	cub->spr.drawEndY = cub->spr.spriteHeight
		/ 2 + cub->resY / 2 + cub->spr.vMoveScreen;
	if (cub->spr.drawEndY >= cub->resY)
		cub->spr.drawEndY = cub->resY - 1;
}

void	sprites_calc2(t_cube *cub)
{
	cub->spr.spriteWidth = abs((int)(cub->resY
				/ (cub->spr.transformY))) / cub->spr.uDiv;
	cub->spr.drawStartX = -cub->spr.spriteWidth
		/ 2 + cub->spr.spriteScreenX;
	if (cub->spr.drawStartX < 0)
		cub->spr.drawStartX = 0;
	cub->spr.drawEndX = cub->spr.spriteWidth / 2 + cub->spr.spriteScreenX;
	if (cub->spr.drawEndX >= cub->resX)
		cub->spr.drawEndX = cub->resX - 1;
}

void	sprites_draw(t_cube *cub, int stripe)
{
	int	color;
	int	cnt;
	int	spr_res;

	cnt = cub->spr.drawStartY;
	while (cnt < cub->spr.drawEndY)
	{
		spr_res = (cnt - cub->spr.vMoveScreen) * 256 - cub->resY
			* 128 + cub->spr.spriteHeight * 128;
		cub->ptx.texY = ((spr_res * cub->stx->height)
				/ cub->spr.spriteHeight) / 256;
		color = my_get_color_pixel(cub, cub->ptx.texX, cub->ptx.texY);
		if ((color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(cub, stripe, cnt, color);
		cnt++;
	}
}

void	sprites_print(t_cube *cub)
{
	int	cnt;
	int	stripe;

	cnt = 0;
	cub->ptx.texNum = 4;
	sprites(cub);
	while (cnt < cub->cnt_2)
	{
		sprites_calc(cub, cnt);
		sprites_calc2(cub);
		stripe = cub->spr.drawStartX;
		while (stripe < cub->spr.drawEndX)
		{
			cub->ptx.texX = (int)(256 * (stripe - (-cub->spr.spriteWidth
							/ 2 + cub->spr.spriteScreenX)) * cub->stx->width
					/ cub->spr.spriteWidth) / 256;
			if (cub->spr.transformY > 0 && stripe > 0 && stripe < cub->resX
				&& cub->spr.transformY < cub->ZBuffer[stripe])
				sprites_draw(cub, stripe);
			stripe++;
		}
		cnt++;
	}
}
