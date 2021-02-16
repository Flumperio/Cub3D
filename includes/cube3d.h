/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:37:28 by juasanto          #+#    #+#             */
/*   Updated: 2021/02/16 13:15:09 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../Libft/libft.h"

typedef struct s_parms
{
	char	*f_name;
	int		save_parm;

}				t_parms;

int			chk_args(int argc, char **argv, t_parms *s_c3d);

#endif
