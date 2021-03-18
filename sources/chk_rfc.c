/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_rfc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:47:28 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/18 13:58:17 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	texture_all(t_cube *s_c3d, t_map *st_map)
{
	st_map->temp = 0;
	if (s_c3d->wrk_map == 0)
	{
		s_c3d->cnt_i += 2;
		rmv_space(s_c3d);
		s_c3d->tex[s_c3d->tmp].path = ft_strdup(&s_c3d->line[s_c3d->cnt_i]);
		if (chk_ext(s_c3d->tex[s_c3d->tmp].path, ".xpm") == 0)
			s_c3d->tex[s_c3d->tmp].exis = 1;
		else
		{
			printf("Texture Extension %s is not correct.\n",
			s_c3d->tex[s_c3d->tmp].name);
			exit(9);
		}
		file_exist(s_c3d->tex[s_c3d->tmp].path, s_c3d->tex[s_c3d->tmp].name);
		s_c3d->cnt_i = ft_strlen(s_c3d->line);
	}
}

void	r_parm(t_cube *s_c3d, t_map *st_map)
{
	char	**num_val;

	st_map->temp = 0;
	if (s_c3d->wrk_map == 0)
	{
		s_c3d->tmp = 0;
		chk_r_value(s_c3d);
		num_val = ft_split(&s_c3d->line[++s_c3d->cnt_i], ' ');
		while (num_val[s_c3d->tmp] != NULL)
			s_c3d->tmp++;
		if (s_c3d->tmp != 2)
			ft_msgerror("Error in the parametres of Resolution (R).", 6);
		else
		{
			s_c3d->p_rx = chk_value(num_val[0], 1, INT32_MAX);
			s_c3d->p_ry = chk_value(num_val[1], 1, INT32_MAX);
		}
		s_c3d->cnt_i = ft_strlen(s_c3d->line);
		ft_free_array(num_val);
		return ;
	}
}

void	f_parm(t_cube *s_c3d, t_map *st_map)
{
	char	**num_val;

	st_map->temp = 0;
	if (s_c3d->wrk_map == 0)
	{
		s_c3d->tmp = 0;
		chk_fc_value(s_c3d);
		num_val = ft_split(&s_c3d->line[++s_c3d->cnt_i], ',');
		while (num_val[s_c3d->tmp] != NULL)
			s_c3d->tmp++;
		if (s_c3d->tmp != 3)
			ft_msgerror("Error in the parametres of Floor (F).", 6);
		else
		{
			s_c3d->p_fr = chk_value(num_val[0], 0, 255);
			s_c3d->p_fg = chk_value(num_val[1], 0, 255);
			s_c3d->p_fb = chk_value(num_val[2], 0, 255);
		}
		s_c3d->cnt_i = ft_strlen(s_c3d->line);
		ft_free_array(num_val);
		return ;
	}
}

void	c_parm(t_cube *s_c3d, t_map *st_map)
{
	char	**num_val;

	st_map->temp = 0;
	if (s_c3d->wrk_map == 0)
	{
		s_c3d->tmp = 0;
		chk_fc_value(s_c3d);
		num_val = ft_split(&s_c3d->line[++s_c3d->cnt_i], ',');
		while (num_val[s_c3d->tmp] != NULL)
			s_c3d->tmp++;
		if (s_c3d->tmp != 3)
			ft_msgerror("Error in the parametres of Ceilling (C).", 6);
		else
		{
			s_c3d->p_cr = chk_value(num_val[0], 0, 255);
			s_c3d->p_cg = chk_value(num_val[1], 0, 255);
			s_c3d->p_cb = chk_value(num_val[2], 0, 255);
		}
		s_c3d->cnt_i = ft_strlen(s_c3d->line);
		ft_free_array(num_val);
		return ;
	}
}

void	chk_map(t_cube *s_c3d, t_map *st_map)
{
	s_c3d->tmp = 0;
	s_c3d->tex[8].exis = 0;
	s_c3d->tex[9].exis = 0;
	if (s_c3d->strg_map == 1)
		cnvrt_map(s_c3d, st_map);
	else
	{
		if (s_c3d->map_lines < 2)
		{
			while (s_c3d->tex[s_c3d->tmp].exis == 1)
				s_c3d->tmp++;
			if (s_c3d->tmp < 8)
				ft_msgerror("Not enough parameters.", 7);
		}
	}
	s_c3d->map_lines++;
	s_c3d->cnt_i = ft_strlen(s_c3d->line);
	return ;
}
