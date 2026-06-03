/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:55:23 by aldalmas          #+#    #+#             */
/*   Updated: 2024/11/07 17:54:46 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_libft.h"

int	get_result(const char *str, int i)
{
	int	result;

	result = 0;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	minus_count;

	i = 0;
	result = 0;
	minus_count = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\r') || (str[i] == '\v') || (str[i] == '\f'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus_count++;
		i++;
	}
	if (ft_isdigit(str[i]) == 0)
		return (0);
	result = get_result(str, i);
	if (minus_count == 1)
		return (result * -1);
	return (result);
}
