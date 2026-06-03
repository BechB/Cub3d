/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:09:18 by bbousaad          #+#    #+#             */
/*   Updated: 2025/02/20 19:09:29 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_ray(t_data *data)
{
	if (data->ray_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->player_x - data->map_x) * data->dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x + 1.0 - data->player_x) * data->dist_x;
	}
	if (data->ray_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->player_y - data->map_y) * data->dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y + 1.0 - data->player_y) * data->dist_y;
	}
}

void	init_data_render(t_data *data, int x)
{
	data->ray_angle = data->player_angle - (FOV / 2) * (PI / 180)
		+ (x * (FOV / WIN_WIDTH) * (PI / 180));
	data->ray_x = cos(data->ray_angle);
	data->ray_y = sin(data->ray_angle);
	data->map_x = (int)data->player_x;
	data->map_y = (int)data->player_y;
	data->dist_x = fabs(1 / data->ray_x);
	data->dist_y = fabs(1 / data->ray_y);
	data->step_x = 0.0;
	data->step_y = 0.0;
	data->side_dist_x = 0.0;
	data->hit = 0;
	data->side = 0;
	set_ray(data);
}

void	texture_choice(t_data *data)
{
	if (data->side_dist_x < data->side_dist_y)
	{
		data->side_dist_x += data->dist_x;
		data->map_x += data->step_x;
		if (data->ray_x < 0)
			data->side = 3;
		else
			data->side = 2;
	}
	else
	{
		data->side_dist_y += data->dist_y;
		data->map_y += data->step_y;
		if (data->ray_y > 0)
			data->side = 0;
		else
			data->side = 1;
	}
}

void	compare_ray(t_data *data)
{
	while (!data->hit)
	{
		texture_choice(data);
		if (data->map_x >= 0 && data->map_x < data->map_width
			&& data->map_y >= 0 && data->map_y < data->map_height)
		{
			if (data->map[data->map_y][data->map_x] == '1')
				data->hit = 1;
		}
		else
			data->hit = 1;
	}
	if (data->side == 2 || data->side == 3)
		data->dist = (data->map_x - data->player_x + (1 - data->step_x) / 2)
			/ data->ray_x;
	else
		data->dist = (data->map_y - data->player_y + (1 - data->step_y) / 2)
			/ data->ray_y;
	data->hit_x = data->player_x + data->ray_x * data->dist;
	data->hit_y = data->player_y + data->ray_y * data->dist;
}

int	can_move(t_data *data)
{
	double	newnewx;
	double	newnewy;
	int		newx;
	int		newy;

	newx = 0;
	newy = 0;
	newnewx = data->new_x + cos(data->player_angle) * 0.1;
	newnewy = data->new_y + sin(data->player_angle) * 0.1;
	data->map_x = (int)data->new_x;
	data->map_y = (int)data->new_y;
	newx = (int)newnewx;
	newy = (int)newnewy;
	if (data->map[newy][data->map_x] == '1'
		|| data->map[data->map_y][newx] == '1')
		return (0);
	if ((data->map_x >= 0 && data->map_x < data->map_width && data->map_y >= 0
			&& data->map_y < data->map_height))
		return (data->map[data->map_y][data->map_x] == '0');
	return (0);
}
