/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_args_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:46:04 by juasanto          #+#    #+#             */
/*   Updated: 2021/05/25 11:26:46 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d_bonus.h"

int	file_exist(char *file, char *name)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nFile %s not exist or its no correct.\n", name);
		exit(9);
	}
	close(fd);
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

int	chk_args(int argc, char **argv, t_cube *cub)
{
	int		cnt;

	cnt = 0;
	if (argc <= 1)
		ft_msgerror("No Parameters.", 1);
	if (argc > 3)
		ft_msgerror("Too Many Parameters.", 2);
	if (chk_ext(argv[1], ".cub") == 0)
		cub->f_name = argv[1];
	else
		ft_msgerror("Extension is not correct.", 3);
	if (argv[2])
	{
		if (chk_save(argv[2]) == 0)
			cub->save_parm = 1;
		else
			ft_msgerror("Argument is not correct.", 4);
	}
	return (0);
}