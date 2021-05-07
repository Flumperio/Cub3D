/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 10:19:53 by juasanto          #+#    #+#             */
/*   Updated: 2021/05/07 13:59:46 by juasanto         ###   ########.fr       */
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

	t_spr SPR_L[n1];
	t_spr SPR_D[n2];
	for (i = 0; i < n1; i++)
		SPR_L[i] = cub->spr[l + i];
	for (j = 0; j < n2; j++)
		SPR_D[j] = cub->spr[m + 1 + j];
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (SPR_L[i].spriteDistance <= SPR_D[j].spriteDistance) {
			cub->spr[k] = SPR_L[i];
			i++;
		}
		else {
			cub->spr[k] = SPR_D[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		cub->spr[k] = SPR_L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		cub->spr[k] = SPR_D[j];
		j++;
		k++;
	}
}

void	sprites(t_cube *cub)
{
	int	cnt;
	int	max;

	cnt = 0;
	max = cub->spr[0].sp_num;
	while(cnt < max)
	{
		cub->spr[cnt].spriteDistance = ((cub->pyr.posX - cub->spr[cnt].x_pos) * (cub->pyr.posX - cub->spr[cnt].x_pos) + (cub->pyr.posY - cub->spr[cnt].y_pos) * (cub->pyr.posY - cub->spr[cnt].y_pos));
			/**
	 	* bufferZ añadido para los sprites
	 	**/
		cub->spr[cnt].ZBuffer = cub->ray.perpWallDist;
		printf("SP_Dis: %f -- X: %f -- Y: %f\n", cub->spr[cnt].spriteDistance, cub->spr[cnt].x_pos, cub->spr[cnt].y_pos);
		cnt++;
	}
	sprites_sort (cub, 0, max - 1);
	cnt = 0;
	while(cnt < max)
	{
		printf("SP_Dis: %f -- X: %f -- Y: %f\n", cub->spr[cnt].spriteDistance, cub->spr[cnt].x_pos, cub->spr[cnt].y_pos);
		cnt++;
	}
}

void	sprites_print (t_cube *cub)
{
	int	cnt;
	int	stripe;
	int	y;
	int	d;

	cnt = 0;
	while(cnt < cub->cnt_2)
	{
		cub->spr->spriteX = cub->spr[cnt].x_pos - cub->pyr.posX;
		cub->spr->spriteY = cub->spr[cnt].y_pos - cub->pyr.posY;

		cub->spr->invDet = 1.0 / (cub->ray.planeX * cub->ray.dirY - cub->ray.dirX * cub->ray.planeY);

		cub->spr->transformX = cub->spr->invDet * (cub->ray.dirY * cub->spr->spriteX - cub->ray.dirX * cub->spr->spriteY);
		cub->spr->transformY = cub->spr->invDet * (-cub->ray.planeY * cub->spr->spriteX + cub->ray.planeX * cub->spr->spriteY);

		cub->spr->spriteScreenX = (int)((cub->resX / 2) * (1 + cub->spr->transformX / cub->spr->transformY));

		cub->spr->spriteHeight = abs((int)(cub->resY / (cub->spr->transformY)));

		cub->spr->drawStartY = -cub->spr->spriteHeight / 2 + cub->resY / 2;
		if (cub->spr->drawStartY < 0)
			cub->spr->drawStartY = 0;
		cub->spr->drawEndY = cub->spr->spriteHeight / 2 + cub->resY / 2;
		if (cub->spr->drawEndY >= cub->resY)
			cub->spr->drawEndY = cub->resY - 1;

		cub->spr->spriteWidth = abs((int) (cub->resY / (cub->spr->transformY)));
		cub->spr->drawStartX = -cub->spr->spriteWidth / 2 + cub->spr->spriteScreenX;
		if (cub->spr->drawStartX < 0)
			cub->spr->drawStartX = 0;
		cub->spr->drawEndX = cub->spr->spriteWidth / 2 + cub->spr->spriteScreenX;
		if (cub->spr->drawEndX >= cub->resX)
			cub->spr->drawEndX = cub->resX - 1;
		stripe = cub->spr->drawStartX;
		while (stripe < cub->spr->drawEndX)
		{
			cub->ptx.texX = (int)(256 * (stripe - (-cub->spr->spriteWidth / 2 + cub->spr->spriteScreenX)) * cub->stx->width / cub->spr->spriteWidth) / 256;
			if (cub->spr->transformY > 0 && stripe > 0 && stripe < cub->resX && cub->spr->transformY < cub->spr[stripe].ZBuffer)
			{
				y = cub->spr->drawStartY;
				while (y < cub->spr->drawEndY)
				{
					d = (y) * 256 - cub->resY * 128 + cub->spr->spriteHeight * 128;
					cub->ptx.texY = ((d * cub->stx->height) / cub->spr->spriteHeight) / 256;
					my_mlx_pixel_put(cub, x, y, 0xFFFFFF);
					y++;
				}

			}
			stripe++;
		}
		cnt++;
	}
}
