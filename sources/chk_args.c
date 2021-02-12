/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:20:01 by juasanto          #+#    #+#             */
/*   Updated: 2021/02/12 11:42:50 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	chk_args(int argc, char **argv)
{
	int		cnt;

	cnt = 0;
	if (argc <= 1)
		return (1);
	if (argc > 3)
		return (2);
	while (cnt < argc)
	{
		printf("N.Args: %i -- Argumento: %i --- Parametro: %s\n", argc, cnt, argv[cnt]);
		cnt++;
	}
	return (0);
}
