/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:39:36 by juasanto          #+#    #+#             */
/*   Updated: 2021/04/28 15:41:19 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	move_fw(t_cube *cub)
{
	if (cub->wrk_map[(int)(cub->pyr.posX + cub->ray.dirX * cub->ray.moveSpeed)][(int)cub->pyr.posY] == 48)
		cub->pyr.posX += cub->ray.dirX * cub->ray.moveSpeed;
	if(cub->wrk_map[(int)cub->pyr.posX][(int)(cub->pyr.posY + cub->ray.dirY * cub->ray.moveSpeed)] == 48)
		cub->pyr.posY += cub->ray.dirY * cub->ray.moveSpeed;
}
void	move_bw(t_cube *cub)
{
	if (cub->wrk_map[(int)(cub->pyr.posX - cub->ray.dirX * cub->ray.moveSpeed)][(int)cub->pyr.posY] == 48)
		cub->pyr.posX -= cub->ray.dirX * cub->ray.moveSpeed;
	if(cub->wrk_map[(int)cub->pyr.posX][(int)(cub->pyr.posY - cub->ray.dirY * cub->ray.moveSpeed)] == 48)
		cub->pyr.posY -= cub->ray.dirY * cub->ray.moveSpeed;
}
void	move_sl(t_cube *cub)
{
	if (cub->wrk_map[(int)(cub->pyr.posX - cub->ray.dirY * cub->ray.moveSpeed)][(int)cub->pyr.posY] == 48)
		cub->pyr.posX -= cub->ray.dirY * cub->ray.moveSpeed;
	if (cub->wrk_map[(int)cub->pyr.posX][(int)(cub->pyr.posY + cub->ray.dirX * cub->ray.moveSpeed)] == 48)
		cub->pyr.posY += cub->ray.dirX * cub->ray.moveSpeed;
}
void	move_sr(t_cube *cub)
{
	if (cub->wrk_map[(int)(cub->pyr.posX + cub->ray.dirY * cub->ray.moveSpeed)][(int)cub->pyr.posY] == 48)
		cub->pyr.posX += cub->ray.dirY * cub->ray.moveSpeed;
	if (cub->wrk_map[(int)cub->pyr.posX][(int)(cub->pyr.posY - cub->ray.dirX * cub->ray.moveSpeed)] == 48)
		cub->pyr.posY -= cub->ray.dirX * cub->ray.moveSpeed;
}
