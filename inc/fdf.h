/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:10:33 by pyathams          #+#    #+#             */
/*   Updated: 2024/06/22 20:33:57 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/ft_printf.h"
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"

# ifndef LHEX
#  define LHEX "0123456789ABCDEF"
# endif

# ifndef WHITE
#  define WHITE 0xFFFFFF
# endif

# ifndef BLACK
#  define BLACK 0x000000
# endif

# ifndef COLOR_1
#  define COLOR_1 0x581845
# endif
# ifndef COLOR_2
#  define COLOR_2 0x900C3F
# endif
# ifndef COLOR_3
#  define COLOR_3 0xC70039
# endif
# ifndef COLOR_4
#  define COLOR_4 0xFF5733
# endif
# ifndef COLOR_5
#  define COLOR_5 0xFFC30F
# endif

# ifndef WIN_H
#  define WIN_H 720
# endif

# ifndef WIN_W
#  define WIN_W 1280
# endif

# ifndef SHIFT
#  define SHIFT 10
# endif
# ifndef ROT_SHIFT
#  define ROT_SHIFT 0.05
# endif
# ifndef ZOOM_SHIFT
#  define ZOOM_SHIFT 0.5
# endif

# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_P 112
# define KEY_MINUS 45
# define KEY_PLUS 61
# define KEY_R 114
# define KEY_U 117
# define KEY_J 106
# define KEY_I 105
# define KEY_K 107
# define KEY_O 111
# define KEY_L 108

typedef struct s_map
{
	int	w;
	int	h;
	int	**zdir_mt;
	int	**clrs;
	int	iscolor;
	int	min_z;
	int	max_z;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		sz_l;
	int		endian;
}	t_img;

typedef struct s_vars
{
	void	*mlx_connection;
	void	*window;
	t_map	*map;
	t_img	*img;
	int		shift_x;
	int		shift_y;
	float	zoom;
	int		iso;
	float	flat;
	float	rot_x;
	float	rot_y;
	float	rot_z;
}	t_vars;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

void	args_handle(t_map **map, int argc, char **argv);
t_map	*width_height_map(char *file);
int		count_numbers(t_map *map, char *line);
void	free_split(char **split);
void	error_exit(void);
void	perror_exit(const char *str);
void	free_map(t_map *map);
int		ft_atoi_base(const char *str, const char *base);
void	malloc_map(t_map *map);
void	zdir_map(t_map *map, char *file);
void	filling_zdir(t_map *map, int fd);
int		color_line(t_map *map, char *s);
void	char_tolower(char *c);
void	get_min_max_z(t_map *map);
int		ft_isspace(int c);
void	ft_striter(char *s, void (*f)(char *));
int		mlx_main(t_map	*map);
int		initialise_vars(t_vars *vars, t_map *map);
void	reset_vars(t_vars *vars);
int		ft_max(int a, int b);
void	initialise_mlx(t_vars	*vars);
int		key_hook(int keycode, t_vars *vars);
void	draw_menu(t_vars *vars);
int		ft_abs(int a);
void	initialise_bresenham(t_point *start, t_point *end,
			t_point *delta, t_point *sign);
void	bresenham(t_vars *vars, t_point start, t_point end);
void	draw(t_vars *vars);
void	img_pixel_put(t_vars *vars, int x, int y, int color);
void	rot_z(t_vars *vars, int *x, int *y);
void	rot_y(t_vars *vars, int *x, int *z);
void	rot_x(t_vars *vars, int *y, int *z);
void	isometric(t_vars *vars, int *x, int *y, int z);
double	percent(int start, int end, int current);
int		get_light(int start, int end, double percent);
int		get_color(t_point current, t_point start, t_point end, t_point delta);
int		get_z_color(t_vars *vars, int cur_z);
t_point	new_point(int x, int y, t_vars *vars);
t_point	get_coords(t_vars *vars, t_point point);
void	free_all(t_vars *vars);
void	free_vars(t_vars *vars);
void	close_win(t_vars *vars);
void	handle_zoom(int keycode, t_vars *vars);
void	handle_move(int keycode, t_vars *vars);
void	handle_flattening(int keycode, t_vars *vars);
void	handle_rot(int keycode, t_vars *vars);
void	draw_rectangle(t_vars *vars, int width, int height);
void initialise_dda(t_point *start, t_point *end, float *dx, float *dy, int *steps);
void dda_line(t_vars *vars, t_point start, t_point end);

#endif