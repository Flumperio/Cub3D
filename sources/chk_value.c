/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:30:26 by jcsantos          #+#    #+#             */
/*   Updated: 2021/03/09 14:11:02 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	chk_value(char *number, int min_value, int max_value)
{
	int		value;
	char	**chk;
	int		cnt;
	int		cnt1;

	cnt = 0;
	cnt1 = 0;
	chk = ft_split(number, ' ');
	while (chk[cnt] != NULL)
		cnt++;
	value = ft_atoi(number);
	if (value < min_value || value > max_value || cnt != 1)
		ft_msgerror("Error in the value of parameters.", 6);
	printf("chk_value: %p\n", chk);
	while (chk[cnt1] != NULL)
	{
		free(chk[cnt1]);
		cnt1++;
	}
	free(chk);
	return (value);
}

void	chk_r_value(t_cube *s_c3d)
{
	int	cnt;

	cnt = 1;
	while (s_c3d->line[cnt] != '\0')
	{
		if (ft_isblank(s_c3d->line[cnt]) != 1 && \
			ft_isdigit(s_c3d->line[cnt]) != 1)
			ft_msgerror("Value no valid for R parameter.", 7);
		cnt++;
	}
}

void	chk_fc_value(t_cube *s_c3d)
{
	int	cnt;

	cnt = 1;
	while (s_c3d->line[cnt] != '\0')
	{
		if (ft_isblank(s_c3d->line[cnt]) != 1 && \
			ft_isdigit(s_c3d->line[cnt]) != 1 && \
			s_c3d->line[cnt] != ',')
			ft_msgerror("Value no valid for F/C parameter.", 7);
		cnt++;
	}
}
