       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.02.22 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.20 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "fractol.h"

void			join_draw_threads(t_global_variables *pgv)
{
	int		i;
	void	*tvalue;

	i = -1;
	while (++i < WINBUF_IMG_COUNT)
	{
		if (pgv->winbuf.img[i].thread_init)
			pthread_join(pgv->winbuf.img[i].thread, &tvalue);
	}
}

static void		fill_fractal(t_draw_thread_param *pdtp)
{
	if (pdtp->pgv->view.fractol_type == FRACTOL_JULIA)
		fill_julia(pdtp, pdtp->tid);
	else if (pdtp->pgv->view.fractol_type == FRACTOL_MANDELBROT)
		fill_mandelbrot(pdtp, pdtp->tid);
	else if (pdtp->pgv->view.fractol_type == FRACTOL_BURNINGSHIP)
		fill_burningship(pdtp, pdtp->tid);
	else if (pdtp->pgv->view.fractol_type == FRACTOL_M3)
		fill_m3(pdtp, pdtp->tid);
	else if (pdtp->pgv->view.fractol_type == FRACTOL_M4)
		fill_m4(pdtp, pdtp->tid);
	else if (pdtp->pgv->view.fractol_type == FRACTOL_M3AND2)
		fill_m3and2(pdtp, pdtp->tid);
	else if (pdtp->pgv->view.fractol_type == FRACTOL_J3)
		fill_j3(pdtp, pdtp->tid);
	else if (pdtp->pgv->view.fractol_type == FRACTOL_J4)
		fill_j4(pdtp, pdtp->tid);
	else if (pdtp->pgv->view.fractol_type == FRACTOL_J3AND2)
		fill_j3and2(pdtp, pdtp->tid);
	else
		fill_winbuf(pdtp->pgv, WINBUF_IMG_BGCOLOR, pdtp->tid);
}

static void		*draw_thread(void *pp)
{
	t_draw_thread_param	*pdtp;

	pdtp = (t_draw_thread_param *)pp;
	pdtp->show_step = 0;
	while (pdtp->pgv->winbuf.img[pdtp->tid].trun)
	{
		if (pthread_mutex_lock(&pdtp->pgv->winbuf.img[pdtp->tid].mutex[0]))
			exit_program(pdtp->pgv);
		if (pdtp->pgv->winbuf.img[pdtp->tid].draw)
		{
			fill_fractal(pdtp);
			pdtp->show_step =
				(pdtp->show_step + 1) % pdtp->pgv->view.show_steps;
			lock_winbuf_img_mutex(pdtp->pgv, 1);
			unlock_winbuf_img_mutex(pdtp->pgv, 1);
			pdtp->pgv->winbuf.img[pdtp->tid].draw = 0;
		}
		if (pthread_mutex_unlock(&pdtp->pgv->winbuf.img[pdtp->tid].mutex[0]))
			exit_program(pdtp->pgv);
	}
	pthread_exit(0);
}

static	void	set_thread_img_min_max(t_draw_thread_param *pdtp)
{
	pdtp->t_img_xmin = pdtp->tid % WINBUF_IMG_HCOUNT
		* pdtp->pgv->winbuf.img_width;
	pdtp->t_img_xmax = (pdtp->tid % WINBUF_IMG_HCOUNT + 1)
		* pdtp->pgv->winbuf.img_width;
	pdtp->t_img_ymin = pdtp->tid / WINBUF_IMG_HCOUNT
		* pdtp->pgv->winbuf.img_height;
	pdtp->t_img_ymax = (pdtp->tid / WINBUF_IMG_HCOUNT + 1)
		* pdtp->pgv->winbuf.img_height;
}

void			create_draw_threads(
				t_draw_thread_param *pdtp,
				t_global_variables *pgv)
{
	int					i;

	i = -1;
	while (++i < WINBUF_IMG_COUNT)
	{
		pdtp[i].tid = i;
		pdtp[i].pgv = pgv;
		set_thread_img_min_max(&pdtp[i]);
		if ((pgv->winbuf.img[i].tattr_init =
			pthread_attr_init(&pgv->winbuf.img[i].tattr)))
			exit_program(pgv);
		else
			pgv->winbuf.img[i].tattr_init = 1;
		if ((pgv->winbuf.img[i].thread_init =
			pthread_create(&pgv->winbuf.img[i].thread,
			&pgv->winbuf.img[i].tattr, draw_thread, (void *)&pdtp[i])))
			exit_program(pgv);
		else
			pgv->winbuf.img[i].thread_init = 1;
	}
}
