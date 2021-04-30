/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 10:19:53 by juasanto          #+#    #+#             */
/*   Updated: 2021/04/30 12:24:12 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	sprites(t_cube *cub)
{
	int	cnt;

	cnt = 0;
	while(cnt < cub->spr[0].sp_num)
	{
		//cub->spr[cnt].spriteOrder = cnt;
		cub->spr[cnt].spriteDistance = ((cub->pyr.posX - cub->spr[cnt].x_pos) * (cub->pyr.posX - cub->spr[cnt].x_pos) + (cub->pyr.posY - cub->spr[cnt].y_pos) * (cub->pyr.posY - cub->spr[cnt].y_pos));
		printf("SP_num: %i -- SP_Order: %i -- SP_Dis: %f\n", cub->spr[cnt].sp_num, cub->spr[cnt].spriteOrder, cub->spr[cnt].spriteDistance);
		cnt++;
	}
}
