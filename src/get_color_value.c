       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.08.08 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.20 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "fractol.h"

int		get_color_value(t_global_variables *pgv, int i)
{
	int		k;

	if (pgv->color_type == 0)
		return (i % pgv->max_iter);
	i *= 10;
	if (pgv->color_type == 1)
		return (i % pgv->max_iter);
	if (pgv->color_type == 2)
		return (i % pgv->max_iter * 256);
	if (pgv->color_type == 3)
		return (i % pgv->max_iter * 65536);
	if (pgv->color_type == 4)
		i *= 2;
	if (pgv->color_type == 5)
		i *= 5;
	if (pgv->color_type == 6)
		i *= 10;
	k = i / 256 % 3;
	if (k == 0)
		return (i % pgv->max_iter);
	if (k == 1)
		return (i % pgv->max_iter * 256);
	if (k == 2)
		return (i % pgv->max_iter * 65536);
	return (0);
}
