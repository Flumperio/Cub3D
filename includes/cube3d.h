/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 13:10:39 by juasanto          #+#    #+#             */
/*   Updated: 2021/04/15 19:14:00 by juasanto         ###   ########.fr       */
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
# include "../minilibx/mlx.h"

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define S 4
# define R 5
# define F 6
# define C 7

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
	int		res_X;
	int		res_Y;
	int		mapX;
	int		mapY;
	int		pl_X;
	int		pl_Y;
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





	double	posX;
	double	posY;

	char	**map;
	int		f_color;
	int		c_color;
}					t_ray;
/*
** Main
*/
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
	t_tex		tex[11];
	t_map		*sprites;
	t_pyr		pyr;
	t_mlx		mlx;
	t_ray		ray;
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
void			tmp_map(t_cube *cub);
int				cls_map(t_cube *cub, int x, int y);
void			test(t_cube *cub);

#endif
