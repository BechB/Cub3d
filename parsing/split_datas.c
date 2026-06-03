/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_datas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:51:04 by aldalmas          #+#    #+#             */
/*   Updated: 2025/02/24 20:58:01 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	len_error(t_parse *p)
{
	special_free1(p);
	ft_error("❌ Empty file");
}

void	split_datas(t_parse *p, t_map *m)
{
	int	i;
	int	j;
	int	len;

	i = 6;
	j = 0;
	len = ft_strlen_dtab(p->full_file) - 6;
	if (len < 0)
		len_error(p);
	m->map = malloc(sizeof(char *) * (len + 1));
	if (!m->map)
	{
		special_free2(m, p);
		return ;
	}
	while (len > 0 && p->full_file[i])
	{
		m->map[j] = ft_strdup(p->full_file[i]);
		i++;
		j++;
	}
	m->map[j] = NULL;
	m->map_len = j;
	free_doubletab(p->full_file);
}
