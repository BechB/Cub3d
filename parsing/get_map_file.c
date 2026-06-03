/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:23:29 by aldalmas          #+#    #+#             */
/*   Updated: 2025/02/24 20:58:14 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	gmf_search_map_line(t_parse *p, char *file_line)
{
	int	i;

	i = 0;
	check_infos(p, file_line);
	if (p->n_infos_found == 1 && p->s_infos_found == 1
		&& p->e_infos_found == 1 && p->w_infos_found == 1
		&& p->f_infos_found == 1 && p->c_infos_found == 1)
	{
		while (file_line[i] == ' ')
			i++;
		if (file_line[i] == '1')
			p->map_found = 1;
	}
}

int	gmf_file_check(t_parse *p, char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		free (p->temp_file);
		close(fd);
		ft_error("❌ Wrong map file");
	}
	if (s_len(map_path) == 4 && ft_strncmp(map_path, ".cub", 4) == 0)
	{
		free (p->temp_file);
		close(fd);
		ft_error("❌ Nice try... file name with only '.cub' not allowed 💩");
	}
	return (fd);
}

int	gmf_error_check(t_parse *p, char *temp, char *last_str)
{
	if (!temp)
		return (0);
	if (p->map_found == 0)
		gmf_search_map_line(p, temp);
	else if (p->map_found == 1 && gmf_map_finished(temp, last_str) == 1)
		p->map_found = 2;
	else if (p->map_found == 1)
	{
		if (gmf_is_empty_line(temp))
		{
			free (p->temp_file);
			special_free1(p);
			ft_error("❌ Empty line in map");
		}
	}
	return (1);
}

void	get_map_file(t_parse *p, char *map_path)
{
	int		fd;
	char	*temp;
	char	*last_tmp;

	last_tmp = NULL;
	p->temp_file = ft_strdup("");
	fd = gmf_file_check(p, map_path);
	while (1)
	{
		temp = get_next_line(fd);
		temp = special_trim(temp);
		if (temp == NULL || gmf_error_check(p, temp, last_tmp) == 0)
			break ;
		p->temp_file = ft_strjoin_free(p->temp_file, temp);
		p->line_nb++;
		if (last_tmp != NULL)
			free (last_tmp);
		last_tmp = ft_strdup(temp);
		free (temp);
	}
	p->full_file = ft_split(p->temp_file, '\n');
	gmf_free(p, temp, last_tmp);
	close(fd);
}

int	gmf_map_finished(char *current_str, char *last_str)
{
	int	i;

	i = 0;
	if (last_str == NULL)
		return (0);
	while (current_str[i])
	{
		if (current_str[i] != ' ' && current_str[i] != '\n')
			return (0);
		i++;
	}
	i = 0;
	while (last_str[i])
	{
		if (last_str[i] != ' '
			&& last_str[i] != '1'
			&& last_str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
