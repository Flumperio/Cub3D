/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 12:36:59 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/20 12:49:22 by jcsantos         ###   ########.fr       */
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
	//init_wrk_map(s_c3d);
	strg_map(s_c3d, st_map);
	// tmp_map(s_c3d, st_map);
	return (0);
}
