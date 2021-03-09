/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:46:04 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/09 16:34:36 by jcsantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	file_exist(char *file, char *name)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nFile %s not exist or its no correct.\n", name);
		exit(9);
	}
	return (0);
}

int	chk_ext(char *name, char *ext)
{
	char	*test_ext;

	test_ext = &name[(ft_strlen(name) - 4)];
	if (ft_strcmp(test_ext, ext) == 0)
		return (0);
	return (1);
}

int	chk_save(char *save)
{
	if (ft_strcmp(save, "--save") == 0)
		return (0);
	return (4);
}

int	chk_args(int argc, char **argv, t_cube *s_c3d)
{
	int		cnt;

	cnt = 0;
	if (argc <= 1)
		ft_msgerror("No hay parametros", 1);
	if (argc > 3)
		ft_msgerror("Demasiados parámetros", 2);
	if (chk_ext(argv[1], ".cub") == 0)
		s_c3d->f_name = argv[1];
	else
		ft_msgerror("La extensión del archivo no es correcta", 3);
	if (argv[2])
	{
		if (chk_save(argv[2]) == 0)
			s_c3d->save_parm = 1;
		else
			ft_msgerror("El argumento no es correcto.", 4);
	}
	return (0);
}
