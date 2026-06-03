/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:16:17 by bbousaad          #+#    #+#             */
/*   Updated: 2025/02/20 16:59:29 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_view(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'N')
		data->player_angle = 4.71;
	if (data->map[i][j] == 'E')
		data->player_angle = 0;
	if (data->map[i][j] == 'S')
		data->player_angle = 1.57;
	if (data->map[i][j] == 'W')
		data->player_angle = 3.14;
}

void	init_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'E' ||
				data->map[i][j] == 'W' || data->map[i][j] == 'S')
			{
				data->player_x = j + 0.5;
				data->player_y = i + 0.5;
				handle_view(data, i, j);
				data->map[i][j] = '0';
				i = data->player_y;
				j = data->player_x;
				return ;
			}
			j++;
		}
		i++;
	}
}
