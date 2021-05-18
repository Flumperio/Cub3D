/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 12:36:59 by juasanto          #+#    #+#             */
/*   Updated: 2021/05/18 13:25:05 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	fill_options(t_cube *cub)
{
	char	*name;

	cub->tmp = 0;
	name = ft_substr(&cub->line[cub->cnt_i], 0,
			!ft_isspace(cub->line[cub->cnt_i + 1]) + 1);
	while (cub->tex[cub->tmp].name != 0)
	{
		if (ft_strncmp(name, cub->tex[cub->tmp].name, \
				ft_strlen(cub->tex[cub->tmp].name)) == 0)
		{
			if (cub->tex[cub->tmp].exis == 1 && cub->strg_map == 0)
				ft_msgerror("Option Duplicated.", 6);
			else
			{
				cub->tex[cub->tmp].exis = 1;
				cub->tex[cub->tmp].func(cub);
				free(name);
				return (1);
			}
		}
		cub->tmp++;
	}
	free(name);
	return (0);
}

int	chk_parms(t_cube *cub)
{
	cub->tmp = 0;
	cub->cnt_i = 0;
	rmv_space(cub);
	while (cub->line[cub->cnt_i] != '\0')
	{
		if (fill_options(cub) == 1)
			return (1);
		else
			ft_msgerror("Invalid parameters in file.", 6);
		cub->cnt_i++;
	}
	return (0);
}

int	chk_file(t_cube *cub)
{
	int		fd1;

	fd1 = open(cub->f_name, O_RDONLY);
	if (fd1 < 0)
		ft_msgerror("File not exist", 5);
	while (get_next_line(fd1, &cub->line) == 1)
	{
		chk_parms(cub);
		free(cub->line);
	}
	chk_parms(cub);
	free(cub->line);
	close(fd1);
	return (0);
}
