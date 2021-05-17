/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 13:10:39 by juasanto          #+#    #+#             */
/*   Updated: 2021/05/17 15:46:02 by juasanto         ###   ########.fr       */
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
# define FOV 38
# define TEXTWIDTH 64
# define TEXTHEIGHT 64
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
	char			*name;
	char			*path;
	void			*img;
	int				exis;
	void			(*func)(struct s_cube *s_s3d);
}					t_tex;
/*
** Storage Textures
*/
typedef struct s_stx
{
	void			*img;
	char			*addr;
	int				bpp;
	int				ll;
	int				e;
	int				width;
	int				height;
}					t_stx;
/*
** Print Texture
*/
typedef struct s_ptx
{
	int				texNum;
	double			wallX;
	int				texX;
	int				texY;
	double			step;
	double			textPos;
	double			floorXWall;
	double			floorYWall;
	double			distWall;
	double			distPlayer;
	double			currentDist;
	double			weight;
	double			currentFloorX;
	double			currentFloorY;
	int				floorTexX;
	int				floorTexY;
}					t_ptx;
/*
** Player
*/
typedef struct s_pyr
{
	int				num;
	char			view;
	double			posX;
	double			posY;
}					t_pyr;
/*
** Move Booleans
*/
typedef struct s_bol
{
	int				key_fw;
	int				key_bw;
	int				key_rl;
	int				key_rr;
	int				key_sl;
	int				key_sr;
}					t_bol;
/*
** Sprites
*/
typedef struct s_osp
{
	double			x_pos;
	double			y_pos;
	int				spriteOrder;
	double			spriteDistance;
}					t_osp;
/*
** Sprites Order
*/
typedef struct s_mrg
{
	int				n1;
	int				n2;
}					t_mrg;
/*
** Calculator Sprites
*/
typedef struct s_spr
{
	int				sp_num;
	double			spriteX;
	double			spriteY;
	double			invDet;
	double			transformX;
	double			transformY;
	int				spriteScreenX;
	int				spriteHeight;
	int				drawStartY;
	int				drawEndY;
	int				spriteWidth;
	int				drawStartX;
	int				drawEndX;
	int				uDiv;
	int				vDiv;
	double			vMove;
	int				vMoveScreen;
}					t_spr;
/*
** MLX
*/
typedef struct s_mlx
{
	void			*mlx;
	void			*mlx_win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_mlx;
/*
** RayTracing
*/
typedef struct s_ray
{
	int				mapX;
	int				mapY;
	double			dirX;
	double			dirY;
	double			planeX;
	double			planeY;
	double			cameraX;
	double			rayDirX;
	double			rayDirY;
	double			sideDistX;
	double			sideDistY;
	double			deltaDistX;
	double			deltaDistY;
	double			perpWallDist;
	double			rotSpeed;
	double			moveSpeed;
	double			oldDirX;
	double			oldPlaneX;
	int				stepX;
	int				stepY;
	int				hit;
	int				side;
	int				lineHeight;
	int				drawStart;
	int				drawEnd;
	int				wall_color;
}					t_ray;
/*
** Main Structure
*/
typedef struct s_cube
{
	char			*line;
	char			*f_name;
	int				save_parm;
	int				cnt_i;
	int				resX;
	int				resY;
	int				p_fr;
	int				p_fg;
	int				p_fb;
	int				p_cr;
	int				p_cg;
	int				p_cb;
	int				f_color;
	int				c_color;
	int				map_lines;
	int				tmp;
	int				strg_map;
	char			**wrk_map;
	char			**tmp_map;
	char			*map_value;
	int				cnt_map;
	int				cnt_2;
	double			*ZBuffer;
	t_osp			*osp;
	t_osp			*spr_l;
	t_osp			*spr_d;
	t_mrg			mrg;
	t_spr			spr;
	t_pyr			pyr;
	t_mlx			mlx;
	t_ray			ray;
	t_bol			bol;
	t_ptx			ptx;
	t_tex			tex[13];
	t_stx			stx[7];
	int				id;
}					t_cube;
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
int				to_rgb(int r, int g, int b);
void			my_mlx_pixel_put(t_cube *cub, int x, int y, int color);
int				my_get_color_pixel(t_cube *cub, int x, int y);
void			stg_tex(t_cube *cub);
void			set_color_wall(t_cube *cub);
void			free_all(t_cube *cub);
/*
** Key Manage
*/
int				ui_cross_exit(t_cube *cub);
int				key_press(int keycode, t_cube *cub);
int				key_relea(int keycode, t_cube *cub);
void			pl_move(t_cube *cub);
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
void			raycast(t_cube *cub);
void			init_ray(t_cube *cub);
void			init_raydir_x_y(t_cube *cub, int x);
void			set_raydir_x_y(t_cube *cub);
void			hit_raydir_x_y(t_cube *cub);
void			size_raydir_x_y(t_cube *cub);
int				paint_floor(t_cube *cub, int x, int y);
int				paint_ceiling(t_cube *cub, int x, int y);
void			print_raydir_x_y(t_cube *cub, int x);
/*
** Print RayCast
*/
void			set_tex_id(t_cube *cub);
void			set_fc_id(t_cube *cub);
void			text_calc(t_cube *cub);
int				paint_wall(t_cube *cub, int x, int y);
int				print_fc(t_cube *cub, int x, int y, int max_y);
/*
** Sprites
*/
void			sprites(t_cube *cub);
void			sprites_print (t_cube *cub);
void			sprites_sort(t_cube *cub, int l, int r);
/*
** Funtions Moves
*/
void			sprites_sort(t_cube *cub, int l, int r);
void			merge_copy(t_cube *cub, int l, int m);
void			merge_swap(t_cube *cub, int i, int j, int k);
void			merge(t_cube *cub, int l, int m, int r);
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
