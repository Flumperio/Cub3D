/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cls_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:10:40 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/25 13:42:43 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	cls_map(t_cube *cub, t_map *map)
{
	int	cnt_x;
	int	cnt_y;
	int	l_len;

	cnt_x = 0;
	cnt_y = 0;
	map->temp = 0;
	printf("map_lines: %i\n", cub->cnt_map);
	while (cnt_x < cub->cnt_map)
	{
		l_len = ft_strlen(cub->tmp_map[cnt_x]);
		while (cnt_y < l_len)
		{
			printf("%c", cub->tmp_map[cnt_x][cnt_y]);
			cnt_y++;
		}
		printf("\n");
		cnt_y = 0;
		cnt_x++;
	}
	return (0);
}
