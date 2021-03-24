/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrk_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:07:10 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/24 12:09:21 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	tmp_map(t_cube *s_c3d, struct s_map *st_map)
{
	int	cnt_x;
	int	cnt_y;
	int	cnt_2;

	cnt_x = 0;
	cnt_y = 0;
	cnt_2 = 0;
	while (s_c3d->tmp_map[cnt_x] != 0)
	{
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
