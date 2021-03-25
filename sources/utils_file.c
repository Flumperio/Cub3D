/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:49:08 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/25 12:23:35 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	rmv_space(t_cube *cub)
{
	while (ft_isblank(cub->line[cub->cnt_i]) == 1)
		cub->cnt_i++;
	return ;
}

int	atoi_b(t_cube *cub)
{
	int		result;

	result = 0;
	while (ft_isdigit(cub->line[cub->cnt_i]))
	{
		result = result * 10 + cub->line[cub->cnt_i] - '0';
		cub->cnt_i++;
	}
	return (result);
}

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
	while (chk[cnt1] != NULL)
	{
		free(chk[cnt1]);
		cnt1++;
	}
	free(chk);
	return (value);
}

void	chk_r_value(t_cube *cub)
{
	int	cnt;

	cnt = 1;
	while (cub->line[cnt] != '\0')
	{
		if (ft_isblank(cub->line[cnt]) != 1 && \
			ft_isdigit(cub->line[cnt]) != 1)
			ft_msgerror("Value no valid for R parameter.", 7);
		cnt++;
	}
}

void	chk_fc_value(t_cube *cub)
{
	int	cnt;

	cnt = 1;
	while (cub->line[cnt] != '\0')
	{
		if (ft_isblank(cub->line[cnt]) != 1 && \
			ft_isdigit(cub->line[cnt]) != 1 && \
			cub->line[cnt] != ',')
			ft_msgerror("Value no valid for F/C parameter.", 7);
		cnt++;
	}
}
