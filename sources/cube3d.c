/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:01:06 by juasanto          #+#    #+#             */
/*   Updated: 2021/02/22 12:45:42 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	main(int argc, char **argv)
{
	int			chk;
	t_cube		s_c3d;

	chk = chk_args(argc, argv, &s_c3d);
	printf("valor chk: %i\n", chk);
	printf("OK\n");
	chk_file(&s_c3d);
	return (0);
}
