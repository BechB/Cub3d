/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:02:36 by aldalmas          #+#    #+#             */
/*   Updated: 2025/02/21 13:59:02 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_libft.h"

char	*if_find_newline(int fd, int ret, char **stock, char *temp)
{
	int		idx_newline;
	char	*returned_line;

	while (ret > 0 || search_backslash_n(*stock) >= 0)
	{
		temp[ret] = '\0';
		*stock = ft_strjoin_gnl(*stock, temp);
		if (!(*stock))
			return (NULL);
		idx_newline = search_backslash_n(*stock);
		if (idx_newline >= 0)
		{
			returned_line = line_to_return(*stock, idx_newline);
			if (!(*returned_line))
				return (free(*stock), *stock = NULL);
			*stock = cut_and_update_stock(*stock, idx_newline);
			return (returned_line);
		}
		ret = read(fd, temp, BUFFER_SIZE);
	}
	return (NULL);
}

void	stock_verification(char **stock)
{
	if (!(*stock))
	{
		*stock = malloc(sizeof(char) * 1);
		if (!(*stock))
		{
			*stock = NULL;
			return ;
		}
		*stock[0] = '\0';
	}
}

char	*get_next_line(int fd)
{
	int			ret;
	char		temp[BUFFER_SIZE + 1];
	static char	*stock;
	char		*returned_line;

	ret = read(fd, temp, BUFFER_SIZE);
	if (ret == -1)
	{
		if (stock)
			free(stock);
		return (stock = NULL);
	}
	stock_verification(&stock);
	returned_line = if_find_newline(fd, ret, &stock, temp);
	if (returned_line)
		return (returned_line);
	if (stock[0] == '\0')
		return (free(stock), stock = NULL);
	returned_line = line_to_return(stock, s_len(stock));
	free(stock);
	stock = NULL;
	return (returned_line);
}
