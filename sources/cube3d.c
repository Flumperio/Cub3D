/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:22:37 by juasanto          #+#    #+#             */
/*   Updated: 2021/02/15 17:48:51 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		main(int argc, char **argv)
{
	char	*error_msg[4];
	int		chk;

	error_msg[0] = "Error. No hay parametros";
	error_msg[1] = "Error. Demasiados parámetros";
	error_msg[2] = "Error. La extensión del archivo no es correcta";
	error_msg[3] = "Error. El parametro no es correcto.";
	chk = chk_args(argc, argv);
	printf("valor chk: %i\n", chk);
	if (chk != 0)
	{
		printf("%s\n", error_msg[chk - 1]);
		return (chk);
	}
	printf("OK\n");
	return (0);
}
