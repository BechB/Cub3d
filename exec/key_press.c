/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:28:57 by bbousaad          #+#    #+#             */
/*   Updated: 2025/02/24 17:08:14 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_data *data, t_img *img)
{
	int		i;
	int		j;

	(void) img;
	i = 0;
	j = 0;
	if (keycode == ESC)
	{
		printf(RED"Rage quit!?\n"RESET);
		if (data->f_color)
			free_doubletab(data->f_color);
		if (data->c_color)
			free_doubletab(data->c_color);
		exit (0);
	}
	key_press2(keycode, data);
	key_press3(keycode, data);
	render(data, img);
	put_mini(data, i, j);
	return (0);
}

int	key_press2(int keycode, t_data *data)
{
	if (keycode == LEFT)
		data->player_angle -= 0.1;
	if (keycode == RIGHT)
		data->player_angle += 0.1;
	if (keycode == UP)
	{
		data->new_x = data->player_x + cos(data->player_angle) * 0.1;
		data->new_y = data->player_y + sin(data->player_angle) * 0.1;
		if (can_move(data))
		{
			data->player_x = data->new_x;
			data->player_y = data->new_y;
		}
	}
	if (keycode == DOWN)
	{
		data->new_x = data->player_x - cos(data->player_angle) * 0.1;
		data->new_y = data->player_y - sin(data->player_angle) * 0.1;
		if (can_move(data))
		{
			data->player_x = data->new_x;
			data->player_y = data->new_y;
		}
	}
	return (0);
}

int	key_press3(int keycode, t_data *data)
{
	if (keycode == A)
		data->player_angle -= 0.1;
	if (keycode == D)
		data->player_angle += 0.1;
	if (keycode == W)
	{
		data->new_x = data->player_x + cos(data->player_angle) * 0.1;
		data->new_y = data->player_y + sin(data->player_angle) * 0.1;
		if (can_move(data))
		{
			data->player_x = data->new_x;
			data->player_y = data->new_y;
		}
	}
	if (keycode == S)
	{
		data->new_x = data->player_x - cos(data->player_angle) * 0.1;
		data->new_y = data->player_y - sin(data->player_angle) * 0.1;
		if (can_move(data))
		{
			data->player_x = data->new_x;
			data->player_y = data->new_y;
		}
	}
	return (0);
}

int	destroy(t_data *data)
{
	free_doubletab(data->f_color);
	free_doubletab(data->c_color);
	mlx_destroy_window(data->mlx, data->win);
	ft_exit(data, RED"RAGE QUIT !?\n"RESET, 0);
	return (0);
}
