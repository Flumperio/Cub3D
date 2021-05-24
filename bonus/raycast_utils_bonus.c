/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:24:01 by juasanto          #+#    #+#             */
/*   Updated: 2021/04/30 08:12:45 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	to_rgb(int r, int g, int b)
{
	return ((b * 1) + (g * 256) + (r * 256 * 256));
}

void	my_mlx_pixel_put(t_cube *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->mlx.addr + (y * cub->mlx.line_length
			+ x * (cub->mlx.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	my_get_color_pixel(t_cube *cub, int x, int y)
{
	char	*dst;

	dst = cub->stx[cub->ptx.texNum].addr + (y * cub->stx[cub->ptx.texNum].ll
			+ x * (cub->stx[cub->ptx.texNum].bpp / 8));
	return (*(unsigned int *)dst);
}

void	stg_tex(t_cube *cub)
{
	int	cnt;

	cnt = 0;
	while (cnt <= 6)
	{
		cub->stx[cnt].img = mlx_xpm_file_to_image(cub->mlx.mlx,
				cub->tex[cnt].path, &cub->stx[cnt].width,
				&cub->stx[cnt].height);
		cub->stx[cnt].addr = mlx_get_data_addr(cub->stx[cnt].img,
				&cub->stx[cnt].bpp, &cub->stx[cnt].ll, &cub->stx[cnt].e);
		cnt++;
	}
}

	/*
	** N, S, E, W
	*/
void	set_color_wall(t_cube *cub)
{
	if (cub->ray.side == 0 && cub->ray.rayDirX > 0)
		cub->ray.wall_color = to_rgb(153, 0, 0);
	if (cub->ray.side == 0 && cub->ray.rayDirX <= 0)
		cub->ray.wall_color = to_rgb(0, 153, 0);
	if (cub->ray.side == 1 && cub->ray.rayDirY > 0)
		cub->ray.wall_color = to_rgb(0, 0, 153);
	if (cub->ray.side == 1 && cub->ray.rayDirY <= 0)
		cub->ray.wall_color = to_rgb(153, 153, 153);
}
