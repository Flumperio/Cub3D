/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 12:36:59 by juasanto          #+#    #+#             */
/*   Updated: 2021/02/25 17:55:17 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"



void	r_parm(char *line, t_cube *s_c3d)
{
	s_c3d->p_r = 1;
	s_c3d->cnt_i++;
	rmv_space(line, s_c3d);
	if (line[s_c3d->cnt_i] > '0' && line[s_c3d->cnt_i] < '9')
		s_c3d->p_rx = atoi_b(line, s_c3d);
	else
		ft_msgerror("Resoluciones no validas.", 7);
	rmv_space(line, s_c3d);
	if (line[s_c3d->cnt_i] > '0' && line[s_c3d->cnt_i] < '9')
		s_c3d->p_ry = atoi_b(line, s_c3d);
	else
		ft_msgerror("Resoluciones no validas.", 7);
	return ;
}

void	texture_parm(char *line, t_cube *s_c3d, char *path)
{
	s_c3d->cnt_i++;
	s_c3d->p_s = 1;
	s_c3d->cnt_i = ft_strlen(line);
	return ;
}

void	f_parm(char *line, t_cube *s_c3d)
{
	s_c3d->p_f = 1;
	s_c3d->cnt_i++;
	s_c3d->cnt_i = ft_strlen(line);
	return ;
}

void	c_parm(char *line, t_cube *s_c3d)
{
	s_c3d->p_c = 1;
	s_c3d->cnt_i++;
	s_c3d->cnt_i = ft_strlen(line);
	return ;
}

void	chk_map(char *line, t_cube *s_c3d)
{
	s_c3d->map_lines++;
	s_c3d->cnt_i = ft_strlen(line);
	return ;
}

int		chk_parms(char *line, t_cube *s_c3d)
{
	s_c3d->cnt_i = 0;
	rmv_space(line, s_c3d);
	while (line[s_c3d->cnt_i] != '\0')
	{
		if (line[s_c3d->cnt_i] == 'R' && (ft_isblank(line[s_c3d->cnt_i + 1])) &&
				s_c3d->p_r == 0)
			r_parm(line, s_c3d);
		else if (line[s_c3d->cnt_i] == 'N' && line[s_c3d->cnt_i + 1] == 'O' &&
		(ft_isblank(line[s_c3d->cnt_i + 2])) && s_c3d->p_no == 0)
			texture_no(line, s_c3d);
		else if (line[s_c3d->cnt_i] == 'S' && line[s_c3d->cnt_i + 1] == 'O' &&
		(ft_isblank(line[s_c3d->cnt_i + 2])) && s_c3d->p_so == 0)
			texture_so(line, s_c3d);
		else if (line[s_c3d->cnt_i] == 'W' && line[s_c3d->cnt_i + 1] == 'E' &&
		(ft_isblank(line[s_c3d->cnt_i + 2])) && s_c3d->p_we == 0)
			texture_we(line, s_c3d);
		else if (line[s_c3d->cnt_i] == 'E' && line[s_c3d->cnt_i + 1] == 'A' &&
		(ft_isblank(line[s_c3d->cnt_i + 2])) && s_c3d->p_ea == 0)
			texture_ea(line, s_c3d);
		else if (line[s_c3d->cnt_i] == 'S' &&
				(ft_isblank(line[s_c3d->cnt_i + 1])) && s_c3d->p_s == 0)
			texture_parm(line, s_c3d, "P");
		else if (line[s_c3d->cnt_i] == 'F'
				&& (ft_isblank(line[s_c3d->cnt_i + 1])) && s_c3d->p_f == 0)
			f_parm(line, s_c3d);
		else if (line[s_c3d->cnt_i] == 'C'
				&& (ft_isblank(line[s_c3d->cnt_i + 1])) && s_c3d->p_c == 0)
			c_parm(line, s_c3d);
		else if (line[s_c3d->cnt_i] == '1' || line[s_c3d->cnt_i] == '0')
			chk_map(line, s_c3d);
		else
			ft_msgerror("Fichero .cub errorneo.", 6);
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
	free(line);
	return (0);
}
