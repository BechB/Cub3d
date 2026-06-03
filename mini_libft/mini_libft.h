/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:49:00 by aldalmas          #+#    #+#             */
/*   Updated: 2025/02/20 17:04:36 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_LIBFT_H
# define MINI_LIBFT_H

// GNL
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_strlen(const char *s);
int		ft_strlen_dtab(char **tab);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin_free(char *stock, char *temp);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strtrim(char *s1, char *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_putchar(char c);
int		handle_int_limit(char *s);
int		len_doubletab(char **tab);

// MON GNL
int		s_len(char *s);
int		search_backslash_n(char	*stock);
char	*get_next_line(int fd);
char	*if_find_newline(int fd, int ret, char **stock, char *temp);
char	*ft_strjoin_gnl(char *stock, char *temp);
char	*line_to_return(char *stock, int idx_backslash_n);
char	*cut_and_update_stock(char *stock, int idx_backslash_n);
void	stock_verification(char **stock);

#endif