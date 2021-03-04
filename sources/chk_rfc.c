/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_rfc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:47:28 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/04 17:32:01 by jcsantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	chk_value(char *number, int min_value, int max_value)
{
	int		value;

	value = ft_atoi(number);
	if (value < min_value || value > max_value)
		ft_msgerror("Error in the value of parameters.", 6);
	return (value);
}

void	r_parm(t_cube *s_c3d)
{
	char	**num_val;

	s_c3d->tmp = 0;
	num_val = ft_split(&s_c3d->line[++s_c3d->cnt_i], ' ');
	while (num_val[s_c3d->tmp] != '\0')
		s_c3d->tmp++;
	if (s_c3d->tmp != 2)
		ft_msgerror("Error in the parametres of Resolution (R).", 6);
	else
	{
		s_c3d->p_rx = chk_value(num_val[0], 1, 4000);
		s_c3d->p_ry = chk_value(num_val[1], 1, 4000);
	}
	s_c3d->cnt_i = ft_strlen(s_c3d->line);
	return ;
}

void	f_parm(t_cube *s_c3d)
{
	char	**num_val;

	s_c3d->tmp = 0;
	num_val = ft_split(&s_c3d->line[++s_c3d->cnt_i], ',');
	while (num_val[s_c3d->tmp] != '\0')
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
	return ;
}

void	c_parm(t_cube *s_c3d)
{
	char	**num_val;

	s_c3d->tmp = 0;
	num_val = ft_split(&s_c3d->line[++s_c3d->cnt_i], ',');
	while (num_val[s_c3d->tmp] != '\0')
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
	return ;
}
