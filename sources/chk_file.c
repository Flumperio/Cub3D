/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 12:36:59 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/01 17:16:44 by jcsantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	r_parm(t_cube *s_c3d)
{
	s_c3d->tex[R].exis = 1;
	s_c3d->cnt_i++;
	rmv_space(s_c3d);
	if (s_c3d->line[s_c3d->cnt_i] >= '0' && s_c3d->line[s_c3d->cnt_i] <= '9')
		s_c3d->p_rx = atoi_b(s_c3d);
	else
		ft_msgerror("No valid Resolution X.", 7);
	rmv_space(s_c3d);
	if (s_c3d->line[s_c3d->cnt_i] >= '0' && s_c3d->line[s_c3d->cnt_i] <= '9')
		s_c3d->p_ry = atoi_b(s_c3d);
	else
		ft_msgerror("No valid Resolution Y.", 7);
	return ;
}

void	f_parm(t_cube *s_c3d)
{
	s_c3d->p_f = 1;
	s_c3d->cnt_i++;
	// rmv_space(line, s_c3d);
	// if (line[s_c3d->cnt_i] >= '0' && line[s_c3d->cnt_i] <= '9')
	// 	s_c3d->p_fr = atoi_b(line, s_c3d);
	// else
	// 	ft_msgerror("Floor R parm is not valid.", 7);
	// rmv_space(line, s_c3d);
	// if (line[s_c3d->cnt_i] >= '0' && line[s_c3d->cnt_i] <= '9')
	// 	s_c3d->p_fg = atoi_b(line, s_c3d);
	// else
	// 	ft_msgerror("Floor G parm is not valid.", 7);
	// rmv_space(line, s_c3d);
	// if (line[s_c3d->cnt_i] >= '0' && line[s_c3d->cnt_i] <= '9')
	// 	s_c3d->p_fb = atoi_b(line, s_c3d);
	// else
	// 	ft_msgerror("Floor B parm is not valid.", 7);
	s_c3d->cnt_i = ft_strlen(s_c3d->line);
	return ;
}

void	c_parm(t_cube *s_c3d)
{
	char	**temp;
	int		cnt;

	cnt = 0;
	s_c3d->p_c = 1;
	s_c3d->cnt_i++;
	// rmv_space(&line[s_c3d->cnt_i], s_c3d);
	// temp = ft_split(&line[s_c3d->cnt_i], ',');
	// while (temp[cnt] != 0)
	// {
	// 	rmv_space(temp[cnt], s_c3d);
	// 	printf("split: %s\n", temp[cnt]);
	// 	cnt++;
	// }
	s_c3d->cnt_i = ft_strlen(s_c3d->line);
	return ;
}

void	chk_map(t_cube *s_c3d)
{
	s_c3d->map_lines++;
	s_c3d->cnt_i = ft_strlen(s_c3d->line);
	return ;
}



// char	*to_name(int index)
// {
// 	static char *name[4] = {"NO", "SO", "WE", "EA"};
// 	return (name[index]);
// }

int	check_nsoe(int index, t_cube *s_c3d)
{
	return (ft_strncmp(&s_c3d->line[s_c3d->cnt_i],
			s_c3d->tex[index].name,
			ft_strlen(s_c3d->tex[index].name)) == 0 &&
			s_c3d->tex[index].exis == 0);
}

int		chk_parms(t_cube *s_c3d)
{
	int		resto;
	int		cnt;
	char	*name;

	resto = 1;
	cnt = 0;
	name = NULL;
	s_c3d->cnt_i = 0;
	rmv_space(s_c3d);
	while (s_c3d->line[s_c3d->cnt_i] != '\0')
	{
		resto -= ft_isspace(s_c3d->line[s_c3d->cnt_i + 1]);
		printf ("Resto: %i\n", resto);
		name = ft_substr(&s_c3d->line[s_c3d->cnt_i], 0, resto + 1);
		printf("Name: %s\n", name);
		while (s_c3d->tex[cnt].name != 0)
		{
			if(ft_strncmp(name, s_c3d->tex[cnt].name, ft_strlen(name) + 1) == 0)
			{
				if (s_c3d->tex[cnt].exis == 1)
				{
				ft_printf("File option '%s' duplicated.\n", s_c3d->tex[cnt].name);
				exit(6);
				}
				else
				{
					s_c3d->tex[cnt].exis = 1;
					printf("llamada a la funcion: %s\n", s_c3d->tex[cnt].name);
					return(1);
				}
			}
		cnt++;
		}
	s_c3d->cnt_i++;
	}
	return (0);
}

int		chk_file(t_cube *s_c3d)
{
	int		fd1;
	int		gnl;

	gnl = 1;
	fd1 = open(s_c3d->f_name, O_RDONLY);
	if (fd1 < 0)
		ft_msgerror("No existe el ficheo", 5);
	while (get_next_line(fd1, &s_c3d->line) == 1)
	{
		gnl++;
		printf("gnl: %s\n", s_c3d->line);
		chk_parms(s_c3d);
		free(s_c3d->line);
	}
	chk_parms(s_c3d);
	free(s_c3d->line);
	return (0);
}

// int		chk_parms(t_cube *s_c3d)
// {
// 	s_c3d->cnt_i = 0;
// 	rmv_space(s_c3d);
// 	while (s_c3d->line[s_c3d->cnt_i] != '\0')
// 	{
// 		if (check_nsoe(R, s_c3d) == 1)
// 			r_parm(s_c3d);
// 		else if (check_nsoe(NO, s_c3d) == 1)
// 			texture_all(NO, s_c3d);
// 		else if (check_nsoe(SO, s_c3d) == 1)
// 			texture_all(SO, s_c3d);
// 		else if (check_nsoe(WE, s_c3d) == 1)
// 			texture_all(WE, s_c3d);
// 		else if (check_nsoe(EA, s_c3d) == 1)
// 			texture_all(EA, s_c3d);
// 		else if (check_nsoe(S, s_c3d) == 1)
// 			texture_all(S, s_c3d);
// 		else if (check_nsoe(F, s_c3d) == 1)
// 			f_parm(s_c3d);
// 		else if (check_nsoe(C, s_c3d) == 1)
// 			c_parm(s_c3d);
// 		else if (s_c3d->line[s_c3d->cnt_i] == '1' ||
// 				s_c3d->line[s_c3d->cnt_i] == '0')
// 			chk_map(s_c3d);
// 		else
// 			ft_msgerror("File .cub error.", 6);
// 	}
// 	return (0);
// }
