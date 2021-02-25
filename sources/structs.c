/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 13:08:21 by juasanto          #+#    #+#             */
/*   Updated: 2021/02/25 16:52:27 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void		inicialize(t_cube *s_c3d)
{
	s_c3d->f_name = NULL;
	s_c3d->save_parm = 0;
	s_c3d->cnt_i = 0;
	s_c3d->p_r = 0;
	s_c3d->p_rx = 0;
	s_c3d->p_ry = 0;
	s_c3d->p_no = 0;
	s_c3d->tex_no = NULL;
	s_c3d->tex_so = NULL;
	s_c3d->tex_we = NULL;
	s_c3d->tex_ea = NULL;
	s_c3d->p_so = 0;
	s_c3d->p_we = 0;
	s_c3d->p_ea = 0;
	s_c3d->p_s = 0;
	s_c3d->p_f = 0;
	s_c3d->p_c = 0;
	s_c3d->map_lines = 0;
	return ;
}
