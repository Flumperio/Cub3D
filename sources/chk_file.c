/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 12:36:59 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/23 12:42:52 by jcsantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	fill_options(t_cube *s_c3d, t_map *st_map)
{
	char	*name;

	s_c3d->tmp = 0;
	name = ft_substr(&s_c3d->line[s_c3d->cnt_i], 0,
			!ft_isspace(s_c3d->line[s_c3d->cnt_i + 1]) + 1);
	while (s_c3d->tex[s_c3d->tmp].name != 0)
	{
		if (ft_strncmp(name, s_c3d->tex[s_c3d->tmp].name, \
				ft_strlen(s_c3d->tex[s_c3d->tmp].name)) == 0)
		{
			if (s_c3d->tex[s_c3d->tmp].exis == 1 && s_c3d->strg_map == 0)
				ft_msgerror("Option Duplicated.", 6);
			else
			{
				s_c3d->tex[s_c3d->tmp].exis = 1;
				s_c3d->tex[s_c3d->tmp].func(s_c3d, st_map);
				free(name);
				return (1);
			}
		}
		s_c3d->tmp++;
	}
	free(name);
	return (0);
}

int	chk_parms(t_cube *s_c3d, t_map *st_map)
{
	s_c3d->tmp = 0;
	s_c3d->cnt_i = 0;
	rmv_space(s_c3d);
	while (s_c3d->line[s_c3d->cnt_i] != '\0')
	{
		if (fill_options(s_c3d, st_map) == 1)
			return (1);
		else
			ft_msgerror("Invalid parameters in file.", 6);
		s_c3d->cnt_i++;
	}
	return (0);
}

int	chk_file(t_cube *s_c3d, t_map *st_map)
{
	int		fd1;

	fd1 = open(s_c3d->f_name, O_RDONLY);
	if (fd1 < 0)
		ft_msgerror("No existe el ficheo", 5);
	while (get_next_line(fd1, &s_c3d->line) == 1)
	{
		chk_parms(s_c3d, st_map);
		free(s_c3d->line);
	}
	chk_parms(s_c3d, st_map);
	free(s_c3d->line);
	// strg_map(s_c3d, st_map);
	// st_map = ft_calloc(st_map->num_2 + 1, sizeof(st_map));
	// tmp_map(s_c3d, st_map);
	// printf("%i - %i\n", st_map[0].x_pos, st_map[0].y_pos);
	// cnt_3 = 0;
	// printf("num_2: %i\n", st_map->num_2);
	// while (st_map[cnt_3].x_pos != 0)
	// {
	// 	printf("pos: %i, x: %i - y: %i\n", cnt_3, \
	// 		st_map[cnt_3].x_pos, st_map[cnt_3].y_pos);
	// 	cnt_3++;
	// }
	return (0);
}
