       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.02.22 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.20 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "fractol.h"

void		check_mkeys_zoom(
				int keycode,
				t_global_variables *pgv)
{
	if (keycode == 5)
		pgv->view.zoom /= VIEW_ZOOM_STEP;
	if (keycode == 4)
		pgv->view.zoom *= VIEW_ZOOM_STEP;
	if (pgv->view.zoom > VIEW_ZOOM_MAX)
		pgv->view.zoom = VIEW_ZOOM_MAX;
	if (pgv->view.zoom < VIEW_ZOOM_MIN)
		pgv->view.zoom = VIEW_ZOOM_MIN;
}
