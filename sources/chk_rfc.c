/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_rfc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:47:28 by juasanto          #+#    #+#             */
/*   Updated: 2021/04/28 15:11:27 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	texture_all(t_cube *cub)
{
	if (cub->wrk_map == 0)
	{
		cub->cnt_i += 2;
		rmv_space(cub);
		cub->tex[cub->tmp].path = ft_strdup(&cub->line[cub->cnt_i]);
		if (chk_ext(cub->tex[cub->tmp].path, ".xpm") == 0)
			cub->tex[cub->tmp].exis = 1;
		else
		{
			printf("Texture Extension %s is not correct.\n",
				cub->tex[cub->tmp].name);
			exit(9);
		}
		file_exist(cub->tex[cub->tmp].path, cub->tex[cub->tmp].name);
		cub->cnt_i = ft_strlen(cub->line);
	}
}

void	r_parm(t_cube *cub)
{
	char	**num_val;

	if (cub->wrk_map == 0)
	{
		cub->tmp = 0;
		chk_r_value(cub);
		num_val = ft_split(&cub->line[++cub->cnt_i], ' ');
		while (num_val[cub->tmp] != NULL)
			cub->tmp++;
		if (cub->tmp != 2)
			ft_msgerror("Error in the parametres of Resolution (R).", 6);
		else
		{
			cub->resX = chk_value(num_val[0], 1, INT32_MAX);
			cub->resY = chk_value(num_val[1], 1, INT32_MAX);
		}
		cub->cnt_i = ft_strlen(cub->line);
		ft_free_array(num_val);
		return ;
	}
}

void	f_parm(t_cube *cub)
{
	char	**num_val;

	if (cub->wrk_map == 0)
	{
		cub->tmp = 0;
		chk_fc_value(cub);
		num_val = ft_split(&cub->line[++cub->cnt_i], ',');
		while (num_val[cub->tmp] != NULL)
			cub->tmp++;
		if (cub->tmp != 3)
			ft_msgerror("Error in the parametres of Floor (F).", 6);
		else
		{
			cub->p_fr = chk_value(num_val[0], 0, 255);
			cub->p_fg = chk_value(num_val[1], 0, 255);
			cub->p_fb = chk_value(num_val[2], 0, 255);
		}
		cub->cnt_i = ft_strlen(cub->line);
		ft_free_array(num_val);
		return ;
	}
}

void	c_parm(t_cube *cub)
{
	char	**num_val;

	if (cub->wrk_map == 0)
	{
		cub->tmp = 0;
		chk_fc_value(cub);
		num_val = ft_split(&cub->line[++cub->cnt_i], ',');
		while (num_val[cub->tmp] != NULL)
			cub->tmp++;
		if (cub->tmp != 3)
			ft_msgerror("Error in the parametres of Ceilling (C).", 6);
		else
		{
			cub->p_cr = chk_value(num_val[0], 0, 255);
			cub->p_cg = chk_value(num_val[1], 0, 255);
			cub->p_cb = chk_value(num_val[2], 0, 255);
		}
		cub->cnt_i = ft_strlen(cub->line);
		ft_free_array(num_val);
		return ;
	}
}

void	chk_map(t_cube *cub)
{
	int	cnt;

	cnt = 0;
	cub->tex[10].exis = 0;
	cub->tex[11].exis = 0;
	if (cub->strg_map == 1)
		cnvrt_map(cub);
	else
	{
		if (cub->map_lines < 2)
		{
			while (cub->tex[cnt].exis == 1)
				cnt++;
			if (cnt < 8)
				ft_msgerror("Not enough parameters.", 7);
		}
	}
	cub->map_lines++;
	cub->cnt_i = ft_strlen(cub->line);
	return ;
}
