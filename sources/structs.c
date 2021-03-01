/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 08:53:35 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/01 16:35:13 by jcsantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void		inicialize(t_cube *s_c3d)
{
	ft_bzero(s_c3d, sizeof(t_cube));
	s_c3d->tex[0].name = "NO";
	s_c3d->tex[1].name = "SO";
	s_c3d->tex[2].name = "WE";
	s_c3d->tex[3].name = "EA";
	s_c3d->tex[4].name = "S";
	s_c3d->tex[5].name = "R";
	s_c3d->tex[6].name = "F";
	s_c3d->tex[7].name = "C";
	s_c3d->tex[8].name = NULL;
	//s_c3d->tex[8].func = chk_args;
}
