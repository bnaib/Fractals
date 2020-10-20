       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.03.10 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.20 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "fractol.h"

void		check_keys_show_steps(
				int keycode,
				t_global_variables *pgv)
{
	if (keycode == 43)
		pgv->view.show_steps--;
	else if (keycode == 47)
		pgv->view.show_steps++;
	if (pgv->view.show_steps < 1)
		pgv->view.show_steps = 1;
	if (pgv->view.show_steps > 5)
		pgv->view.show_steps = 5;
}
