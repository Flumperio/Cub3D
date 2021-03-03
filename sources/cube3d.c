/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 10:31:45 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/03 12:51:41 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	main(int argc, char **argv)
{
	int			chk;
	t_cube		s_c3d;

	inicialize(&s_c3d);
	chk = chk_args(argc, argv, &s_c3d);
	printf("valor chk: %i\n", chk);
	printf("OK\n");
	chk_file(&s_c3d);
	system("leaks cube3d");
	return (0);
}
