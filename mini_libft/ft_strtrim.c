/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:58:23 by aldalmas          #+#    #+#             */
/*   Updated: 2024/03/29 09:57:34 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_libft.h"

size_t	end_idx_set(char *s1, char *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		if (ft_strchr(set, s1[i]))
			i--;
		else
			return (i + 1);
	}
	return (0);
}

int	start_idx_set(char *s1, char *set, int end_idx)
{
	int	i;

	i = 0;
	while (i < end_idx)
	{
		if (ft_strchr(set, s1[i]))
			i++;
		else
			return (i);
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	int	j;
	int	i;

	if (!set)
		return (NULL);
	j = end_idx_set(s1, set);
	i = start_idx_set(s1, set, j);
	return (ft_substr(s1, i, j - i));
}
