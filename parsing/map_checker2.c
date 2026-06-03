/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:43:15 by aldalmas          #+#    #+#             */
/*   Updated: 2025/01/14 15:43:17 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	is_missing_player(t_map *m, t_parse *p)
{
	if (p->orient_north == 0 && p->orient_south == 0 && p->orient_east == 0
		&& p->orient_west == 0)
	{
		special_free2(m, p);
		ft_error("Player is missing (Need 'N', 'S', 'E' or 'W' in the map)");
	}
}

void	orient_checker2(t_map *m, t_parse *p)
{
	if (p->orient_north > 1 || p->orient_south > 1
		|| p->orient_east > 1 || p->orient_west > 1)
	{
		special_free2(m, p);
		ft_error("Too much player found, need only one");
	}
	if (p->orient_north == 1)
	{
		if (p->orient_south > 0 || p->orient_east > 0 || p->orient_west > 0)
		{
			special_free2(m, p);
			ft_error("Too much player found, need only one");
		}
	}
	if (p->orient_south == 1)
	{
		if (p->orient_north > 0 || p->orient_east > 0 || p->orient_west > 0)
		{
			special_free2(m, p);
			ft_error("Too much player found, need only one");
		}
	}
	orient_check3(m, p);
}

void	orient_check3(t_map *m, t_parse *p)
{
	if (p->orient_east == 1)
	{
		if (p->orient_north > 0 || p->orient_south > 0 || p->orient_west > 0)
		{
			special_free2(m, p);
			ft_error("Too much player found, need only one");
		}
	}
	if (p->orient_west == 1)
	{
		if (p->orient_north > 0 || p->orient_east > 0 || p->orient_south > 0)
		{
			special_free2(m, p);
			ft_error("Too much player found, need only one");
		}
	}
}

void	orient_checker(t_map *m, t_parse *p, int orient)
{
	if (orient == 'N')
		p->orient_north++;
	if (orient == 'S')
		p->orient_south++;
	if (orient == 'E')
		p->orient_east++;
	if (orient == 'W')
		p->orient_west++;
	orient_checker2(m, p);
}
