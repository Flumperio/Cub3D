/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mng.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:51:55 by juasanto          #+#    #+#             */
/*   Updated: 2021/04/20 16:53:38 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	ui_cross_exit(t_cube *cub)
{
	mlx_destroy_window(cub->mlx.mlx, cub->mlx.mlx_win);
	system("leaks cub3D");
	exit (0);
}

int	key_press(int keycode, t_cube *cub)
{
	printf("keykode: %i\n", keycode);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(cub->mlx.mlx, cub->mlx.mlx_win);
		system("leaks cub3D");
		exit (0);
	}
	if (keycode == KEY_FW)
		cub->bol.key_fw = 1;
	if (keycode == KEY_BW)
		cub->bol.key_bw = 1;
	if (keycode == KEY_RL)
		cub->bol.key_rl = 1;
	if (keycode == KEY_RR)
		cub->bol.key_rr = 1;
	if (keycode == KEY_SL)
		cub->bol.key_sl = 1;
	if (keycode == KEY_SR)
		cub->bol.key_sr = 1;
	return (0);
}

int	key_relea(int keycode, t_cube *cub)
{
	printf("keykode: %i\n", keycode);
	if (keycode == KEY_FW)
		cub->bol.key_fw = 0;
	if (keycode == KEY_BW)
		cub->bol.key_bw = 0;
	if (keycode == KEY_RL)
		cub->bol.key_rl = 0;
	if (keycode == KEY_RR)
		cub->bol.key_rr = 0;
	if (keycode == KEY_SL)
		cub->bol.key_sl = 0;
	if (keycode == KEY_SR)
		cub->bol.key_sr = 0;
	return (0);
}

void	pl_move(t_cube *cub)
{
	if (cub->bol.key_fw == 1)
		move_fw(cub);
	if (cub->bol.key_bw == 1)
		move_bw(cub);
	if (cub->bol.key_rl == 1)
		move_rl(cub);
	if (cub->bol.key_rr == 1)
		move_rr(cub);
	if (cub->bol.key_sl == 1)
		move_sl(cub);
	if (cub->bol.key_sr == 1)
		move_sr(cub);
}