/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:20:03 by aldalmas          #+#    #+#             */
/*   Updated: 2025/02/20 14:44:24 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	search_format(char *str_to_check)
{
	int		len_str;
	int		len_xpm;
	char	*format;

	format = ft_strdup(".xpm");
	len_str = s_len(str_to_check);
	len_xpm = s_len(format);
	if (ft_strncmp(str_to_check + len_str - len_xpm, format, len_xpm) == 0)
	{
		free(format);
		return (1);
	}
	free(format);
	return (0);
}

int	is_valid_path(char *path)
{
	int	i;

	i = ft_strlen(path) - 1;
	while (path[i] && i >= 0)
	{
		if (path[i] == '.' && search_format(path) == 1)
			return (1);
		i--;
	}
	return (0);
}

char	*is_format_ok(char *path)
{
	char	*formated_path;

	formated_path = ft_strtrim(path + 2, " \n");
	if (is_valid_path(formated_path) == 1)
		return (formated_path);
	free (formated_path);
	return (NULL);
}

char	*is_infos_ok(t_map *m, t_parse *p, char *path, char orient)
{
	int		fd;
	char	*formated_path;

	formated_path = is_format_ok(path);
	if (formated_path == NULL)
	{
		special_free2(m, p);
		ft_error("Invalid format (.xpm needed)");
	}
	fd = open(formated_path, O_RDONLY);
	if (fd == -1)
	{
		free (formated_path);
		special_free2(m, p);
		if (orient == 'N')
			ft_error("'NO' path is invalid");
		if (orient == 'S')
			ft_error("'SO' path is invalid");
		if (orient == 'E')
			ft_error("'EA' path is invalid");
		if (orient == 'W')
			ft_error("'WE' path is invalid");
	}
	free (path);
	return (formated_path);
}
