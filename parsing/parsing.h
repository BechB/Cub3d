/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:05:36 by aldalmas          #+#    #+#             */
/*   Updated: 2025/02/01 17:36:00 by aldalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../cub3d.h"

typedef struct s_map	t_map;
typedef struct s_parse
{
	int			map_found;
	int			n_infos_found;
	int			s_infos_found;
	int			w_infos_found;
	int			e_infos_found;
	int			f_infos_found;
	int			c_infos_found;
	int			orient_north;
	int			orient_south;
	int			orient_east;
	int			orient_west;
	int			line_nb;
	char		*n_path;
	char		*s_path;
	char		*w_path;
	char		*e_path;
	char		*f_color;
	char		*c_color;
	char		**check_colors;
	char		*temp_file;
	char		**full_file;
	char		**formated_color_f;
	char		**formated_color_c;
}				t_parse;

// --- a enlever
void	debug_print_doubletab(char **tab);

// --- init.c
void	init_struct(t_parse *p, t_map *m);

// --- parsing.c
void	parsing(t_parse *p, t_map *m, int ac, char **av);
void	ft_error(char *error_msg);
void	get_map_file(t_parse *p, char *map_path);
void	check_infos(t_parse *p, char *file_line);
void	check_infos2(t_parse *p, char *file_line);

// --- get_map_file.c
void	get_map_file(t_parse *p, char *map_path);
int		gmf_file_check(t_parse *p, char *map_path);
int		gmf_error_check(t_parse *p, char *temp, char *previous_temp);
int		gmf_map_finished(char *current_str, char *last_str);
void	gmf_search_map_line(t_parse *p, char *file_line);

// --- get_map_file_utils.c
int		gmf_is_empty_line(char *file);
int		st_idx_found(char *s1);
char	*special_trim(char *s1);
void	gmf_free(t_parse *p, char *temp, char *last_tmp);

// --- split_datas.c
void	split_datas(t_parse *p, t_map *m);

// --- map_checker.c
int		first_checker(t_map *m, int y);
int		body_checker(t_map *m, t_parse *p, int y);
int		char_checker(char c);
void	is_map_ok(t_map *m, t_parse *p);
void	check_map(t_map *m, t_parse *p, int y);
void	orient_check3(t_map *m, t_parse *p);

// --- map_checker2.c
int		char_check_orientation(char c);
int		is_closed(t_map *m, int y, int i);
void	orient_checker(t_map *m, t_parse *p, int orient);
void	orient_checker2(t_map *m, t_parse *p);
void	is_missing_player(t_map *m, t_parse *p);

// --- infos_checker.c
char	*is_infos_ok(t_map *m, t_parse *p, char *path, char orient);
char	*is_format_ok(char *path);

// --- color_checker.c
int		check_color_format(char **colors);
int		check_comma(char *color);
char	**is_color_ok(char *color);
char	**reformate_color(char **temp);
int		contain_onlydigits(char *str);

// --- color-checker-utils.c
int		is_empty(char **formated_color);
int		check_color_chars(char c);

// --- special_frees.c
void	free_doubletab(char **tab);
void	special_free1(t_parse *p);
void	special_free2(t_map *m, t_parse *p);

#endif