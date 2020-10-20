       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.03.10 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.20 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "fractol.h"

void		check_keys_move(
				int keycode,
				t_global_variables *pgv)
{
	if (keycode == 0)
		pgv->view.position.x -= VIEW_MOVE_STEP / pgv->view.zoom;
	else if (keycode == 2)
		pgv->view.position.x += VIEW_MOVE_STEP / pgv->view.zoom;
	else if (keycode == 13)
		pgv->view.position.y -= VIEW_MOVE_STEP / pgv->view.zoom;
	else if (keycode == 1)
		pgv->view.position.y += VIEW_MOVE_STEP / pgv->view.zoom;
	else if (keycode == 69)
		pgv->view.zoom *= VIEW_ZOOM_STEP;
	else if (keycode == 78)
		pgv->view.zoom /= VIEW_ZOOM_STEP;
	if (pgv->view.zoom > VIEW_ZOOM_MAX)
		pgv->view.zoom = VIEW_ZOOM_MAX;
	if (pgv->view.zoom < VIEW_ZOOM_MIN)
		pgv->view.zoom = VIEW_ZOOM_MIN;
}
