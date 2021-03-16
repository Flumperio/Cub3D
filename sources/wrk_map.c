/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrk_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:07:10 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/15 19:21:14 by jcsantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

// void	dup_map(t_cube *s_c3d)
// {
// 	int	cnt;

// 	cnt = 0;
// 	while (s_c3d->line[cnt] != '\0')
// 	{
// 		if (ft_isblank(s_c3d->line[cnt]))
// 			s_c3d->line[cnt] = '0';
// 		if (s_c3d->line[cnt] == '2')
// 			s_c3d->line[cnt] = '0';
// 		if (s_c3d->line[cnt] == 'N')
// 		{
// 			s_c3d->line[cnt] = '0';

// 		}
// 		cnt++;
// 	}
// 	s_c3d->wrk_map[s_c3d->cnt_map++] = ft_strdup(s_c3d->line);
// 	s_c3d->wrk_map[s_c3d->cnt_map] = NULL;
// 	return ;

// }

void	cnvrt_map(t_cube *s_c3d)
{
	int	cnt;

	cnt = 0;
	while (s_c3d->line[cnt] != '\0')
	{
		if (ft_isblank(s_c3d->line[cnt]))
			s_c3d->line[cnt] = '0';
		cnt++;
	}
	s_c3d->wrk_map[s_c3d->cnt_map++] = ft_strdup(s_c3d->line);
	s_c3d->wrk_map[s_c3d->cnt_map] = NULL;
	return ;
}

void	strg_map(t_cube *s_c3d)
{
	int		fd1;

	fd1 = 0;
	s_c3d->strg_map = 1;
	s_c3d->wrk_map = ft_calloc(s_c3d->map_lines + 1, sizeof(char **));
	fd1 = open(s_c3d->f_name, O_RDONLY);
	while (get_next_line(fd1, &s_c3d->line) == 1)
	{
		chk_parms(s_c3d);
		ft_free(s_c3d->line);
	}
	chk_parms(s_c3d);
	ft_free(s_c3d->line);
	return ;
}
