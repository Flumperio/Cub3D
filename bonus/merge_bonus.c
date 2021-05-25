/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:17:56 by juasanto          #+#    #+#             */
/*   Updated: 2021/05/25 11:27:18 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d_bonus.h"

void	sprites_sort(t_cube *cub, int l, int r)
{
	int	m;

	if (l < r)
	{
		m = l + (r - l) / 2;
		sprites_sort(cub, l, m);
		sprites_sort(cub, m + 1, r);
		merge(cub, l, m, r);
	}
}

void	merge_copy(t_cube *cub, int l, int m)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cub->mrg.n1)
		cub->spr_l[i] = cub->osp[l + i];
	j = -1;
	while (++j < cub->mrg.n2)
		cub->spr_d[j] = cub->osp[m + 1 + j];
}

void	merge_swap(t_cube *cub, int i, int j, int k)
{
	while (i < cub->mrg.n1)
	{
		cub->osp[k] = cub->spr_l[i];
		i++;
		k++;
	}
	while (j < cub->mrg.n2)
	{
		cub->osp[k] = cub->spr_d[j];
		j++;
		k++;
	}
}

void	merge(t_cube *cub, int l, int m, int r)
{
	int	i;
	int	j;
	int	k;

	cub->mrg.n1 = m - l + 1;
	cub->mrg.n2 = r - m;
	merge_copy (cub, l, m);
	i = 0;
	j = 0;
	k = l;
	while (i < cub->mrg.n1 && j < cub->mrg.n2)
	{
		if (cub->spr_l[i].spriteDistance >= cub->spr_d[j].spriteDistance)
		{
			cub->osp[k] = cub->spr_l[i];
			i++;
		}
		else
		{
			cub->osp[k] = cub->spr_d[j];
			j++;
		}
		k++;
	}
	merge_swap (cub, i, j, k);
}
