       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.02.22 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.20 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "fractol.h"

static int	check_param(char *str)
{
	if (!ft_strcmp(str, "julia"))
		return (FRACTOL_JULIA);
	if (!ft_strcmp(str, "mandelbrot"))
		return (FRACTOL_MANDELBROT);
	if (!ft_strcmp(str, "burningship"))
		return (FRACTOL_BURNINGSHIP);
	if (!ft_strcmp(str, "m3"))
		return (FRACTOL_M3);
	if (!ft_strcmp(str, "m4"))
		return (FRACTOL_M4);
	if (!ft_strcmp(str, "m3and2"))
		return (FRACTOL_M3AND2);
	if (!ft_strcmp(str, "j3"))
		return (FRACTOL_J3);
	if (!ft_strcmp(str, "j4"))
		return (FRACTOL_J4);
	if (!ft_strcmp(str, "j3and2"))
		return (FRACTOL_J3AND2);
	return (0);
}

static void	write_help(void)
{
	write(1, "You can use 1 parametr from list:", 34);
	write(1, " julia, mandelbrot, burningship,", 32);
	write(1, " m3, m4, m3and2, j3, j4, j3and2\n", 32);
	exit(0);
}

int			main(int argc, char **argv)
{
	t_global_variables	gv;
	t_draw_thread_param	pdtp[WINBUF_IMG_COUNT];

	if (argc != 2)
		write_help();
	load_default_values(&gv);
	if (!(gv.view.fractol_type = check_param(argv[1])))
		write_help();
	if ((gv.mlx.ptr = mlx_init()) == NULL)
		exit_program(&gv);
	if ((gv.mlx.win.ptr = mlx_new_window(gv.mlx.ptr, MAIN_WIN_WIDTH,
			MAIN_WIN_HEIGHT, MAIN_WIN_HEADER)) == NULL)
		exit_program(&gv);
	create_winbuf_img(&gv);
	create_winbuf_img_mutex(&gv);
	create_draw_threads(&pdtp[0], &gv);
	mlx_key_hook(gv.mlx.win.ptr, hook_keyup, &gv);
	mlx_mouse_hook(gv.mlx.win.ptr, hook_mouse, &gv);
	mlx_loop_hook(gv.mlx.ptr, hook_loop, &gv);
	mlx_do_key_autorepeaton(gv.mlx.ptr);
	mlx_hook(gv.mlx.win.ptr, 2, 0, hook_keydown, &gv);
	mlx_hook(gv.mlx.win.ptr, 17, 0, hook_wndexit, &gv);
	mlx_hook(gv.mlx.win.ptr, 6, 0, move_hook, &gv);
	mlx_loop(gv.mlx.ptr);
	exit_program(&gv);
}
