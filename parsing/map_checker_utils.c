/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:42:24 by aldalmas          #+#    #+#             */
/*   Updated: 2025/01/14 15:45:53 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	char_check_orientation(char c)
{
	if (c == 'N')
		return (1);
	if (c == 'S')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'W')
		return (1);
	return (0);
}

int	is_closed(t_map *m, int y, int i)
{
	if (m->map[y][i] == '0' || char_check_orientation(m->map[y][i]))
	{
		if (m->map[y][i - 1] == ' '
			|| m->map[y][i - 1] == '\0' || !m->map[y][i - 1])
			return (0);
		if (m->map[y][i + 1] == ' '
			|| m->map[y][i + 1] == '\0' || !m->map[y][i + 1])
			return (0);
		if (m->map[y + 1][i] == ' '
			|| m->map[y + 1][i] == '\0' || !m->map[y + 1][i])
			return (0);
		if (m->map[y - 1][i] == ' '
			|| m->map[y - 1][i] == '\0' || !m->map[y - 1][i])
			return (0);
	}
	return (1);
}
