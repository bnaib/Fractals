       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.02.22 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.20 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#ifndef __FRACTOL_H
# define __FRACTOL_H
# include <errno.h>
# include <mlx.h>
# include <time.h>
# include <pthread.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define MAIN_WIN_WIDTH 1800
# define MWW MAIN_WIN_WIDTH
# define MAIN_WIN_HEIGHT 1000
# define MWH MAIN_WIN_HEIGHT
# define MAIN_WIN_HEADER "School 21 - Fract'ol - author: bnaib"
# define MAIN_WIN_C_SQUARE_OF_RADIUS 82

# define WINBUF_IMG_HCOUNT 4
# define WINBUF_IMG_VCOUNT 1
# define WINBUF_IMG_COUNT 4

# define WINBUF_IMG_BGCOLOR 0x303030
# define WINBUF_IMG_FILLCOLOR 0x005000

# define AFPS_TIMEOUT 10

# define VIEW_ZOOM_STEP 1.1
# define VIEW_ZOOM_MAX 10000.0
# define VIEW_ZOOM_MIN 0.01

# define VIEW_MOVE_STEP 0.05

# define FRACTOL_JULIA 1
# define FRACTOL_MANDELBROT 2
# define FRACTOL_BURNINGSHIP 3
# define FRACTOL_M3 4
# define FRACTOL_M4 5
# define FRACTOL_M3AND2 6
# define FRACTOL_J3 7
# define FRACTOL_J4 8
# define FRACTOL_J3AND2 9

# include "libft.h"
# include "global_variables.h"

void			exit_program(t_global_variables *pgv);
void			load_default_values(t_global_variables *gv);

void			join_draw_threads(t_global_variables *pgv);
void			create_draw_threads(
					t_draw_thread_param *pdtp,
					t_global_variables *pgv);

int				get_color_value(t_global_variables *pgv, int i);

void			fill_winbuf(
					t_global_variables *pgv,
					int color, int tid);
void			fill_julia(t_draw_thread_param *pdtp, int tid);
void			fill_mandelbrot(t_draw_thread_param *pdtp, int tid);
void			fill_burningship(t_draw_thread_param *pdtp, int tid);
void			fill_m3(t_draw_thread_param	*pdtp, int tid);
void			fill_m4(t_draw_thread_param	*pdtp, int tid);
void			fill_m3and2(t_draw_thread_param *pdtp, int tid);
void			fill_j3(t_draw_thread_param *pdtp, int tid);
void			fill_j4(t_draw_thread_param *pdtp, int tid);
void			fill_j3and2(t_draw_thread_param *pdtp, int tid);
void			show_fps(t_global_variables *pgv);
void			show_winbuf(t_global_variables *pgv);

void			destroy_winbuf_img(t_global_variables *pgv);
void			create_winbuf_img(t_global_variables *pgv);

void			lock_winbuf_img_mutex(t_global_variables *pgv, int id);
void			unlock_winbuf_img_mutex(t_global_variables *pgv, int id);
void			destroy_winbuf_img_mutex(t_global_variables *pgv, int id);
void			create_winbuf_img_mutex(t_global_variables *pgv);

void			join_draw_threads(t_global_variables *pgv);
void			create_draw_threads(
					t_draw_thread_param *pdtp,
					t_global_variables *pgv);

int				move_hook(int x, int y, t_global_variables *pgv);

int				hook_keyup(int keycode, void *pp);
int				hook_mouse(int button, int x, int y, void *pp);
int				hook_loop(void *pp);
int				hook_keydown(int keycode, void *pp);
int				hook_wndexit(void *pp);

void			check_mkeys_zoom(
					int keycode,
					t_global_variables *pgv);
void			check_keys_show_steps(
					int keycode,
					t_global_variables *pgv);
void			check_keys_move(
					int keycode,
					t_global_variables *pgv);
#endif
