/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cls_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:10:40 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/29 14:11:02 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	cls_map(t_cube *cub, t_map *map, int x, int y)
{
	// int	c_x;
	// int	c_y;
	// int	c_l;
	// //int c_x1, c_y1;
	// //int	l_len;

	// c_x = x;
	// c_y = y;
	// c_l = cub->map_lines;
	//cub->tmp = 1;
	//map->temp = 0;
	printf("PL: %c, x: %i - y: %i\n", cub->pl_view, x, y);
	if (x == 0 || y == 0 || y == ft_strlen(cub->tmp_map[x]) - 1 || cub->tmp_map[x + 1][y] == '\0'||
		y > ft_strlen(cub->tmp_map[x - 1]) || y > ft_strlen(cub->tmp_map[x + 1]))
		ft_msgerror("ABIERTO", 6);
	cub->tmp_map[x][y] = '3';
	if (cub->tmp_map[x - 1][y] == '0')
	{
		cls_map(cub, map, x - 1, y);
	}
	if (cub->tmp_map[x][y + 1] == '0')
	{
		cls_map(cub, map, x, y + 1);
	}
	if (cub->tmp_map[x + 1][y] == '0')
	{
		cls_map(cub, map, x + 1, y);
	}
	if (cub->tmp_map[x][y - 1] == '0')
	{
		cls_map(cub, map, x, y - 1);
	}

	// if (cub->tmp_map[x][y + 1] == '0')
	// {
	// 	cub->tmp_map[x][y + 1] = '3';
	// 	y++;
	// 	cls_map(cub, map);
	// }
	// if (cub->tmp_map[x + 1][y] == '0')
	// {
	// 	cub->tmp_map[x + 1][y] = '3';
	// 	x++;
	// 	cls_map(cub, map);
	// }
	// if (cub->tmp_map[x][y - 1] == '0')
	// {
	// 	cub->tmp_map[x][y - 1] = '3';
	// 	y--;
	// 	cls_map(cub, map);
	// }
	// if (cub->tmp_map[x][y + 1] == '0')
	// {
	// 	cub->tmp_map[x][y + 1] = '3';
	// 	y++;
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
