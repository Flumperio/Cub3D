/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrk_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:07:10 by juasanto          #+#    #+#             */
/*   Updated: 2021/04/15 13:48:10 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	strg_pl_pos(t_cube *cub, int x, int y)
{
	cub->pyr.view = cub->tmp_map[x][y];
	cub->pyr.posX = x;
	cub->pyr.posY = y;
	cub->tmp_map[x][y] = '3';
	cub->wrk_map[x][y] = '0';
}

void	strg_sp_pos(t_cube *cub, int x, int y)
{
	cub->sprites[cub->sprites->sp_num].x_pos = x;
	cub->sprites[cub->sprites->sp_num].y_pos = y;
	cub->sprites->sp_num++;
	// map[map->sp_num].x_pos = x;
	// map[map->sp_num].y_pos = y;
	// map->sp_num++;
	cub->tmp_map[x][y] = '0';
}

void	tmp_map(t_cube *cub)
{
	int	cnt_x;
	int	cnt_y;

	cnt_x = 0;
	cnt_y = 0;
	cub->sprites->sp_num = 0;
	//map->sp_num = 0;
	while (cub->tmp_map[cnt_x] != 0)
	{
		while (cub->tmp_map[cnt_x][cnt_y] != 0)
		{
			if (ft_strchr("NSWE", cub->tmp_map[cnt_x][cnt_y]))
				strg_pl_pos(cub, cnt_x, cnt_y);
			if (cub->tmp_map[cnt_x][cnt_y] == '2')
				strg_sp_pos(cub, cnt_x, cnt_y);
			cnt_y++;
		}
		cnt_y = 0;
		cnt_x++;
	}
}

void	cnvrt_map(t_cube *cub)
{
	int		cnt;
	cnt = 0;
	while (cub->line[cnt] != '\0')
	{
		if (ft_isblank(cub->line[cnt]))
			cub->line[cnt] = '0';
		if (cub->line[cnt] == '2')
			cub->cnt_2++;
		if (ft_strchr("NSWE", cub->line[cnt]))
			cub->pyr.num++;
		if (!ft_strchr(cub->map_value, cub->line[cnt]))
			ft_msgerror ("No valid map.", 7);
		cnt++;
	}
	cub->wrk_map[cub->cnt_map] = ft_strdup(cub->line);
	cub->wrk_map[cub->cnt_map + 1] = NULL;
	cub->tmp_map[cub->cnt_map] = ft_strdup(cub->line);
	cub->tmp_map[cub->cnt_map + 1] = NULL;
	cub->cnt_map++;
}

void	strg_map(t_cube *cub)
{
	int		fd1;

	fd1 = 0;
	cub->strg_map = 1;
	cub->wrk_map = ft_calloc(cub->map_lines + 1, sizeof(char **));
	cub->tmp_map = ft_calloc(cub->map_lines + 1, sizeof(char **));
	fd1 = open(cub->f_name, O_RDONLY);
	while (get_next_line(fd1, &cub->line) == 1)
	{
		chk_parms(cub);
		ft_free(cub->line);
	}
	chk_parms(cub);
	ft_free(cub->line);
	if (cub->pyr.num != 1)
		ft_msgerror("No valid map.", 7);
}
