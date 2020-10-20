       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.02.22 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.20 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "fractol.h"

static void	check_keys_max_iter(
	int keycode,
	t_global_variables *pgv)
{
	if (keycode != 27 && keycode != 24)
		return ;
	if (keycode == 27)
		pgv->max_iter--;
	else if (keycode == 24)
		pgv->max_iter++;
	if (pgv->max_iter < 10)
		pgv->max_iter = 10;
	if (pgv->max_iter > 256)
		pgv->max_iter = 256;
}

int			hook_keydown(int keycode, void *pp)
{
	t_global_variables	*pgv;

	if (pp == NULL)
		return (0);
	pgv = (t_global_variables *)pp;
	check_keys_move(keycode, pgv);
	check_keys_show_steps(keycode, pgv);
	check_keys_max_iter(keycode, pgv);
	return (0);
}
