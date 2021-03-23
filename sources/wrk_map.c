/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrk_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:07:10 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/23 13:27:25 by jcsantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	tmp_map(t_cube *s_c3d, t_map *st_map)
{
	int	cnt_x;
	int	cnt_y;
	int	cnt_2;
	int	tmp;

	cnt_x = 0;
	cnt_y = 0;
	cnt_2 = 0;
	tmp = 0;
	while (s_c3d->wrk_map[tmp])
	{
		printf("map_line: %s\n", s_c3d->wrk_map[tmp]);
		tmp++;
	}
	tmp = 0;
	while (s_c3d->tmp_map[tmp])
	{
		printf ("\e[31mtmp_line: %s\n", s_c3d->tmp_map[tmp]);
		tmp++;
	}
	//st_map = ft_calloc(st_map->num_2 + 1, sizeof(st_map));
			//printf("tmp_map: %s\n", s_c3d->tmp_map[cnt_x]);
	while (s_c3d->tmp_map[cnt_x] != 0)
	{
		printf("tmp_map: %s\n", s_c3d->tmp_map[cnt_x]);
		while (s_c3d->tmp_map[cnt_x][cnt_y] != 0)
		{
			if (ft_strchr("NSWE", s_c3d->tmp_map[cnt_x][cnt_y]))
			{
				s_c3d->pl_view = s_c3d->tmp_map[cnt_x][cnt_y];
				s_c3d->pl_posx = cnt_x;
				s_c3d->pl_posy = cnt_y;
			}
			if (s_c3d->tmp_map[cnt_x][cnt_y] == '2')
			{
				st_map[cnt_2].x_pos = cnt_x;
				st_map[cnt_2].y_pos = cnt_y;
				cnt_2++;
			}
			cnt_y++;
		}
		cnt_y = 0;
		cnt_x++;
	}
	//free(st_map);
}

void	cnvrt_map(t_cube *s_c3d, t_map *st_map)
{
	int		cnt;

	cnt = 0;
	while (s_c3d->line[cnt] != '\0')
	{
		if (ft_isblank(s_c3d->line[cnt]))
			s_c3d->line[cnt] = '0';
		if (s_c3d->line[cnt] == '2')
			st_map->num_2++;
		if (ft_strchr("NSWE", s_c3d->line[cnt]))
			st_map->temp++;
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

void	strg_map(t_cube *s_c3d, t_map *st_map)
{
	int		fd1;

	fd1 = 0;
	s_c3d->strg_map = 1;
	s_c3d->wrk_map = ft_calloc(s_c3d->map_lines + 1, sizeof(char **));
	s_c3d->tmp_map = ft_calloc(s_c3d->map_lines + 1, sizeof(char **));
	fd1 = open(s_c3d->f_name, O_RDONLY);
	while (get_next_line(fd1, &s_c3d->line) == 1)
	{
		chk_parms(s_c3d, st_map);
		ft_free(s_c3d->line);
	}
	chk_parms(s_c3d, st_map);
	ft_free(s_c3d->line);
	if (st_map->temp != 1)
		ft_msgerror("No valid map.", 7);
}
