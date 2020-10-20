       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.02.22 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.20 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "fractol.h"

static void	load_def_dv_mlx(t_global_variables *pgv)
{
	pgv->mlx.ptr = NULL;
	pgv->mlx.win.ptr = NULL;
	pgv->mlx.win.width = MAIN_WIN_WIDTH;
	pgv->mlx.win.height = MAIN_WIN_HEIGHT;
}

static void	load_def_gv_winbuf(t_global_variables *pgv)
{
	int		i;

	i = -1;
	pgv->winbuf.img_ptr = NULL;
	while (++i < WINBUF_IMG_COUNT)
	{
		pgv->winbuf.img[i].draw = 0;
		pgv->winbuf.img[i].mattr_init[0] = 0;
		pgv->winbuf.img[i].mattr_init[1] = 0;
		pgv->winbuf.img[i].mutex_init[0] = 0;
		pgv->winbuf.img[i].mutex_init[1] = 0;
		pgv->winbuf.img[i].tattr_init = 0;
		pgv->winbuf.img[i].thread_init = 0;
		pgv->winbuf.img[i].trun = 1;
	}
}

static void	load_def_gv_view(t_global_variables *pgv)
{
	pgv->view.zoom = 1.0;
	pgv->view.position.x = 0;
	pgv->view.position.y = 0;
	pgv->view.fractol_type = FRACTOL_JULIA;
	pgv->view.mouse_position.x = 0;
	pgv->view.mouse_position.y = 0;
	pgv->view.show_steps = 5;
}

void		load_default_values(t_global_variables *pgv)
{
	pgv->max_iter = 256;
	pgv->color_type = 6;
	load_def_dv_mlx(pgv);
	pgv->info.fps = 1;
	pgv->info.help = 1;
	pgv->info.adv = 1;
	load_def_gv_winbuf(pgv);
	load_def_gv_view(pgv);
}
