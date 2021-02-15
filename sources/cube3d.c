/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:22:37 by juasanto          #+#    #+#             */
/*   Updated: 2021/02/15 12:59:34 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		main(int argc, char **argv)
{
	char	*error_msg[]= { "Error. No hay parametros", "Error. Demasiados parámetros" };
	int		chk;

	chk = 0;
	chk = chk_args(argc, argv);
	printf("Valor de chk: %i\n", chk);
	if (chk != 0)
	{
		printf("%s", error_msg[chk - 1]);
		return (chk);
	}
	printf("OK");
	return (0);
}
