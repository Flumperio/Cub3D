/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrk_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:07:10 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/25 11:35:38 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	strg_pl_pos(t_cube *s_c3d, int x, int y)
{
	s_c3d->pl_view = s_c3d->tmp_map[x][y];
	s_c3d->pl_posx = x;
	s_c3d->pl_posy = y;
}

void	strg_sp_pos(t_map *st_map, int x, int y)
{
	st_map[st_map->sp_num].x_pos = x;
	st_map[st_map->sp_num].y_pos = y;
	st_map->sp_num++;
}

void	tmp_map(t_cube *s_c3d, t_map *st_map)
{
	int	cnt_x;
	int	cnt_y;

	cnt_x = 0;
	cnt_y = 0;
	st_map->sp_num = 0;
	while (s_c3d->tmp_map[++cnt_x] != 0)
	{
		while (s_c3d->tmp_map[cnt_x][++cnt_y] != 0)
		{
			if (ft_strchr("NSWE", s_c3d->tmp_map[cnt_x][cnt_y]))
				strg_pl_pos(s_c3d, cnt_x, cnt_y);
			if (s_c3d->tmp_map[cnt_x][cnt_y] == '2')
				strg_sp_pos(st_map, cnt_x, cnt_y);
		}
		cnt_y = 0;
	}
}

void	cnvrt_map(t_cube *s_c3d)
{
	int		cnt;

	cnt = 0;
	while (s_c3d->line[cnt] != '\0')
	{
		if (ft_isblank(s_c3d->line[cnt]))
			s_c3d->line[cnt] = '0';
		if (s_c3d->line[cnt] == '2')
			s_c3d->cnt_2++;
		if (ft_strchr("NSWE", s_c3d->line[cnt]))
			s_c3d->pl_num++;
		if (!ft_strchr(s_c3d->map_value, s_c3d->line[cnt]))
			ft_msgerror ("No valid map.", 7);
		cnt++;
	}
	s_c3d->wrk_map[s_c3d->cnt_map] = ft_strdup(s_c3d->line);
	s_c3d->wrk_map[s_c3d->cnt_map + 1] = NULL;
	s_c3d->tmp_map[s_c3d->cnt_map] = ft_strdup(s_c3d->line);
	s_c3d->tmp_map[s_c3d->cnt_map + 1] = NULL;
	s_c3d->cnt_map++;
}

void	strg_map(t_cube *s_c3d)
{
	int		fd1;

	fd1 = 0;
	s_c3d->strg_map = 1;
	s_c3d->wrk_map = ft_calloc(s_c3d->map_lines + 1, sizeof(char **));
	s_c3d->tmp_map = ft_calloc(s_c3d->map_lines + 1, sizeof(char **));
	fd1 = open(s_c3d->f_name, O_RDONLY);
	while (get_next_line(fd1, &s_c3d->line) == 1)
	{
		chk_parms(s_c3d);
		ft_free(s_c3d->line);
	}
	chk_parms(s_c3d);
	ft_free(s_c3d->line);
	if (s_c3d->pl_num != 1)
		ft_msgerror("No valid map.", 7);
}
