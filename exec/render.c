/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:34:04 by bbousaad          #+#    #+#             */
/*   Updated: 2025/02/19 18:37:55 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_limits(t_data *data)
{
	float	distance_to_wall;
	float	perpendicular_distance;

	distance_to_wall = data->dist;
	perpendicular_distance = fabs(distance_to_wall
			* cos(data->ray_angle - data->player_angle));
	if (perpendicular_distance < 0.01)
		perpendicular_distance = 0.01;
	data->line_height = (int)(WIN_HEIGHT / perpendicular_distance);
	data->start = WIN_HEIGHT / 2 - data->line_height / 2;
	data->end = WIN_HEIGHT / 2 + data->line_height / 2;
	if (data->start < 0)
		data->start = 0;
	if (data->end >= WIN_HEIGHT)
		data->end = WIN_HEIGHT;
}

void	set_texture(t_data *data, t_img *img)
{
	data->texture_step = (double)img->height / data->line_height;
	data->texture_pos = 0;
	if (data->line_height > WIN_HEIGHT)
		data->texture_pos = (data->line_height - WIN_HEIGHT)
			/ 2.0 * data->texture_step;
}

void	put_pixels_lines(t_data *data, t_img *img, int x, int y)
{
	int	color;
	int	i;

	y = -1;
	set_limits(data);
	i = data->end - 1;
	while (++y < data->start)
		if (y > (data->map_height * 10) || x > (data->map_width * 10))
			mlx_pixel_put(data->mlx, data->win, x, y,
				convert_color2(data->c_red, data->c_green, data->c_blue));
	while (++i < WIN_HEIGHT)
		mlx_pixel_put(data->mlx, data->win, x, i,
			convert_color2(data->f_red, data->f_green, data->f_blue));
	set_texture(data, img);
	while (y < data->end)
	{
		img->img_y = (int)data->texture_pos & (img->height - 1);
		color = *(int *)(img->addr + (img->img_y * img->line_len + img->img_x
					* (img->bpp / 8)));
		if (color != 0 && (y > (data->map_height * 10)
				|| x > (data->map_width * 10)))
			mlx_pixel_put(data->mlx, data->win, x, y, color);
		data->texture_pos = data->texture_step + data->texture_pos;
		y++;
	}
}

void	calcul_render(t_data *data, t_img *img, int y, int x)
{
	double	wall_x;

	img = &data->img[data->side];
	if (data->side == 0 || data->side == 1)
		wall_x = fmod(data->hit_x, 1.0);
	else
		wall_x = fmod(data->hit_y, 1.0);
	if (data->side == 0)
		wall_x = 1.0 - wall_x;
	else if (data->side == 3)
		wall_x = 1.0 - wall_x;
	img->img_x = (int)(wall_x * (double)img->width) % img->width;
	put_pixels_lines(data, img, x, y);
}

void	render(t_data *data, t_img *img)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_data_render(data, x);
		compare_ray(data);
		if (!data->hit)
			continue ;
		calcul_render(data, img, 0, x);
		x++;
	}
}
