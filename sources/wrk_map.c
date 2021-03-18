/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrk_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:07:10 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/18 14:17:51 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

// void	dup_map(t_cube *s_c3d)
// {
// 	int	cnt;

// 	cnt = 0;
// 	while (s_c3d->line[cnt] != '\0')
// 	{
// 		if (ft_isblank(s_c3d->line[cnt]))
// 			s_c3d->line[cnt] = '0';
// 		if (s_c3d->line[cnt] == '2')
// 			s_c3d->line[cnt] = '0';
// 		if (s_c3d->line[cnt] == 'N')
// 		{
// 			s_c3d->line[cnt] = '0';

// 		}
// 		cnt++;
// 	}
// 	s_c3d->wrk_map[s_c3d->cnt_map++] = ft_strdup(s_c3d->line);
// 	s_c3d->wrk_map[s_c3d->cnt_map] = NULL;
// 	return ;

// }
// int		chk_val_map(t_cube *s_c3d, t_map *st_map)
// {
// 	int	cnt;
// 	int	cnt1;

// 	cnt = 0;
// 	cnt1 = 7;
// 	while (s_c3d->line[cnt] != '\0')
// 	{
// 		while (cnt1 > 0)
// 			if (s_c3d->line[cnt] == st_map->map_value[cnt1])
// 				cnt1++;
// 			else
// 				ft_msgerror ("No valid map.", 7);
// 	}
// }

void	cnvrt_map(t_cube *s_c3d, t_map *st_map)
{
	int		cnt;

	cnt = 0;
	while (s_c3d->line[cnt] != '\0')
	{
		if (ft_isblank(s_c3d->line[cnt]))
			s_c3d->line[cnt] = '0';
		if (!ft_strchr(st_map->map_value, s_c3d->line[cnt]))
			ft_msgerror ("No valid map.", 7);
		cnt++;
	}
	s_c3d->wrk_map[s_c3d->cnt_map++] = ft_strdup(s_c3d->line);
	s_c3d->wrk_map[s_c3d->cnt_map] = NULL;
	return ;
}

void	strg_map(t_cube *s_c3d, t_map *st_map)
{
	int		fd1;

	fd1 = 0;
	s_c3d->strg_map = 1;
	s_c3d->wrk_map = ft_calloc(s_c3d->map_lines + 1, sizeof(char **));
	fd1 = open(s_c3d->f_name, O_RDONLY);
	while (get_next_line(fd1, &s_c3d->line) == 1)
	{
		chk_parms(s_c3d, st_map);
		ft_free(s_c3d->line);
	}
	chk_parms(s_c3d, st_map);
	ft_free(s_c3d->line);
	return ;
}
