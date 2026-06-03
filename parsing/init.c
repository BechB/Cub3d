/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:38:23 by aldalmas          #+#    #+#             */
/*   Updated: 2025/01/25 17:15:47 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct(t_parse *p, t_map *m)
{
	p->temp_file = NULL;
	p->n_path = NULL;
	p->s_path = NULL;
	p->e_path = NULL;
	p->w_path = NULL;
	p->f_color = NULL;
	p->c_color = NULL;
	p->map_found = 0;
	p->n_infos_found = 0;
	p->s_infos_found = 0;
	p->w_infos_found = 0;
	p->e_infos_found = 0;
	p->f_infos_found = 0;
	p->c_infos_found = 0;
	p->orient_north = 0;
	p->orient_south = 0;
	p->orient_east = 0;
	p->orient_west = 0;
	p->line_nb = 0;
	m->map_len = 0;
}
