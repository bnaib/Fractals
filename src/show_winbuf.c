       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.02.22 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.20 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "fractol.h"

void	show_winbuf(t_global_variables *pgv)
{
	int		i;

	i = -1;
	lock_winbuf_img_mutex(pgv, 0);
	mlx_put_image_to_window(pgv->mlx.ptr, pgv->mlx.win.ptr,
		pgv->winbuf.img_ptr, 0, 0);
	while (++i < WINBUF_IMG_COUNT)
		pgv->winbuf.img[i].draw = 1;
	unlock_winbuf_img_mutex(pgv, 0);
}
