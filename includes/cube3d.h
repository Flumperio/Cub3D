/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:37:28 by juasanto          #+#    #+#             */
/*   Updated: 2021/02/23 17:51:56 by juasanto         ###   ########.fr       */
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
	int			p_no;
	int			p_so;
	int			p_we;
	int			p_ea;
	int			p_s;
	int			p_f;
	int			p_c;


}				t_cube;

int				chk_args(int argc, char **argv, t_cube *s_c3d);
int				chk_file(t_cube *s_c3d);

#endif
