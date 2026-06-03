/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:49:24 by bbousaad          #+#    #+#             */
/*   Updated: 2025/06/15 13:33:00 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	open_win(t_data *data, t_img *img, t_parse *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "CUB3D");
	map_size(data);
	init_player(data);
	init_img(data, p);
	convert_color(data);
	data->last_mouse_x = 0;
	data->first_move = 1;
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 6, (1L << 6), mouse, data);
	render(data, img);
	mlx_hook(data->win, 17, 0, destroy, data);
	put_mini(data, i, j);
	mlx_loop(data->mlx);
}

int	mouse(int x, int y, t_data *data, t_img *img)
{
	int	delta_x;

	(void) y;
	if (data->first_move)
	{
		data->last_mouse_x = 0;
		data->first_move = 0;
		return (0);
	}
	delta_x = x - data->last_mouse_x;
	if (delta_x == 0)
		return (0);
	data->player_angle += delta_x * TURN;
	if (data->player_angle < 0)
		data->player_angle += 2 * PI;
	if (data->player_angle >= 2 * PI)
		data->player_angle -= 2 * PI;
	data->last_mouse_x = x;
	render(data, img);
	return (0);
}
