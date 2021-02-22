/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 12:36:59 by juasanto          #+#    #+#             */
/*   Updated: 2021/02/22 13:45:43 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		chk_file(t_cube *s_c3d)
{
	int		fd1;
	int		gnl;
	char	*line;

	line = NULL;
	gnl = 1;
	fd1 = open(s_c3d->f_name, O_RDONLY);
	if (fd1 < 0)
		ft_msgerror("No existe el ficheo", 5);
	while (gnl == 1)
	{
		gnl = get_next_line(fd1, &line);
		printf("gnl: %s\n", line);
	}
	return (0);
}
