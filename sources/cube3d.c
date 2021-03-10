/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 10:31:45 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/10 13:11:38 by juasanto         ###   ########.fr       */
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

void	init_wrk_map(t_cube *s_c3d)
{
	int	cnt;

	cnt = 0;
	while (cnt < 10)
	{
		s_c3d->tex[cnt].exis = 0;
		cnt ++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	int			chk;
	t_cube		s_c3d;
	int			tmp;

	tmp = 0;
	inicialize(&s_c3d);
	chk = chk_args(argc, argv, &s_c3d);
	chk_file(&s_c3d);
	while (s_c3d.wrk_map[tmp] != NULL)
	{
		printf("map_line: %s\n", s_c3d.wrk_map[tmp]);
		tmp++;
	}
	system("leaks cub3D");
	return (0);
}
