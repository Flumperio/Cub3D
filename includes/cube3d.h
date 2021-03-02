/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 13:10:39 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/02 13:45:39 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../Libft/includes/libft.h"

#define NO	0
#define SO	1
#define WE	2
#define EA	3
#define S	4
#define R	5
#define F	6
#define C	7
typedef struct	s_tex
{
	char		*name;
	char		*path;
	int			exis;
	void		(*func)();
}				t_tex;

typedef struct	s_cube
{
	char		*line;
	char		*f_name;
	int			save_parm;
	int			cnt_i;
	//int			p_r;
	int			p_rx;
	int			p_ry;
	int			p_f;
	int			p_fr;
	int			p_fg;
	int			p_fb;
	int			p_c;
	int			p_cr;
	int			p_cg;
	int			p_cb;
	int			map_lines;
	int			tmp;
	t_tex		tex[9];
}				t_cube;

int				chk_args(int argc, char **argv, t_cube *s_c3d);
int				chk_file(t_cube *s_c3d);
void			inicialize(t_cube *s_c3d);
int				chk_ext(char *name, char *ext);
void			rmv_space(t_cube *s_c3d);
int				atoi_b(t_cube *s_c3d);
int				file_exist(char *file, char *name);
void			texture_all(t_cube *s_c3d, int index);
void			r_parm(t_cube *s_c3d);
void			f_parm(t_cube *s_c3d);
void			c_parm(t_cube *s_c3d);

#endif
