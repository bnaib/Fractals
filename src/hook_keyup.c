       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.02.22 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.20 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "fractol.h"

static void	switch_fractal_type(
	int keycode,
	t_global_variables *pgv)
{
	if (keycode == 18)
		pgv->view.fractol_type = FRACTOL_JULIA;
	else if (keycode == 19)
		pgv->view.fractol_type = FRACTOL_MANDELBROT;
	else if (keycode == 20)
		pgv->view.fractol_type = FRACTOL_BURNINGSHIP;
	else if (keycode == 21)
		pgv->view.fractol_type = FRACTOL_M3;
	else if (keycode == 23)
		pgv->view.fractol_type = FRACTOL_M4;
	else if (keycode == 22)
		pgv->view.fractol_type = FRACTOL_M3AND2;
	else if (keycode == 26)
		pgv->view.fractol_type = FRACTOL_J3;
	else if (keycode == 28)
		pgv->view.fractol_type = FRACTOL_J4;
	else if (keycode == 25)
		pgv->view.fractol_type = FRACTOL_J3AND2;
}

static void	switch_color_type(
	int keycode,
	t_global_variables *pgv)
{
	if (keycode == 82)
		pgv->color_type = 0;
	else if (keycode == 83)
		pgv->color_type = 1;
	else if (keycode == 84)
		pgv->color_type = 2;
	else if (keycode == 85)
		pgv->color_type = 3;
	else if (keycode == 86)
		pgv->color_type = 4;
	else if (keycode == 87)
		pgv->color_type = 5;
	else if (keycode == 88)
		pgv->color_type = 6;
}

int			hook_keyup(int keycode, void *pp)
{
	t_global_variables	*pgv;

	pgv = (t_global_variables *)pp;
	switch_fractal_type(keycode, pgv);
	switch_color_type(keycode, pgv);
	if (keycode == 53)
		exit_program(pgv);
	return (0);
}
