/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_capture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:24:18 by juasanto          #+#    #+#             */
/*   Updated: 2021/05/18 16:21:14 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	main_bmp(t_cube *cub)
{
	int	fd;
	int	ret;
	int	value;
	int	tmp;


	printf("Take ScreenShot\n");
	fd = open("screen_shot.bmp", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	printf("FD: %i\n", fd);
	ret = write(fd, "BM", sizeof(char) * 2);
	value = ((cub->resX * cub->resY) * 4) + 14 + 40 ;
	printf ("v: %i\n", value);/* tamaño del fichero * 3 uso 24bpp */
	ret = write(fd, &value, sizeof(unsigned int));
	value = 0;
	ret = write(fd, &value, sizeof(unsigned short int));
	ret = write(fd, &value, sizeof(unsigned short int));
	value = 54;
	ret = write(fd, &value, 4);
	value = 40;
	ret = write(fd, &value, 4);
	value = cub->resX;
	ret = write(fd, &value, 4);
	value = cub->resY;
	ret = write(fd, &value, 4);
	value = 1;
	ret = write(fd, &value, 2);
	value = 24;
	ret = write(fd, &value, 2);
	value = 0;
	ret = write(fd, &value, 4);
	ret = write(fd, &value, 4);
	ret = write(fd, &value, 4);
	ret = write(fd, &value, 4);
	ret = write(fd, &value, 4);
	ret = write(fd, &value, 4);
	tmp = ((cub->resX * cub->resY) * 3);
	while (tmp < 0)
	{
		ret = write (fd, &value, 3);
		tmp--;
	}

	close(fd);
	free_all(cub);
	exit(0);
}
