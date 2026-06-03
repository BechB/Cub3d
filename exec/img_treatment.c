/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_treatment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:07:32 by bbousaad          #+#    #+#             */
/*   Updated: 2025/02/24 17:08:12 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_img(t_data *data, t_parse *p)
{
	load_img(data, &data->img[0], p->s_path);
	load_img(data, &data->img[1], p->n_path);
	load_img(data, &data->img[2], p->e_path);
	load_img(data, &data->img[3], p->w_path);
	free(p->n_path);
	free(p->s_path);
	free(p->e_path);
	free(p->w_path);
}

void	load_img(t_data *data, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(data->mlx, path,
			&img->width, &img->height);
	if (!img->img)
	{
		printf(RED"Error : Check images%s\n"RESET, path);
		exit(1);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len,
			&img->endian);
}
