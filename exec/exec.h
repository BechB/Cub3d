/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:12:42 by bbousaad          #+#    #+#             */
/*   Updated: 2025/06/15 13:33:03 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# define RED2       0xFF0000
# define GREEN2     0x00FF00
# define BLUE2      0x0000FF
# define BLACK2     0x000000
# define GREY2      0x808080
# define PURPLE2    0x800080
# define ESC	    65307
# define UP		    65362
# define LEFT       65361
# define DOWN       65364
# define RIGHT      65363
# define A          97
# define D          100
# define W          119
# define S          115
# define PI         3.1415926535
# define TURN       0.007
# define WIN_WIDTH  900
# define WIN_HEIGHT 500
# define FOV        60.0
# include "../cub3d.h"

typedef struct s_parse	t_parse;
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
	int		img_x;
	int		img_y;
}				t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		map_height;
	int		map_width;
	char	**map;
	t_img	img[4];
	double	player_x;
	double	player_y;
	double	player_angle;
	double	new_x;
	double	new_y;
	int		map_x;
	int		map_y;
	double	ray_x;
	double	ray_y;
	double	ray_angle;
	double	dist_y;
	double	dist_x;
	double	side_dist_x;
	double	side_dist_y;
	double	dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	char	**f_color;
	char	**c_color;
	int		f_red;
	int		f_green;
	int		f_blue;
	int		c_red;
	int		c_green;
	int		c_blue;
	int		last_mouse_x;
	int		first_move;
	double	hit_x;
	double	hit_y;
	int		start;
	int		end;
	int		line_height;
	float	distance_to_wall;
	double	texture_step;
	double	texture_pos;
}	t_data;

//--WARNING / ERROR
void	ft_exit(t_data *dta, char *mess, int status);
void	ft_error(char *error_msg);

//--UTILS
void	pos_player(t_data *dta);
void	map_size(t_data *dta);
void	draw_big_pixel_floor(void *mlx_ptr, void *win_ptr, int x, int y);
void	draw_big_pixel_wall(void *mlx_ptr, void *win_ptr, int x, int y);
void	draw_big_pixel_player(void *mlx_ptr, void *win_ptr, int x, int y);
void	draw_big_pixel_floor2(void *mlx_ptr, void *win_ptr, int x, int y);

//--RENDER
void	open_win(t_data *data, t_img *img, t_parse *p);
void	render(t_data *data, t_img *img);
void	put_mini(t_data *data, int i, int j);
void	put_mini2(t_data *data);
void	put_pixels_lines(t_data *data, t_img *img, int x, int y);

//--CALCUL RENDER
int		can_move(t_data *data);
void	set_limits(t_data *data);
void	set_texture(t_data *data, t_img *img);
void	load_img(t_data *data, t_img *img, char *path);
void	set_ray(t_data *data);
void	compare_ray(t_data *data);
void	texture_choice(t_data *data);

//--INIT-RENDER
int		convert_color2(int red, int green, int blue);
void	convert_color(t_data *data);
void	init_data_render(t_data *data, int x);
void	init_img(t_data *data, t_parse *p);
void	handle_view(t_data *data, int i, int j);
void	init_player(t_data *data);

//--KEY / EVENTS
int		key_press(int keycode, t_data *data, t_img *img);
int		key_press3(int keycode, t_data *data);
int		key_press2(int keycode, t_data *data);
int		destroy(t_data *data);
int		mouse(int x, int y, t_data *data, t_img *img);

#endif