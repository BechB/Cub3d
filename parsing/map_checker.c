/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 08:25:56 by aldalmas          #+#    #+#             */
/*   Updated: 2025/02/24 20:52:59 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	char_checker(char c)
{
	if (c == '0')
		return (1);
	if (c == '1')
		return (1);
	if (c == 'N')
		return (1);
	if (c == 'S')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'W')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

int	first_checker(t_map *m, int y)
{
	int	i;

	i = 0;
	while (m->map[y][i])
	{
		if (m->map[y][i] != '1'
			&& m->map[y][i] != ' '
			&& m->map[y][i] != '\0'
			&& m->map[y][i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	body_checker(t_map *m, t_parse *p, int y)
{
	int	i;

	i = 0;
	while (m->map[y][i] == ' ')
		i++;
	if (m->map[y][i] != '1')
		return (0);
	while (m->map[y][i])
	{
		if (!char_checker(m->map[y][i]) || !is_closed(m, y, i))
			return (0);
		if (m->map[y][i] == 'N')
			orient_checker(m, p, 'N');
		if (m->map[y][i] == 'S')
			orient_checker(m, p, 'S');
		if (m->map[y][i] == 'E')
			orient_checker(m, p, 'E');
		if (m->map[y][i] == 'W')
			orient_checker(m, p, 'W');
		i++;
	}
	return (1);
}

void	check_map(t_map *m, t_parse *p, int y)
{
	int	error;

	error = 0;
	if (y == 0 || y == m->map_len - 1)
	{
		if (!first_checker(m, y))
		{
			printf("map: [%s]\n", m->map[y]);
			error = 1;
		}
	}
	else
	{
		if (body_checker(m, p, y) == 0)
			error = 2;
	}
	if (error > 0)
		special_free2(m, p);
	if (error == 1)
		ft_error("Invalid file/map format");
	else if (error == 2)
		ft_error("Invalid map format");
}

void	is_map_ok(t_map *m, t_parse *p)
{
	int	y;

	y = 0;
	while (m->map[y])
	{
		check_map(m, p, y);
		y++;
	}
	is_missing_player(m, p);
}
