       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.08.07 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.20 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "fractol.h"

static unsigned int		get_m3_point_color(
							t_global_variables *pgv,
							double *d,
							int x,
							int y)
{
	int				i;
	double			k[2];

	k[0] = (x - MWW / 2.0) / pgv->view.zoom * 0.01 + pgv->view.position.x * 10;
	k[1] = (y - MWH / 2.0) / pgv->view.zoom * 0.01 + pgv->view.position.y * 10;
	d[2] = k[0] + (pgv->view.mouse_position.x - MWW / 2.0) / MWW / 100;
	d[3] = k[1] + (pgv->view.mouse_position.y - MWH / 2.0) / MWH / 100;
	i = -1;
	while (++i < pgv->max_iter)
	{
		d[0] = d[2] * d[2] * d[2] - 3.0 * d[2] * d[3] * d[3] + k[0];
		d[1] = 3.0 * d[2] * d[2] * d[3] - d[3] * d[3] * d[3] + k[1];
		d[2] = d[0];
		d[3] = d[1];
		if (d[2] * d[2] + d[3] * d[3] > MAIN_WIN_C_SQUARE_OF_RADIUS)
			break ;
	}
	i = get_color_value(pgv, i);
	return (mlx_get_color_value(pgv->mlx.ptr, i));
}

void					fill_m3(t_draw_thread_param *pdtp, int tid)
{
	int				x[2];
	int				y;
	int				xmax;
	int				ymax;
	double			d[4];

	x[0] = tid % WINBUF_IMG_HCOUNT * pdtp->pgv->winbuf.img_width - 1;
	y = tid / WINBUF_IMG_HCOUNT * pdtp->pgv->winbuf.img_height
		- pdtp->pgv->view.show_steps + pdtp->show_step;
	xmax = (tid % WINBUF_IMG_HCOUNT + 1) * pdtp->pgv->winbuf.img_width;
	ymax = (tid / WINBUF_IMG_HCOUNT + 1) * pdtp->pgv->winbuf.img_height;
	while ((y += pdtp->pgv->view.show_steps) < ymax)
	{
		x[1] = x[0];
		while (++x[1] < xmax)
		{
			((unsigned int *)pdtp->pgv->winbuf.img_data.ptr)
				[y * pdtp->pgv->winbuf.width + x[1]] =
				get_m3_point_color(pdtp->pgv, d, x[1], y);
		}
	}
}
