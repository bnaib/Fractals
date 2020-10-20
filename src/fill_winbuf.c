       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.02.22 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.20 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "fractol.h"

void	fill_winbuf(t_global_variables *pgv, int color, int tid)
{
	int				x[2];
	int				y;
	int				xmax;
	int				ymax;
	unsigned int	c;

	c = mlx_get_color_value(pgv->mlx.ptr, color);
	x[0] = tid % WINBUF_IMG_HCOUNT * pgv->winbuf.img_width - 1;
	y = tid / WINBUF_IMG_HCOUNT * pgv->winbuf.img_height - 1;
	xmax = (tid % WINBUF_IMG_HCOUNT + 1) * pgv->winbuf.img_width;
	ymax = (tid / WINBUF_IMG_HCOUNT + 1) * pgv->winbuf.img_height;
	while (++y < ymax)
	{
		x[1] = x[0];
		while (++x[1] < xmax)
		{
			((unsigned int *)pgv->winbuf.img_data.ptr)
				[y * pgv->winbuf.width + x[1]] = c;
		}
	}
}
