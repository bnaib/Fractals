       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.02.22 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.20 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#ifndef __GLOBAL_VARIABLES_H
# define __GLOBAL_VARIABLES_H

typedef struct		s_gv_mlx_win
{
	void				*ptr;
	int					width;
	int					height;
}					t_gv_mlx_win;

typedef struct		s_gv_mlx
{
	void				*ptr;
	t_gv_mlx_win		win;
}					t_gv_mlx;

typedef struct		s_gc_info
{
	char				fps;
	char				help;
	char				adv;
}					t_gv_info;

typedef struct		s_gv_wb_img_data
{
	int					bpp;
	int					sl;
	int					endian;
	char				*ptr;
}					t_gv_wb_img_data;

typedef struct		s_gv_wb_img
{
	int					x;
	int					y;
	char				draw;
	int					mattr_init[2];
	pthread_mutexattr_t	mattr[2];
	int					mutex_init[2];
	pthread_mutex_t		mutex[2];
	int					tattr_init;
	pthread_attr_t		tattr;
	int					thread_init;
	pthread_t			thread;
	char				trun;
}					t_gv_wb_img;

typedef struct		s_gv_winbuf
{
	int					width;
	int					height;
	int					img_width;
	int					img_height;
	t_gv_wb_img_data	img_data;
	void				*img_ptr;
	t_gv_wb_img			img[WINBUF_IMG_COUNT];
}					t_gv_winbuf;

typedef struct		s_int_position_2d
{
	double				x;
	double				y;
}					t_int_position_2d;

typedef struct		s_gv_view
{
	double				zoom;
	t_int_position_2d	position;
	t_int_position_2d	mouse_position;
	char				show_steps;
	char				fractol_type;
}					t_gv_view;

typedef struct		s_global_variables
{
	t_gv_mlx			mlx;
	t_gv_info			info;
	t_gv_winbuf			winbuf;
	t_gv_view			view;
	int					max_iter;
	int					color_type;
}					t_global_variables;

typedef struct		s_draw_thread_param
{
	int					tid;
	char				show_step;
	int					t_img_xmin;
	int					t_img_ymin;
	int					t_img_xmax;
	int					t_img_ymax;
	t_global_variables	*pgv;
}					t_draw_thread_param;

#endif
