/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_capture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:24:18 by juasanto          #+#    #+#             */
/*   Updated: 2021/05/24 11:26:21 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	header1(int fd, t_cube *cub);
void	header2(int fd, t_cube *cub);

static int	my_get_img_pixel(t_cube *cub, int x, int y)
{
	int		color;
	char	*dst;

	dst = cub->mlx.addr + (y * cub->mlx.line_length
			+ x * cub->mlx.bits_per_pixel / 8);
	color = *(unsigned int *)dst;
	return (color);
}

void	header1(int fd, t_cube *cub)
{
	int	ret;
	int	value;

	ret = write(fd, "BM", sizeof(char) * 2);
	value = ((cub->resX * cub->resY) * 4) + 14 + 40 ;
	ret = write(fd, &value, 4);
	value = 0;
	ret = write(fd, &value, 1);
	ret = write(fd, &value, 1);
	ret = write(fd, &value, 2);
	value = 54;
	ret = write(fd, &value, 4);
	if (ret < 0)
		ft_msgerror("Save file error.", 6);
	header2(fd, cub);
}

void	header2(int fd, t_cube *cub)
{
	int	ret;
	int	value;

	value = 40;
	ret = write(fd, &value, 4);
	value = cub->resX;
	ret = write(fd, &value, 4);
	value = cub->resY;
	ret = write(fd, &value, 4);
	value = 1;
	ret = write(fd, &value, 2);
	value = 32;
	ret = write(fd, &value, 2);
	value = 0;
	ret = write(fd, &value, 4);
	ret = write(fd, &value, 4);
	ret = write(fd, &value, 4);
	ret = write(fd, &value, 4);
	ret = write(fd, &value, 4);
	ret = write(fd, &value, 4);
	if (ret < 0)
		ft_msgerror("Save file error.", 6);
}

void	main_bmp(t_cube *cub)
{
	int	fd;
	int	value;
	int	x;
	int	y;

	system("pkill afplay");
	fd = open("screen_shot.bmp", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	header1(fd, cub);
	y = cub->resY - 1;
	while (y > -1)
	{
		x = 0;
		while (x < cub->resX)
		{
			value = my_get_img_pixel(cub, x, y);
			if (write(fd, &value, 4) < 0)
				ft_msgerror("Save file error.", 6);
			x++;
		}
		y--;
	}
	close(fd);
	free_all(cub);
	system("leaks cub3D");
	exit(6);
}
