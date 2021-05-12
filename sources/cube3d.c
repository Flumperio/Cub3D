/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 10:31:45 by juasanto          #+#    #+#             */
/*   Updated: 2021/05/12 16:19:24 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	init_c3d(t_cube *cub)
{
	ft_bzero(cub, sizeof(t_cube));
	cub->tex[0] = (t_tex){"NO", NULL, NULL, 0, texture_all};
	cub->tex[1] = (t_tex){"SO", NULL, NULL, 0, texture_all};
	cub->tex[2] = (t_tex){"WE", NULL, NULL, 0, texture_all};
	cub->tex[3] = (t_tex){"EA", NULL, NULL, 0, texture_all};
	cub->tex[4] = (t_tex){"S", NULL, NULL, 0, texture_all};
	cub->tex[5] = (t_tex){"TF", NULL, NULL, 0, texture_all};
	cub->tex[6] = (t_tex){"UT", NULL, NULL, 0, texture_all};
	cub->tex[7] = (t_tex){"R", NULL, NULL, 0, r_parm};
	cub->tex[8] = (t_tex){"F", NULL, NULL, 0, f_parm};
	cub->tex[9] = (t_tex){"C", NULL, NULL, 0, c_parm};
	cub->tex[10] = (t_tex){"1", NULL, NULL, 0, chk_map};
	cub->tex[11] = (t_tex){"0", NULL, NULL, 0, chk_map};
	cub->tex[12].name = NULL;
	cub->map_value = "012NSWE \t";
}

int	main(int argc, char **argv)
{
	t_cube		cub;
	int			tmp;
	int			cnt;

	tmp = 0;
	cnt = 0;
	init_c3d(&cub);
	chk_args(argc, argv, &cub);
	chk_file(&cub);
	strg_map(&cub);
	cub.osp = (t_osp *)ft_calloc(sizeof(t_spr), cub.cnt_2 + 1);
	tmp_map(&cub);
	cls_map(&cub, cub.pyr.posX, cub.pyr.posY);
	raycast(&cub);
	printf("MAP OK.\n");
	system("leaks cub3D");
	return (0);
}
