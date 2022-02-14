/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:47:34 by msimon            #+#    #+#             */
/*   Updated: 2021/12/05 08:31:29 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"

/*WIDTH не меньше 320 HEIGHT не меньше 240*/
# define WIDTH			1440
# define HEIGHT			900
# define CFRAME			100
# define SP_SPEED		0.05
# define DO_SPEED		0.1
# define PI				3.1415926535
/*FOV - угол обзора в градусах*/
# define FOV			60.0
# define MOVE_SPEED		0.1
# define ROT_SPEED		3.0
# define ROT_MOUSE		1.5
# define MOUSE_WAIT		3
# define WALL			0.2001
# define ESC			53
# define BUTTON_W		13
# define BUTTON_A		0
# define BUTTON_S		1
# define BUTTON_D		2
# define BUTTON_E		14
# define LEFT			123
# define RIGHT			124

# define ERR_MEM		"Memory was allocated incorrectly\n"
# define ERR_USAGE		"Usage: ./cub3D MAP_FILE(*.cub)\n"
# define ERR_OPEN_F		"No open file"
# define ERR_TYPE_F		"Incorrect type MAP_FILE(*.cub)\n"
# define ERR_READ_F		"No read file"
# define ERR_CMD_F		"Parser map: incorrect cmd or map line\n"
# define ERR_TEX_F		"Parser map: texture file not opened\n"
# define ERR_COL_VAL	"Parser map: incorrect color value\n"
# define ERR_RGB_VAL	"Parser map: value out of range [0..255]\n"
# define ERR_UNI_SMB	"The special symbol of the map is not unique\n"
# define ERR_NOT_SMB	"The special symbol of the map is not correct\n"
# define ERR_WALL_T		"Parser map: the wall texture is already set\n"
# define ERR_SET_COL	"The color of the floor and ceiling is already set\n"
# define ERR_NULL_MAP	"Parser map: map is NULL\n"
# define ERR_MAP_LN		"Parser map: map line is long\n"
# define ERR_PLR_POS	"Parser map: player not found\n"
# define ERR_NO_WALL	"Parser map: not all wall texture\n"
# define ERR_DOOR_POS	"Parser map: door position error\n"
# define ERR_CONTOUR	"Parser map: contour not closed\n"

typedef struct s_ipoint
{
	int		x;
	int		y;
}	t_ipoint;

typedef struct s_fpoint
{
	float	x;
	float	y;
}	t_fpoint;

typedef struct s_pfpoint
{
	float	*x;
	float	*y;
}	t_pfpoint;

typedef struct s_image
{
	void	*src;
	int		w;
	int		h;
	int		*pimg;
	int		bpp;
	int		sl;
	int		end;
}	t_image;

/*Источник для вертикального рендеринга*/
/*img - исходная текстура*/
/*pos - положение выбранной горизонтальной линии от левого края [0..1)*/
/*size - размер изоброжения в пикселях*/
typedef struct s_src_render
{
	t_image	*img;
	float	pos;
	float	size;
	char	type;
	float	dist;
	void	*data;
}	t_src_render;

typedef struct s_pl_move
{
	float	ud_move;
	float	lr_move;
	float	rt_move;
	int		x_mouse;
	int		m_counter;	
	char	event_f;
}	t_pl_move;

typedef struct s_player
{
	float	posx;
	float	posy;
	float	posa;
}	t_player;

typedef struct s_element_map
{
	char	type;
	void	*data;	
}	t_element_map;

typedef struct s_map
{
	t_element_map	*el;
	int				w;
	int				h;
}	t_map;

typedef struct s_wall
{
	t_image	n;
	t_image	e;
	t_image	s;
	t_image	w;
}	t_wall;

/*Тип двери для карты*/
/*img ссылка на текстуру*/
/*pos положение начала двери, измен. от 0 до 1*/
/*open флаг открытия двери 0 - закрыта 1, -откр.*/
/*dir флаг ориентации двери 0 - гор. 1 - вертик.*/
/*пройти можно когда open - 1 и pos - 1*/
typedef struct s_door
{
	t_image	*img;
	float	pos;
	char	open;
	char	dir;
	int		x;
	int		y;
}	t_door;

/*Тип спрайтов*/
/*texs массив текстур*/
/*n_sp номер текущего спрайта из массива текстур 0 <= n_sp < размер(texs)*/
/*x, y - координаты центра спрайта*/
/*dx, dy - ед. вектор который указывает направление движения*/
/*fix флаг 1 - движ. 0 - недвижимый*/
/*cfarme и count отвечают за задержку между перестроениями спрайтов*/
typedef struct s_sprite
{
	t_image	**texs;
	int		n_sp;
	float	x;
	float	y;
	float	dx;
	float	dy;
	char	fix;
	float	size;
	float	r;
	int		xb;
	int		xe;
	int		cframe;
	int		count;
}	t_sprite;

typedef struct s_bg
{
	int		ceil;
	int		floor;
	char	flg_init;
}	t_bg;

