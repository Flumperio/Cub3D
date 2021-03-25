/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 13:10:39 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/25 12:24:00 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <time.h>
# include "../Libft/includes/libft.h"

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define S 4
# define R 5
# define F 6
# define C 7

struct	s_cube;

typedef	struct s_map
{
	int				sp_num;
	int				x_pos;
	int				y_pos;
	//int				num_2;
	int				temp;
}					t_map;

typedef struct s_tex
{
	char		*name;
	char		*path;
	int			exis;
	void		(*func)(struct s_cube *s_s3d);
}				t_tex;

typedef struct s_cube
{
	char		*line;
	char		*f_name;
	int			save_parm;
	int			cnt_i;
	int			p_rx;
	int			p_ry;
	int			p_fr;
	int			p_fg;
	int			p_fb;
	int			p_cr;
	int			p_cg;
	int			p_cb;
	int			map_lines;
	int			tmp;
	int			strg_map;
	char		**wrk_map;
	char		**tmp_map;
	char		*map_value;
	int			cnt_map;
	int			cnt_2;
	int			pl_num;
	char		pl_view;
	int			pl_posx;
	int			pl_posy;
	t_tex		tex[11];
}				t_cube;

int				chk_args(int argc, char **argv, t_cube *cub);
int				chk_file(t_cube *cub);
void			inicialize(t_cube *cub);
int				chk_ext(char *name, char *ext);
void			rmv_space(t_cube *cub);
int				atoi_b(t_cube *cub);
int				file_exist(char *file, char *name);
void			texture_all(t_cube *cub);
int				chk_value(char *number, int min_value, int max_value);
void			r_parm(t_cube *cub);
void			f_parm(t_cube *cub);
void			c_parm(t_cube *cub);
void			chk_map(t_cube *cub);
void			chk_r_value(t_cube *cub);
void			chk_fc_value(t_cube *cub);
void			strg_map(t_cube *cub);
int				chk_parms(t_cube *cub);
void			cnvrt_map(t_cube *cub);
void			tmp_map(t_cube *cub, t_map *map);

#endif
