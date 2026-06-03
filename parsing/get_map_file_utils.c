/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_file_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:15:37 by aldalmas          #+#    #+#             */
/*   Updated: 2025/02/24 20:42:39 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*special_trim(char *temp_gnl)
{
	size_t	i;
	char	*new_s1;
	char	*temp;

	new_s1 = NULL;
	if (temp_gnl == NULL)
		return (NULL);
	i = st_idx_found(temp_gnl);
	temp = ft_substr(temp_gnl, 0, i);
	free(temp_gnl);
	new_s1 = ft_strjoin(temp, "\n");
	free(temp);
	return (new_s1);
}

int	st_idx_found(char *s1)
{
	int	i;

	i = s_len(s1) - 1;
	while (i >= 0)
	{
		if (s1[i] == ' ' || s1[i] == '\n')
			i--;
		else
			return (i + 1);
	}
	return (0);
}

int	gmf_is_empty_line(char *file)
{
	int	i;

	i = 0;
	while (file[i] == ' ')
		i++;
	if (file[i] == '1')
	{
		while (file[i] == '1')
			i++;
		if (file[i] != '\n' && file[i] != '\0' && file[i] != ' ')
			return (0);
	}
	else
	{
		if (file[i] == '\n')
			return (1);
	}
	return (0);
}

void	gmf_free(t_parse *p, char *temp, char *last_tmp)
{
	free (temp);
	free(last_tmp);
	free(p->temp_file);
}
