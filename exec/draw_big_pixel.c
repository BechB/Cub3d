/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_big_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:15:49 by bbousaad          #+#    #+#             */
/*   Updated: 2025/02/19 16:56:15 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_big_pixel_wall(void *mlx_ptr, void *win_ptr, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x + i, y + j, PURPLE2);
			j++;
		}
		i++;
	}
}

void	draw_big_pixel_floor(void *mlx_ptr, void *win_ptr, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x + i, y + j, GREY2);
			j++;
		}
		i++;
	}
}

void	draw_big_pixel_floor2(void *mlx_ptr, void *win_ptr, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x + i, y + j, GREY2);
			j++;
		}
		i++;
	}
}

void	draw_big_pixel_player(void *mlx_ptr, void *win_ptr, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x + i, y + j, RED2);
			j++;
		}
		i++;
	}
}
