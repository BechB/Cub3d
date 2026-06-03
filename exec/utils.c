/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:04:01 by bbousaad          #+#    #+#             */
/*   Updated: 2025/02/19 16:55:47 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit(t_data *dta, char *mess, int status)
{
	printf("%s\n", mess);
	exit (status);
	(void)dta;
}

void	pos_player(t_data *dta)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dta->map[i])
	{
		j = 0;
		while (dta->map[i][j])
		{
			if (dta->map[i][j] == 'N' || dta->map[i][j] == 'E' ||
				dta->map[i][j] == 'O' || dta->map[i][j] == 'S')
			{
				dta->player_x = j + 0.5;
				dta->player_y = i + 0.5;
			}
			j++;
		}
		i++;
	}
}

void	map_size(t_data *data)
{
	int	current_width;

	data->map_height = 0;
	data->map_width = 0;
	current_width = 0;
	while (data->map[data->map_height])
	{
		current_width = ft_strlen(data->map[data->map_height]);
		if (current_width > data->map_width)
			data->map_width = current_width;
		data->map_height++;
	}
}

void	convert_color(t_data *data)
{
	data->c_red = atoi(data->c_color[0]);
	data->c_green = atoi(data->c_color[1]);
	data->c_blue = atoi(data->c_color[2]);
	data->f_red = atoi(data->f_color[0]);
	data->f_green = atoi(data->f_color[1]);
	data->f_blue = atoi(data->f_color[2]);
}

int	convert_color2(int red, int green, int blue)
{
	if (red < 0)
		red = 0;
	if (red > 255)
		red = 255;
	if (green < 0)
		green = 0;
	if (green > 255)
		green = 255;
	if (blue < 0)
		blue = 0;
	if (blue > 255)
		blue = 255;
	return ((red << 16) | (green << 8) | blue);
}
