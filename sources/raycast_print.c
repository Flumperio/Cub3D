/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:27:03 by juasanto          #+#    #+#             */
/*   Updated: 2021/05/25 10:31:43 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	paint_floor(t_cube *cub, int x, int y)
{
	cub->ptx.texNum = 5;
	set_fc_id (cub);
	cub->ptx.distWall = cub->ray.perpWallDist;
	cub->ptx.distPlayer = 0.0;
	return (print_fc(cub, x, y, cub->resY));
}

int	paint_ceiling(t_cube *cub, int x, int y)
{
	cub->ptx.texNum = 6;
	set_fc_id (cub);
	cub->ptx.distWall = -cub->ray.perpWallDist;
	cub->ptx.distPlayer = 0.0;
	return (print_fc(cub, x, y, cub->ray.drawStart));
}

void	print_raydir_x_y(t_cube *cub, int x)
{
	int		y;

	y = 0;
	cub->ZBuffer[x] = cub->ray.perpWallDist;
	text_calc(cub);
	while (y < cub->resY)
	{
		if (y < cub->ray.drawStart)
			my_mlx_pixel_put(cub, x, y, 0x079099);
		else if (y > cub->ray.drawStart && y < cub->ray.drawEnd)
			y = paint_wall(cub, x, y);
		else if (y > cub->ray.drawEnd)
			my_mlx_pixel_put(cub, x, y, 0x445555);
		y++;
	}
}
