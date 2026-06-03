/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int_limit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:33:40 by aldalmas          #+#    #+#             */
/*   Updated: 2025/02/20 17:04:57 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_libft.h"

int	handle_int_limit(char *s)
{
	int	len_s;

	len_s = ft_strlen(s);
	if (len_s > 11)
		return (0);
	if (s[0] != '-')
	{
		if (len_s == 10 && ft_strncmp(s, "2147483647", 10) > 0)
			return (0);
	}
	else
	{
		if (len_s == 11 && ft_strncmp(s, "-2147483648", 11) > 0)
			return (0);
	}
	return (1);
}
