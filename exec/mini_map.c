/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:58:55 by bbousaad          #+#    #+#             */
/*   Updated: 2025/02/19 16:53:42 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_mini2(t_data *data)
{
	draw_big_pixel_floor2(data->mlx, data->win, data->player_x
		* 10, data->player_y * 10);
	draw_big_pixel_player(data->mlx, data->win, data->player_x
		* 10, data->player_y * 10);
}

void	put_mini(t_data *data, int i, int j)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (data->map[++y])
	{
		x = -1;
		i = 0;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == '1')
			{
				draw_big_pixel_wall(data->mlx, data->win, i, j);
			}
			else if (data->map[y][x] == '0')
			{
				draw_big_pixel_floor(data->mlx, data->win, i, j);
			}
			i = i + 10;
			put_mini2(data);
		}
		j = j + 10;
	}
}
