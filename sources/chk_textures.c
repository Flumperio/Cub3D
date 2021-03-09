/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:47:09 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/09 13:24:34 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	texture_all(t_cube *s_c3d)
{
	s_c3d->cnt_i += 2;
	rmv_space(s_c3d);
	s_c3d->tex[s_c3d->tmp].path = ft_strdup(&s_c3d->line[s_c3d->cnt_i]);
	if (chk_ext(s_c3d->tex[s_c3d->tmp].path, ".xpm") == 0)
		s_c3d->tex[s_c3d->tmp].exis = 1;
	else
	{
		ft_printf("Texture Extension %s is not correct.\n",
		s_c3d->tex[s_c3d->tmp].name);
		exit(9);
	}
	file_exist(s_c3d->tex[s_c3d->tmp].path, s_c3d->tex[s_c3d->tmp].name);
	s_c3d->cnt_i = ft_strlen(s_c3d->line);
}
