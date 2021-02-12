/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:22:37 by juasanto          #+#    #+#             */
/*   Updated: 2021/02/12 11:51:43 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		main(int argc, char **argv)
{
	char	**error_msg;

	error_msg = NULL;
	error_msg[1] = "Error de Mapa";
	error_msg[2] = "Demasiados parámetros";
	if (chk_args(argc, argv) == 1)
		printf("Falta nombre del mapa");
	if (chk_args(argc, argv) == 2)
		printf("Demasiados parámetros");
	return (0);
}
