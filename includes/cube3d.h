/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 13:10:39 by juasanto          #+#    #+#             */
/*   Updated: 2021/02/25 13:41:38 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../Libft/includes/libft.h"

typedef struct	s_cube
{
	char		*f_name;
	int			save_parm;
	int			cnt_i;
	int			p_r;
	int			p_rx;
	int			p_ry;
	int			p_no;
	char		*tex_no;
	int			p_so;
	int			p_we;
	int			p_ea;
	int			p_s;
	int			p_f;
	int			p_c;
	int			map_lines;
}				t_cube;

int				chk_args(int argc, char **argv, t_cube *s_c3d);
int				chk_file(t_cube *s_c3d);
void			inicialize(t_cube *s_c3d);
int				chk_ext(char *name, char *ext);

#endif
