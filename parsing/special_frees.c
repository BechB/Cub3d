/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_frees.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:07:05 by aldalmas          #+#    #+#             */
/*   Updated: 2025/01/14 15:25:45 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_doubletab(char **tab)
{
	int	y;

	y = 0;
	while (tab && tab[y])
	{
		free (tab[y]);
		y++;
	}
	free (tab);
}

void	special_free1(t_parse *p)
{
	if (!p)
		return ;
	if (p->n_path != NULL)
		free (p->n_path);
	if (p->s_path != NULL)
		free (p->s_path);
	if (p->e_path != NULL)
		free (p->e_path);
	if (p->w_path != NULL)
		free (p->w_path);
	if (p->f_color != NULL)
		free (p->f_color);
	if (p->c_color != NULL)
		free (p->c_color);
}

void	special_free2(t_map *m, t_parse *p)
{
	if (m && m->map)
		free_doubletab(m->map);
	special_free1(p);
}
