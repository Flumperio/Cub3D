/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cls_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:10:40 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/30 13:03:22 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	cls_map(t_cube *cub, t_map *map, int x, int y)
{
	if (x == 0 || y == 0 || y == ft_strlen(cub->tmp_map[x]) - 1 || x == cub->cnt_map - 1 || \
		y > ft_strlen(cub->tmp_map[x + 1]))
		ft_msgerror("Open Map", 6);
	cub->tmp_map[x][y] = '3';
	if (cub->tmp_map[x - 1][y] == '0')
		cls_map(cub, map, x - 1, y);
	if (cub->tmp_map[x][y + 1] == '0')
		cls_map(cub, map, x, y + 1);
	if (cub->tmp_map[x + 1][y] == '0')
		cls_map(cub, map, x + 1, y);
	if (cub->tmp_map[x][y - 1] == '0')
		cls_map(cub, map, x, y - 1);
	return (0);
}
