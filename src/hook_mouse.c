       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.02.22 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.20 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "fractol.h"

int		hook_mouse(int button, int x, int y, void *pp)
{
	t_global_variables	*pgv;

	pgv = (t_global_variables *)pp;
	check_mkeys_zoom(button, pgv);
	return (0);
}
