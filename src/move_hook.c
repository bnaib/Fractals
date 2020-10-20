       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.08.09 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.20 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "fractol.h"

int		move_hook(int x, int y, t_global_variables *pgv)
{
	if (x >= 0 && x < MAIN_WIN_WIDTH)
		pgv->view.mouse_position.x = x;
	if (y >= 0 && y < MAIN_WIN_HEIGHT)
		pgv->view.mouse_position.y = y;
	return (0);
}
