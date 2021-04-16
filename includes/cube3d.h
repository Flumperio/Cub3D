/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 13:10:39 by juasanto          #+#    #+#             */
/*   Updated: 2021/04/16 14:27:41 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

/*
** Libraries
*/
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <time.h>
# include <math.h>
# include "../Libft/includes/libft.h"
# include "../minilibx/mlx.h"

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define S 4
# define R 5
# define F 6
# define C 7
/*
** Define Keys
*/
# define KEY_FW 13
# define KEY_BW 1
# define KEY_RR 2
# define KEY_RL 0
# define KEY_SR 14
# define KEY_SL 12
# define KEY_ESC 53
/*
** Predefiniton S_Cube
*/
struct	s_cube;
/*
** Gestion Texturas Fichero
*/
typedef struct s_tex
{
	char		*name;
	char		*path;
	void		*img;
	int			exis;
	void		(*func)(struct s_cube *s_s3d);
}				t_tex;
/*
** Player
*/
typedef struct s_pyr
{
	int			num;
	char		view;
	double		posX;
	double		posY;
}				t_pyr;
/*
** Sprites
*/
typedef struct s_map
{
	int				sp_num;
	int				x_pos;
	int				y_pos;
}					t_map;
/*
** MLX
*/
typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}					t_mlx;
/*
** RayTracing
*/
typedef struct s_ray
{
	int		mapX;
	int		mapY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	double	rotSpeed;
	double	moveSpeed;
	double	oldDirX;
	double	oldPlaneX;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;

}					t_ray;
/*
** Main Structure
*/
typedef struct s_cube
{
	char		*line;
	char		*f_name;
	int			save_parm;
	int			cnt_i;
	int			resX;
	int			resY;
	int			p_fr;
	int			p_fg;
	int			p_fb;
	int			p_cr;
	int			p_cg;
	int			p_cb;
	int			f_color;
	int			c_color;
	int			map_lines;
	int			tmp;
	int			strg_map;
	char		**wrk_map;
	char		**tmp_map;
	char		*map_value;
	int			cnt_map;
	int			cnt_2;
	t_tex		tex[11];
	t_map		*sprites;
	t_pyr		pyr;
	t_mlx		mlx;
	t_ray		ray;
}				t_cube;
/*
** Check Arguments
*/
int				chk_args(int argc, char **argv, t_cube *cub);
int				chk_file(t_cube *cub);
int				chk_ext(char *name, char *ext);
int				chk_value(char *number, int min_value, int max_value);
void			chk_map(t_cube *cub);
void			chk_r_value(t_cube *cub);
void			chk_fc_value(t_cube *cub);
int				chk_parms(t_cube *cub);
/*
** Utils
*/
void			inicialize(t_cube *cub);
void			rmv_space(t_cube *cub);
int				atoi_b(t_cube *cub);
int				file_exist(char *file, char *name);
void			texture_all(t_cube *cub);
/*
** Storage Values
*/
void			r_parm(t_cube *cub);
void			f_parm(t_cube *cub);
void			c_parm(t_cube *cub);
void			strg_map(t_cube *cub);
/*
** Maps Operations
*/
void			cnvrt_map(t_cube *cub);
void			tmp_map(t_cube *cub);
int				cls_map(t_cube *cub, int x, int y);
/*
** RayCast
*/
void			test(t_cube *cub);
/*
** Funtions Moves
*/
void			move_fw(t_cube *cub);
void			move_bw(t_cube *cub);
void			move_sl(t_cube *cub);
void			move_sr(t_cube *cub);
void			move_rr(t_cube *cub);
void			move_rl(t_cube *cub);

#endif
