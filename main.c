/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:56:51 by aldalmas          #+#    #+#             */
/*   Updated: 2025/02/24 17:08:43 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_parse	p;
	t_map	m;
	t_data	*dta;
	t_img	*img;

	(void) ac;
	dta = malloc(sizeof(t_data));
	img = malloc(sizeof(t_img));
	parsing(&p, &m, ac, av);
	copy_map(dta, &m);
	dta->f_color = NULL;
	dta->c_color = NULL;
	dta->f_color = transfer_colors(p.formated_color_f);
	dta->c_color = transfer_colors(p.formated_color_c);
	pos_player(dta);
	open_win(dta, img, &p);
	return (0);
}

void	copy_map(t_data *data, t_map *m)
{
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (m->map[y])
		y++;
	data->map = malloc(sizeof(char *) * (y + 1));
	while (i < y)
	{
		data->map[i] = ft_strdup(m->map[i]);
		free(m->map[i]);
		i++;
	}
	data->map[i] = NULL;
	free(m->map);
}

char	**transfer_colors(char **tab_src)
{
	int		y;
	char	**tab_dest;

	y = 0;
	tab_dest = malloc(sizeof(char *) * (len_doubletab(tab_src) + 1));
	while (tab_src[y])
	{
		tab_dest[y] = ft_strdup(tab_src[y]);
		free(tab_src[y]);
		y++;
	}
	tab_dest[y] = NULL;
	free(tab_src);
	return (tab_dest);
}
