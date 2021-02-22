/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:37:28 by juasanto          #+#    #+#             */
/*   Updated: 2021/02/22 12:40:19 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../Libft/includes/libft.h"

typedef struct	s_cube
{
	char		*f_name;
	int			save_parm;

}				t_cube;

int				chk_args(int argc, char **argv, t_cube *s_c3d);
int				chk_file(t_cube *s_c3d);

#endif
