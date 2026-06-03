/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:38:36 by aldalmas          #+#    #+#             */
/*   Updated: 2024/11/30 15:48:29 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_libft.h"

int	s_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *stock, char *temp)
{
	char	*memory;
	int		i;
	int		j;

	memory = malloc(sizeof(char) * (s_len(stock) + s_len(temp) + 1));
	if (!memory)
		return (free(stock), NULL);
	i = -1;
	while (stock[++i])
		memory[i] = stock[i];
	memory[i] = '\0';
	j = i;
	i = -1;
	while (temp[++i])
		memory[j + i] = temp[i];
	memory[j + i] = '\0';
	free(stock);
	return (memory);
}

char	*line_to_return(char *stock, int idx_backslash_n)
{
	int		i;
	char	*row_to_return;

	i = 0;
	if (search_backslash_n(stock) == -1)
		row_to_return = malloc(sizeof(char) * (idx_backslash_n + 1));
	else
		row_to_return = malloc(sizeof(char) * (idx_backslash_n + 2));
	if (!row_to_return)
		return (NULL);
	while (stock[i] && (i <= idx_backslash_n))
	{
		row_to_return[i] = stock[i];
		i++;
	}
	row_to_return[i] = '\0';
	return (row_to_return);
}

char	*cut_and_update_stock(char *stock, int idx_backslash_n)
{
	int		i;
	char	*new_stock;

	i = 0;
	new_stock = malloc(sizeof(char) * (s_len(stock) - idx_backslash_n) + 1);
	if (!new_stock)
		return (free(stock), stock = NULL);
	while (stock[i + idx_backslash_n + 1])
	{
		new_stock[i] = stock[i + idx_backslash_n + 1];
		i++;
	}
	new_stock[i] = '\0';
	free(stock);
	stock = NULL;
	return (new_stock);
}

int	search_backslash_n(char	*stock)
{
	int	i;

	i = 0;
	while (stock[i])
	{
		if (stock[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
