/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:47:09 by juasanto          #+#    #+#             */
/*   Updated: 2021/02/25 18:00:41 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	texture_no(char *line, t_cube *s_c3d)
{
	char	*tmp;

	tmp = NULL;
	s_c3d->cnt_i += 2;
	rmv_space(line, s_c3d);
	tmp = ft_strdup(&line[s_c3d->cnt_i]);
	s_c3d->tex_no = tmp;
	if (chk_ext(s_c3d->tex_no, ".xpm") == 0)
		s_c3d->p_no = 1;
	else
		ft_msgerror("Texture Extension NO is not correct.", 9);
	file_exist(s_c3d->tex_no, "NO");
	s_c3d->cnt_i = ft_strlen(line);
	//free(tmp);
	return ;
}

void	texture_so(char *line, t_cube *s_c3d)
{
	char	*tmp;

	tmp = NULL;
	s_c3d->cnt_i += 2;
	rmv_space(line, s_c3d);
	tmp = ft_strdup(&line[s_c3d->cnt_i]);
	s_c3d->tex_so = tmp;
	if (chk_ext(s_c3d->tex_so, ".xpm") == 0)
		s_c3d->p_so = 1;
	else
		ft_msgerror("Texture Extension SO is not correct.", 9);
	file_exist(s_c3d->tex_so, "SO");
	s_c3d->cnt_i = ft_strlen(line);
	//free(tmp);
	return ;
}

void	texture_we(char *line, t_cube *s_c3d)
{
	char	*tmp;

	tmp = NULL;
	s_c3d->cnt_i += 2;
	rmv_space(line, s_c3d);
	tmp = ft_strdup(&line[s_c3d->cnt_i]);
	s_c3d->tex_we = tmp;
	if (chk_ext(s_c3d->tex_we, ".xpm") == 0)
		s_c3d->p_we = 1;
	else
		ft_msgerror("Texture Extension WE is not correct.", 9);
	file_exist(s_c3d->tex_we, "WE");
	s_c3d->cnt_i = ft_strlen(line);
	//free(tmp);
	return ;
}

void	texture_ea(char *line, t_cube *s_c3d)
{
	char	*tmp;

	tmp = NULL;
	s_c3d->cnt_i += 2;
	rmv_space(line, s_c3d);
	tmp = ft_strdup(&line[s_c3d->cnt_i]);
	s_c3d->tex_ea = tmp;
	if (chk_ext(s_c3d->tex_ea, ".xpm") == 0)
		s_c3d->p_ea = 1;
	else
		ft_msgerror("Texture Extension EA is not correct.", 9);
	file_exist(s_c3d->tex_ea, "EA");
	s_c3d->cnt_i = ft_strlen(line);
	//free(tmp);
	return ;
}
