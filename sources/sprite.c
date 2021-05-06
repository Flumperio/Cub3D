/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 10:19:53 by juasanto          #+#    #+#             */
/*   Updated: 2021/05/06 14:02:55 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	order_sprites (t_cube *cub);
void	mergeSort(t_cube *cub, int l, int r);

void	sprites(t_cube *cub)
{
	int	cnt;
	int	max;

	cnt = 0;
	max = cub->spr[0].sp_num;
	while(cnt < max)
	{
		//cub->spr[cnt].spriteOrder = cnt;
		cub->spr[cnt].spriteDistance = ((cub->pyr.posX - cub->spr[cnt].x_pos) * (cub->pyr.posX - cub->spr[cnt].x_pos) + (cub->pyr.posY - cub->spr[cnt].y_pos) * (cub->pyr.posY - cub->spr[cnt].y_pos));
		printf("SP_Dis: %f -- X: %f -- Y: %f\n", cub->spr[cnt].spriteDistance, cub->spr[cnt].x_pos, cub->spr[cnt].y_pos);
		cnt++;
	}
	mergeSort (cub, 0, max - 1);

	cnt = 0;
	while(cnt < max)
	{
		//cub->spr[cnt].spriteOrder = cnt;
		//cub->spr[cnt].spriteDistance = ((cub->pyr.posX - cub->spr[cnt].x_pos) * (cub->pyr.posX - cub->spr[cnt].x_pos) + (cub->pyr.posY - cub->spr[cnt].y_pos) * (cub->pyr.posY - cub->spr[cnt].y_pos));
		printf("SP_Dis: %f -- X: %f -- Y: %f\n", cub->spr[cnt].spriteDistance, cub->spr[cnt].x_pos, cub->spr[cnt].y_pos);
		cnt++;
	}
	//order_sprites(cub);
}

void	order_sprites (t_cube *cub)
{
	int		cnt;
	int		max;
	t_spr	temp;

	cnt = 0;
	max = cub->spr[0].sp_num;
	temp = cub->spr[0];
		printf("\nHOLE: %i -- %g -- %f -- %f\n", temp.spriteOrder, temp.spriteDistance, temp.x_pos, temp.y_pos);

	while (cnt < max )
	{
		if(cub->spr[cnt].spriteDistance > temp.spriteDistance)
			temp = cub->spr[cnt];
		cnt++;
	}

	printf("HOLE: %i -- %g -- %f -- %f\n", temp.spriteOrder, temp.spriteDistance, temp.x_pos, temp.y_pos);
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
    while (i < n1 && j < n2) {
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
    while (j < n2) {
        cub->spr[k] = SPR_D[j];
        j++;
        k++;
    }
}

void mergeSort(t_cube *cub, int l, int r)
{
    if (l < r)
	{
        int m = l + (r - l) / 2;
        mergeSort(cub, l, m);
        mergeSort(cub, m + 1, r);
        merge(cub, l, m, r);
    }
}
