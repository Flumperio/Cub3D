/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:49:08 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/04 17:32:37 by jcsantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	rmv_space(t_cube *s_c3d)
{
	while (ft_isblank(s_c3d->line[s_c3d->cnt_i]) == 1)
		s_c3d->cnt_i++;
	return ;
}

int	atoi_b(t_cube *s_c3d)
{
	int		result;

	result = 0;
	while (ft_isdigit(s_c3d->line[s_c3d->cnt_i]))
	{
		result = result * 10 + s_c3d->line[s_c3d->cnt_i] - '0';
		s_c3d->cnt_i++;
	}
	return (result);
}

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
