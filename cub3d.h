/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:57:05 by aldalmas          #+#    #+#             */
/*   Updated: 2025/02/20 19:44:11 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

# include "mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include "mini_libft/mini_libft.h"
# include "exec/exec.h"
# include "parsing/parsing.h"

typedef struct s_map
{
	int		map_len;
	char	**map;
}	t_map;

void	copy_map(t_data *data, t_map *m);
char	**transfer_colors(char **tab_src);

#endif