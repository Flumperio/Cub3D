/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrk_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:07:10 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/19 13:56:22 by jcsantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	tmp_map(t_cube *s_c3d, t_map *st_map)
{
	int	cnt;

	cnt = 0;
	st_map = ft_calloc(st_map->num_2 + 2, sizeof(st_map));
	while (s_c3d->tmp_map[cnt] != 0)
	{

	}
}

void	cnvrt_map(t_cube *s_c3d, t_map *st_map)
{
	int		cnt;

	cnt = 0;
	st_map->temp = 0;
	while (s_c3d->line[cnt] != '\0')
	{
		if (ft_isblank(s_c3d->line[cnt]))
			s_c3d->line[cnt] = '0';
		if (s_c3d->line[cnt] == '2')
			st_map->num_2++;
		if (!ft_strchr(st_map->map_value, s_c3d->line[cnt]))
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
}
