/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:49:35 by aldalmas          #+#    #+#             */
/*   Updated: 2025/02/24 18:47:20 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	contain_onlydigits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_color_format(char **colors)
{
	int	x;
	int	y;

	y = 0;
	while (colors[y])
	{
		if (!handle_int_limit(colors[y]))
			return (0);
		x = 0;
		while (colors[y][x])
		{
			if (colors[y][x] == ' ')
				return (0);
			x++;
		}
		if (!contain_onlydigits(colors[y]))
			return (0);
		if (ft_atoi(colors[y]) < 0 || ft_atoi(colors[y]) > 255)
			return (0);
		y++;
	}
	return (1);
}

int	check_comma(char *color)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (color[i])
	{
		if (!check_color_chars(color[i]))
			return (0);
		if (color[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		return (0);
	return (1);
}

char	**reformate_color(char **temp)
{
	int		y;
	char	**new_temp;

	y = 0;
	new_temp = malloc(sizeof(char *) * (len_doubletab(temp) + 1));
	while (temp[y])
	{
		new_temp[y] = ft_strtrim(temp[y], " \n");
		free(temp[y]);
		if (y == 2 && ft_strlen(new_temp[y]) == 0)
		{
			if (new_temp[0])
				free (new_temp[0]);
			if (new_temp[1])
				free (new_temp[1]);
			if (new_temp[2])
				free (new_temp[2]);
			y = 0;
			break ;
		}
		y++;
	}
	new_temp[y] = NULL;
	free(temp);
	return (new_temp);
}

char	**is_color_ok(char *color)
{
	int		i;
	char	**formated_color;

	i = 1;
	formated_color = NULL;
	if (color && color + i && check_comma(color + i))
	{
		formated_color = ft_split(color + i, ',');
		if (len_doubletab(formated_color) == 3 && !is_empty(formated_color))
		{
			formated_color = reformate_color(formated_color);
			if (formated_color[0] != NULL && check_color_format(formated_color))
			{
				free(color);
				return (formated_color);
			}
		}
	}
	if (formated_color != NULL)
		free_doubletab(formated_color);
	free(color);
	ft_error("Invalid color format");
	return (NULL);
}
