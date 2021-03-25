/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cls_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:10:40 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/25 18:29:25 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	cls_map(t_cube *cub, t_map *map)
{
	int	c_x;
	int	c_y;
	int	c_l;
	//int c_x1, c_y1;
	//int	l_len;

	c_x = cub->pl_posx;
	c_y = cub->pl_posy;
	c_l = cub->map_lines;
	cub->tmp = 1;
	//map->temp = 0;
	printf("PL: %c, x: %i - y: %i\n", cub->pl_view, cub->pl_posx, cub->pl_posy);
	if (cub->tmp_map[cub->pl_posx - 1][cub->pl_posy] != '1' && \
		map->temp == 0)
	{
		cub->tmp_map[cub->pl_posx - 1][cub->pl_posy] = '3';
		cub->pl_posx--;
		cls_map(cub, map);
		map->temp = 1;
	}
	if (cub->tmp_map[cub->pl_posx][cub->pl_posy + 1] != '1' && \
		map->temp == 1)
	{
		cub->tmp_map[cub->pl_posx][cub->pl_posy + 1] = '3';
		cub->pl_posy++;
		cls_map(cub, map);
		map->temp = 2;
	}
	if (cub->tmp_map[cub->pl_posx + 1][cub->pl_posy] != '1' && \
		map->temp == 2)
	{
		cub->tmp_map[cub->pl_posx + 1][cub->pl_posy] = '3';
		cub->pl_posx++;
		cls_map(cub, map);
		map->temp = 3;
	}
	if (cub->tmp_map[cub->pl_posx][cub->pl_posy - 1] != '1' && \
		map->temp == 3)
	{
		cub->tmp_map[cub->pl_posx][cub->pl_posy - 1] = '3';
		cub->pl_posy--;
		cls_map(cub, map);
		map->temp = 0;

	}
	// if (cub->tmp_map[cub->pl_posx][cub->pl_posy + 1] == '0')
	// {
	// 	cub->tmp_map[cub->pl_posx][cub->pl_posy + 1] = '3';
	// 	cub->pl_posy++;
	// 	cls_map(cub, map);
	// }
	// if (cub->tmp_map[cub->pl_posx + 1][cub->pl_posy] == '0')
	// {
	// 	cub->tmp_map[cub->pl_posx + 1][cub->pl_posy] = '3';
	// 	cub->pl_posx++;
	// 	cls_map(cub, map);
	// }
	// if (cub->tmp_map[cub->pl_posx][cub->pl_posy - 1] == '0')
	// {
	// 	cub->tmp_map[cub->pl_posx][cub->pl_posy - 1] = '3';
	// 	cub->pl_posy--;
	// 	cls_map(cub, map);
	// }

	// c_x1 = 0;
	// c_y1 = 0;
	// while (cub->tmp_map[c_x1] != 0)
	// {
	// 	while (cub->tmp_map[c_x1][c_y1] != 0)
	// 	{
	// 		printf("%c", cub->tmp_map[c_x1][c_y1]);
	// 		c_y1++;
	// 	}
	// 	printf("\n");
	// 	c_y1 = 0;
	// 	c_x1++;
	// }
	return (0);
}

	// while (cnt_x < cub->cnt_map)
	// {
	// 	l_len = ft_strlen(cub->tmp_map[cnt_x]);
	// 	while (cnt_y < l_len)
	// 	{
	// 		printf("%c", cub->tmp_map[cnt_x][cnt_y]);
	// 		cnt_y++;
	// 	}
	// 	printf("\n");
	// 	cnt_y = 0;
	// 	cnt_x++;
	// }
