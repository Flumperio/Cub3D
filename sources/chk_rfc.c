/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_rfc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:47:28 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/09 14:38:24 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	free_array(char **str)
{
	int	cnt;

	cnt = 0;
	if (!str)
		return ;
	while (str[cnt])
	{
		free(str[cnt]);
		str[cnt++] = NULL;
	}
	free(str);
	str = NULL;
}

void	r_parm(t_cube *s_c3d)
{
	char	**num_val;

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
	printf("num_val - r: %p\n", num_val);
	printf("r_parm - 1: %p\n", *num_val);
	free_array(num_val);
	return ;
}


void	f_parm(t_cube *s_c3d)
{
	char	**num_val;

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
	printf("num_val - f: %p\n", num_val);
	free_array(num_val);
	return ;
}

void	c_parm(t_cube *s_c3d)
{
	char	**num_val;

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
	printf("num_val - c: %p\n", num_val);
	free_array(num_val);
	return ;
}
