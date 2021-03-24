/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 12:36:59 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/24 12:08:15 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	fill_options(t_cube *s_c3d)
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
				s_c3d->tex[s_c3d->tmp].func(s_c3d);
				free(name);
				return (1);
			}
		}
		s_c3d->tmp++;
	}
	free(name);
	return (0);
}

int	chk_parms(t_cube *s_c3d)
{
	s_c3d->tmp = 0;
	s_c3d->cnt_i = 0;
	rmv_space(s_c3d);
	while (s_c3d->line[s_c3d->cnt_i] != '\0')
	{
		if (fill_options(s_c3d) == 1)
			return (1);
		else
			ft_msgerror("Invalid parameters in file.", 6);
		s_c3d->cnt_i++;
	}
	return (0);
}

int	chk_file(t_cube *s_c3d)
{
	int		fd1;

	fd1 = open(s_c3d->f_name, O_RDONLY);
	if (fd1 < 0)
		ft_msgerror("No existe el ficheo", 5);
	while (get_next_line(fd1, &s_c3d->line) == 1)
	{
		chk_parms(s_c3d);
		free(s_c3d->line);
	}
	chk_parms(s_c3d);
	free(s_c3d->line);
	return (0);
}
