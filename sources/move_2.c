/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:47:23 by juasanto          #+#    #+#             */
/*   Updated: 2021/04/30 08:06:41 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	move_rl(t_cube *cub)
{
	cub->ray.oldDirX = cub->ray.dirX;
	cub->ray.dirX = cub->ray.dirX * cos(cub->ray.rotSpeed)
		- cub->ray.dirY * sin(cub->ray.rotSpeed);
	cub->ray.dirY = cub->ray.oldDirX * sin(cub->ray.rotSpeed)
		+ cub->ray.dirY * cos(cub->ray.rotSpeed);
	cub->ray.oldPlaneX = cub->ray.planeX;
	cub->ray.planeX = cub->ray.planeX * cos(cub->ray.rotSpeed)
		- cub->ray.planeY * sin(cub->ray.rotSpeed);
	cub->ray.planeY = cub->ray.oldPlaneX * sin(cub->ray.rotSpeed)
		+ cub->ray.planeY * cos(cub->ray.rotSpeed);
}

void	move_rr(t_cube *cub)
{
	cub->ray.oldDirX = cub->ray.dirX;
	cub->ray.dirX = cub->ray.dirX * cos(-cub->ray.rotSpeed)
		- cub->ray.dirY * sin(-cub->ray.rotSpeed);
	cub->ray.dirY = cub->ray.oldDirX * sin(-cub->ray.rotSpeed)
		+ cub->ray.dirY * cos(-cub->ray.rotSpeed);
	cub->ray.oldPlaneX = cub->ray.planeX;
	cub->ray.planeX = cub->ray.planeX * cos(-cub->ray.rotSpeed)
		- cub->ray.planeY * sin(-cub->ray.rotSpeed);
	cub->ray.planeY = cub->ray.oldPlaneX * sin(-cub->ray.rotSpeed)
		+ cub->ray.planeY * cos(-cub->ray.rotSpeed);
}
