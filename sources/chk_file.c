/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 12:36:59 by juasanto          #+#    #+#             */
/*   Updated: 2021/02/23 18:19:08 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	rmv_space(char *line, t_cube *s_c3d)
{
	while(ft_isblank(line[s_c3d->cnt_i]) == 1)
		s_c3d->cnt_i++;
	return;
}

void	r_parm(char *line, t_cube *s_c3d)
{
	s_c3d->p_r = 1;
	s_c3d->cnt_i++;
	s_c3d->cnt_i = ft_strlen(line) + 1;
	return;
}

void	texture_parm(char *line, t_cube *s_c3d, char *path)
{
	s_c3d->cnt_i++;
	if(*path == 'N')
		s_c3d->p_no = 1;
	else if(*path == 'S')
		s_c3d->p_so = 1;
	else if(*path == 'W')
		s_c3d->p_we = 1;
	else
		s_c3d->p_ea = 1;
	s_c3d->cnt_i = ft_strlen(line) + 1;
	return;
}

void	f_parm(char *line, t_cube *s_c3d)
{
	s_c3d->p_f = 1;
	s_c3d->cnt_i++;
	s_c3d->cnt_i = ft_strlen(line) + 1;
	return;
}

void	c_parm(char *line, t_cube *s_c3d)
{
	s_c3d->p_c = 1;
	s_c3d->cnt_i++;
	s_c3d->cnt_i = ft_strlen(line) + 1;
	return;
}



int		chk_parms(char *line, t_cube *s_c3d)
{
	s_c3d->cnt_i = 0;
	rmv_space(line, s_c3d);
	while (line[s_c3d->cnt_i] != '\0')
	{
		if (line[s_c3d->cnt_i] == 'R' && (ft_isblank(line[s_c3d->cnt_i + 1])) && s_c3d->p_r == 0)
			r_parm(line, s_c3d);
		else if (line[s_c3d->cnt_i] == 'N' && line[s_c3d->cnt_i + 1] == 'O' &&
		(ft_isblank(line[s_c3d->cnt_i + 2])) && s_c3d->p_no == 0)
			texture_parm(line, s_c3d, "N");
		else if (line[s_c3d->cnt_i] == 'S' && line[s_c3d->cnt_i + 1] == 'O' &&
		(ft_isblank(line[s_c3d->cnt_i + 2])) && s_c3d->p_so == 0)
			texture_parm(line, s_c3d, "S");
		else if (line[s_c3d->cnt_i] == 'W' && line[s_c3d->cnt_i + 1] == 'E' &&
		(ft_isblank(line[s_c3d->cnt_i + 2])) && s_c3d->p_we == 0)
			texture_parm(line, s_c3d, "W");
		else if (line[s_c3d->cnt_i] == 'E' && line[s_c3d->cnt_i + 1] == 'A' &&
		(ft_isblank(line[s_c3d->cnt_i + 2])) && s_c3d->p_ea == 0)
			texture_parm(line, s_c3d, "E");
		else if (line[s_c3d->cnt_i] == 'S' && (ft_isblank(line[s_c3d->cnt_i + 1])) && s_c3d->p_s == 0)
			texture_parm(line, s_c3d, "S");
		else if (line[s_c3d->cnt_i] == 'F' && (ft_isblank(line[s_c3d->cnt_i + 1])) && s_c3d->p_r == 0)
			f_parm(line, s_c3d);
		else if (line[s_c3d->cnt_i] == 'C' && (ft_isblank(line[s_c3d->cnt_i + 1])) && s_c3d->p_r == 0)
			c_parm(line, s_c3d);
		else if (line[s_c3d->cnt_i] == '1')
			c_parm(line, s_c3d);
		// else
		// 	ft_msgerror("Fichero .cub errorneo.", 6);

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
		chk_parms(line, s_c3d);
		free(line);
	}
	chk_parms(line, s_c3d);
	//free(line);
	return (0);
}
