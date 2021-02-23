/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 12:36:59 by juasanto          #+#    #+#             */
/*   Updated: 2021/02/23 13:40:25 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		chk_parms(char *line, t_cube *s_c3d)
{
	int		cnt;
	char	*tmp_num;

	cnt = 0;
	tmp_num = NULL;
	while (line[cnt] != '\0')
	{
		if (line[cnt] == 'R' && (ft_isblank(line[cnt + 1])) && s_c3d->res == 0)
		{
			s_c3d->res = 1;
			cnt++;
		}

	}
	return (0);
}

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
	while (get_next_line(fd1, &line) == 1)
	{
		gnl++;
		printf("gnl: %s\n", line);
		//chk_parms(line, s_c3d);
		//free(line);
	}
	//chk_parms(line, s_c3d);
	//free(line);
	return (0);
}
