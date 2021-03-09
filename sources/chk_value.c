/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:30:26 by jcsantos          #+#    #+#             */
/*   Updated: 2021/03/08 19:19:11 by jcsantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	chk_value(char *number, int min_value, int max_value)
{
	int		value;

	value = ft_atoi(number);
	if (value < min_value || value > max_value)
		ft_msgerror("Error in the value of parameters.", 6);
	return (value);
}

void	chk_r_value(t_cube *s_c3d)
{
	int	cnt;

	cnt = 0;
	while (s_c3d->line[++cnt] != '\0')
	{
		if (ft_isblank(s_c3d->line[cnt]) != 0 && \
			ft_isdigit(s_c3d->line[cnt]) != 0)
			ft_msgerror("Value no valid for R parameter.", 7);
	}
}

void	chk_fc_value(t_cube *s_c3d)
{
	int	cnt;

	cnt = 0;
	while (s_c3d->line[++cnt] != '\0')
	{
		if (!(ft_isblank(s_c3d->line[cnt]) == 0 || \
			ft_isdigit(s_c3d->line[cnt]) == 0 || \
			s_c3d->line[cnt] == ','))
			ft_msgerror("Value no valid for F/C parameter.", 7);
	}
}
