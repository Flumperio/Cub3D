/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 10:19:53 by juasanto          #+#    #+#             */
/*   Updated: 2021/05/12 16:19:51 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	merge(t_cube *cub, int l, int m, int r);

void sprites_sort(t_cube *cub, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		sprites_sort(cub, l, m);
		sprites_sort(cub, m + 1, r);
		merge(cub, l, m, r);
	}
}

void merge(t_cube *cub, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	t_osp	*SPR_L;
	t_osp 	*SPR_D;

	// t_spr SPR_L[n1];
	// t_spr SPR_D[n2];

	SPR_L = (t_osp *)ft_calloc(cub->cnt_2, sizeof (t_osp));
	SPR_D = (t_osp *)ft_calloc(cub->cnt_2, sizeof (t_osp));
	for (i = 0; i < n1; i++)
		SPR_L[i] = cub->osp[l + i];
	for (j = 0; j < n2; j++)
		SPR_D[j] = cub->osp[m + 1 + j];
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (SPR_L[i].spriteDistance >= SPR_D[j].spriteDistance) {
			cub->osp[k] = SPR_L[i];
			i++;
		}
		else {
			cub->osp[k] = SPR_D[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		cub->osp[k] = SPR_L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		cub->osp[k] = SPR_D[j];
		j++;
		k++;
	}
}

void	sprites(t_cube *cub)
{
	int	cnt;
	int	max;

	cnt = 0;
	max = cub->cnt_2;
	while(cnt < max)
	{
		cub->osp[cnt].spriteDistance = ((cub->pyr.posX - cub->osp[cnt].x_pos) * (cub->pyr.posX - cub->osp[cnt].x_pos) + (cub->pyr.posY - cub->osp[cnt].y_pos) * (cub->pyr.posY - cub->osp[cnt].y_pos));
		cnt++;
	}
	sprites_sort (cub, 0, max - 1);
	cnt = 0;
}

void	sprites_print (t_cube *cub)
{
	int	cnt;
	int	stripe;
	int	y;
	int	d;
	int	color;
	int max;
	int	tmp;
	int	uDiv;
	int	vDiv;
	double	vMove;
	int	vMoveScreen;

	uDiv = 1;
	vDiv = 1;
	vMove = 0.0;
	tmp = 0;
	cnt = 0;
	max = cub->cnt_2;
	cub->ptx.texNum = 4;
	sprites(cub);
	while(cnt < max)
	{
		cub->spr.spriteX = cub->osp[cnt].x_pos - cub->pyr.posX;
		cub->spr.spriteY = cub->osp[cnt].y_pos - cub->pyr.posY;

		cub->spr.invDet = 1.0 / (cub->ray.planeX * cub->ray.dirY - cub->ray.dirX * cub->ray.planeY);

		cub->spr.transformX = cub->spr.invDet * (cub->ray.dirY * cub->spr.spriteX - cub->ray.dirX * cub->spr.spriteY);
		cub->spr.transformY = cub->spr.invDet * (-cub->ray.planeY * cub->spr.spriteX + cub->ray.planeX * cub->spr.spriteY);

		vMoveScreen = (int)(vMove / cub->spr.transformY);

		cub->spr.spriteScreenX = (int)((cub->resX / 2) * (1 + cub->spr.transformX / cub->spr.transformY));

		cub->spr.spriteHeight = abs((int)(cub->resY / (cub->spr.transformY))) / vDiv;

		cub->spr.drawStartY = -cub->spr.spriteHeight / 2 + cub->resY / 2 + vMoveScreen;
		if (cub->spr.drawStartY < 0)
			cub->spr.drawStartY = 0;
		cub->spr.drawEndY = cub->spr.spriteHeight / 2 + cub->resY / 2 + vMoveScreen;
		if (cub->spr.drawEndY >= cub->resY)
			cub->spr.drawEndY = cub->resY - 1;

		cub->spr.spriteWidth = abs((int) (cub->resY / (cub->spr.transformY))) / uDiv;
		cub->spr.drawStartX = -cub->spr.spriteWidth / 2 + cub->spr.spriteScreenX;
		if (cub->spr.drawStartX < 0)
			cub->spr.drawStartX = 0;
		cub->spr.drawEndX = cub->spr.spriteWidth / 2 + cub->spr.spriteScreenX;
		if (cub->spr.drawEndX >= cub->resX)
			cub->spr.drawEndX = cub->resX - 1;
		stripe = cub->spr.drawStartX;

		while (stripe < cub->spr.drawEndX)
		{
			//printf("stripe: %d -- Valor: %f\n", stripe, cub->spr->ZBuffer[stripe]);
			// cub->ptx.texX = (int)(256 * (stripe - (-cub->spr->spriteWidth / 2 + cub->spr->spriteScreenX)) * cub->stx->width / cub->spr->spriteWidth) / 256;
			// if (cub->spr->transformY > 0 && stripe > 0 && stripe < cub->resX && cub->spr->transformY < cub->spr->ZBuffer[stripe])
			cub->ptx.texX = (int)(256 * (stripe - (-cub->spr.spriteWidth / 2 + cub->spr.spriteScreenX)) * cub->stx->width / cub->spr.spriteWidth) / 256;
			if (cub->spr.transformY > 0 && stripe > 0 && stripe < cub->resX && cub->spr.transformY < cub->resX)
			{
				y = cub->spr.drawStartY;
				while (y < cub->spr.drawEndY)
				{
					d = (y - vMoveScreen) * 256 - cub->resY * 128 + cub->spr.spriteHeight * 128;
					cub->ptx.texY = ((d * cub->stx->height) / cub->spr.spriteHeight) / 256;
					color = my_get_color_pixel(cub, cub->ptx.texX, cub->ptx.texY);
					if((color & 0x00FFFFFF) != 0)
						my_mlx_pixel_put(cub, stripe, y, color);
					y++;
				}
			}
			stripe++;
		}
		cnt++;
	}
}