/*fix флаг 1 - движ. 0 - недвижимый*/
typedef struct s_texs
{
	t_image	**texs;
	char	smb;
	char	fix;
	int		cframe;	
}	t_texs;

typedef struct s_screen
{
	void	*mlx;
	void	*win;
	int		counter;
	t_image	buf;
}	t_screen;

typedef struct s_main_data
{
	t_screen	scr;
	t_bg		bg;
	t_pl_move	pl_move;
	t_player	player;
	t_map		map;
	t_wall		wall;
	t_texs		**door_tex_arr;
	t_texs		**sp_tex_arr;
	t_sprite	**sprs;
	t_door		**doors;
	t_image		mini_map;
	float		scale;
}	t_main_data;

typedef struct s_mappoint
{
	float	x;
	float	y;
	int		ok;
	char	type;
	void	*data;
}	t_mappoint;

typedef struct s_points
{
	t_mappoint	ver;
	t_mappoint	hor;
}	t_points;

typedef struct s_dist
{
	float	ver_dist;
	float	hor_dist;
}	t_dist;

/*messages.c*/
void			prt_error(char *str, char fl);

/*arr_utils.c*/
void			init_arr(void ***arr);
int				arr_len(void **arr);
int				add_arr_el(void ***arr, size_t size);
void			drop_arr(void **arr);

/*init_utils.c*/
void			init_md(t_main_data *md);
void			init_hook(t_main_data *md);

/*event_utils.c*/
int				key_press(int key, t_main_data *md);
int				key_release(int key, t_main_data *md);
int				mouse_move(int x, int y, t_main_data *md);

/*close_app.c*/
int				close_app(t_main_data *md);

/*render.c*/
int				render_next_frame(t_main_data *md);

/*ray_render.c*/
void			ray_render(t_main_data *md, int x, t_src_render **arr);

/*parser_map.c*/
void			parsing_map(t_main_data *md, char *fn);

/*parser_cmd.c*/
void			parser_wall(t_main_data *md, t_image *wall, char *str, int pos);
void			parser_bg(int *col, char *str, int pos);

/*parser_texs.c*/
void			parser_texs(t_main_data *md, t_texs ***arr, char *str, int pos);
int				chk_smb_in_texs(t_texs **arr, char ch);

/*check_map.c*/
void			ch_map(t_main_data *md);

/*check_map_utils.c*/
void			ch_border_pos(t_main_data *md, int x, int y);
t_element_map	get_map_el(t_main_data *md, int x, int y);
void			ch_and_add_el(t_main_data *md, t_ipoint p,
					t_ipoint ***ch_arr, t_ipoint ***pro_arr);

/*set_map.c*/
void			set_map(t_main_data *md, char **map);

/*set_el_map.c*/
void			set_el_map(t_main_data *md, char ch, int p);

/*set_unmapped_el.c*/
void			set_sp_map(t_main_data *md, int s, int x, int y);
void			set_plr_map(t_main_data *md, char ch, int x, int y);

/*string_utils.c*/
/*Возвращает следующий посли слова номер символа или -1 конец стр.*/
int				get_next_word(char *str, char **cmd, int pos);
void			str_join_char(char **str, char ch);

/*graph_utils.c*/
int				merge_pixel(int down, int up);
void			draw_img(t_image dst, t_image src, int xz, int yz);
void			draw_pixel(t_image dst, int x, int y, int color);

/*graph_utils2.c*/
void			draw_rhomb(t_image dst, t_ipoint centre, int size, int color);

/*draw_mini_map.c*/
void			draw_mini_map(t_main_data *md);

/*render_init_sprites.c*/
void			init_sprites(t_main_data *md);

/*JHIZDAHR*/
/*mechanics.c*/
t_src_render	***make_arr_ray(t_main_data *md);

/*horizontal_point.c*/
t_mappoint		get_horizontal_point(t_player player, float angle, t_map map);

/*vertical_point.c*/
t_mappoint		get_vertical_point(t_player player, float angle, t_map map);

/*player_move.c*/
void			player_move(t_main_data *md);
int				point_check(float x, float y, t_main_data *md, float wall);

/*other_move.c*/
void			other_move(t_main_data *md);
/*Функция проверяет можно ли изменить позицию объекта*/
/*f флаг изменения - если 0 меняем всегда если есть возможность*/
/*f флаг изменения - если 1 меняем только если изменение по двум координатам*/
/*и только при приближении до 0.5 для спрайтов*/
/*возвращает 1 если изменение выполнено и 0 если нет*/
char			change_pos(t_main_data *md, t_pfpoint pos, t_fpoint d, char f);

/*check_door_opening.c*/
int				check_door_near_player(t_main_data *md, t_door *door);

/*mechanics_utils.c*/
float			angle_math(float angle);
float			get_distance(t_mappoint point, t_player player, double angle);
void			choose_img(t_mappoint p, t_src_render *res, float now_angle);
float			count_pos(t_src_render *res, t_points points, float now_angle);
void			check_type(t_src_render *res, t_dist dist);

#endif
