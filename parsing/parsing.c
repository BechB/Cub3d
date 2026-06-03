/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:21:10 by aldalmas          #+#    #+#             */
/*   Updated: 2025/02/24 18:48:39 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_error(char *error_msg)
{
	printf(RED "ERROR\n->%s\n" RESET, error_msg);
	exit (1);
}

void	check_infos(t_parse *p, char *file_line)
{
	if (file_line == NULL)
		return ;
	if (file_line != NULL && ft_strncmp(file_line, "NO ", 3) == 0)
	{
		p->n_infos_found++;
		if (p->n_infos_found == 1 && p->n_path == NULL)
			p->n_path = ft_strdup(file_line);
	}
	else if (file_line != NULL && ft_strncmp(file_line, "SO ", 3) == 0)
	{
		p->s_infos_found++;
		if (p->s_infos_found == 1 && p->s_path == NULL)
			p->s_path = ft_strdup(file_line);
	}
	else if (file_line != NULL && ft_strncmp(file_line, "EA ", 3) == 0)
	{
		p->e_infos_found++;
		if (p->e_infos_found == 1 && p->e_path == NULL)
			p->e_path = ft_strdup(file_line);
	}
	else
		check_infos2(p, file_line);
}

void	check_infos2(t_parse *p, char *file_line)
{
	if (file_line != NULL && ft_strncmp(file_line, "WE ", 3) == 0)
	{
		p->w_infos_found++;
		if (p->w_infos_found == 1 && p->w_path == NULL)
			p->w_path = ft_strdup(file_line);
	}
	else if (file_line != NULL && ft_strncmp(file_line, "F ", 2) == 0)
	{
		p->f_infos_found++;
		if (p->f_infos_found == 1 && p->f_color == NULL)
			p->f_color = ft_strdup(file_line);
	}
	else if (file_line != NULL && ft_strncmp(file_line, "C ", 2) == 0)
	{
		p->c_infos_found++;
		if (p->c_infos_found == 1)
		{
			if (p->c_infos_found == 1 && p->c_color == NULL)
				p->c_color = ft_strdup(file_line);
		}
	}
}

void	parsing(t_parse *p, t_map *m, int ac, char **av)
{
	init_struct(p, m);
	if (ac != 2)
		ft_error("❌ Invalid number of args (only '.cub' file needed)");
	get_map_file(p, av[1]);
	split_datas(p, m);
	is_map_ok(m, p);
	if (p->n_path && p->s_path && p->e_path && p->w_path)
	{
		p->n_path = is_infos_ok(m, p, p->n_path, 'N');
		p->s_path = is_infos_ok(m, p, p->s_path, 'S');
		p->e_path = is_infos_ok(m, p, p->e_path, 'E');
		p->w_path = is_infos_ok(m, p, p->w_path, 'W');
		p->formated_color_f = is_color_ok(p->f_color);
		p->formated_color_c = is_color_ok(p->c_color);
	}
	else
	{
		special_free2(m, p);
		ft_error("❌ Error with one path");
	}
}

void	debug_print_doubletab(char **tab)
{
	int	y;

	y = 0;
	while (tab[y])
	{
		printf("DEBUG: [%s]\n", tab[y]);
		y++;
	}
}
