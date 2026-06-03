/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_checker_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:29:36 by aldalmas          #+#    #+#             */
/*   Updated: 2025/02/24 17:52:18 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_color_chars(char c)
{
	if (ft_isdigit(c))
		return (1);
	if (c == ',')
		return (1);
	if (c == ' ')
		return (1);
	if (c == '\n')
		return (1);
	return (0);
}

int	is_empty(char **formated_color)
{
	int	y;
	int	x;
	int	not_space;

	y = 0;
	while (formated_color[y])
	{
		x = 0;
		not_space = 0;
		while (formated_color[y][x])
		{
			if (formated_color[y][x] != ' ')
				not_space = 1;
			x++;
		}
		if (not_space == 0)
			return (1);
		y++;
	}
	return (0);
}
