/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 08:53:35 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/04 17:32:28 by jcsantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	inicialize(t_cube *s_c3d)
{
	ft_bzero(s_c3d, sizeof(t_cube));
	s_c3d->tex[0] = (t_tex){"NO", NULL, 0, texture_all};
	s_c3d->tex[1] = (t_tex){"SO", NULL, 0, texture_all};
	s_c3d->tex[2] = (t_tex){"WE", NULL, 0, texture_all};
	s_c3d->tex[3] = (t_tex){"EA", NULL, 0, texture_all};
	s_c3d->tex[4] = (t_tex){"S", NULL, 0, texture_all};
	s_c3d->tex[5] = (t_tex){"R", NULL, 0, r_parm};
	s_c3d->tex[6] = (t_tex){"F", NULL, 0, f_parm};
	s_c3d->tex[7] = (t_tex){"C", NULL, 0, c_parm};
	s_c3d->tex[8] = (t_tex){"1", NULL, 0, chk_map};
	s_c3d->tex[9] = (t_tex){"0", NULL, 0, chk_map};
	s_c3d->tex[10].name = NULL;
}
