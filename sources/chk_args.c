/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:20:01 by juasanto          #+#    #+#             */
/*   Updated: 2021/02/15 18:14:25 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	chk_name(char *name)
{
	char	*test_ext;

	test_ext = &name[(ft_strlen(name) - 4)];
	if(ft_strcmp(test_ext, ".cub") == 0)
		return (0);
	return (3);
}

int	chk_save(char *save)
{
	if(ft_strcmp(save, "--save") == 0)
		return (0);
	return (4);
}



int	chk_args(int argc, char **argv)
{
	int		cnt;

	cnt = 0;
	/* While para comprobar los argumentos, Borrar */
	while (cnt < argc)
	{
		printf("N.Args: %i -- Argumento: %i --- Parametro: %s\n", argc, cnt, argv[cnt]);
		cnt++;
	}
	/* Borrar While */
	if (argc <= 1)
		return (1);
	if (argc > 3)
		return (2);
	if (chk_name(argv[1]) != 0)
		return (3);
	if (argv[2] && chk_save(argv[2]) != 0)
		return (4);
	return (0);
}
