       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.02.22 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.20 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "fractol.h"

void		exit_program(t_global_variables *pgv)
{
	int		i;

	if (errno)
		perror("Fractol");
	i = -1;
	while (++i < WINBUF_IMG_COUNT)
		pgv->winbuf.img[i].trun = 0;
	join_draw_threads(pgv);
	destroy_winbuf_img_mutex(pgv, 1);
	destroy_winbuf_img_mutex(pgv, 0);
	destroy_winbuf_img(pgv);
	if (pgv->mlx.win.ptr != NULL)
		mlx_destroy_window(pgv->mlx.ptr, pgv->mlx.win.ptr);
	exit(0);
}
