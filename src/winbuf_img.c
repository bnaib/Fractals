       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.02.22 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.20 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "fractol.h"

void	destroy_winbuf_img(t_global_variables *pgv)
{
	if (pgv->winbuf.img_ptr != NULL)
		mlx_destroy_image(pgv->mlx.ptr, pgv->winbuf.img_ptr);
}

void	create_winbuf_img(t_global_variables *pgv)
{
	int		i;

	pgv->winbuf.width = MAIN_WIN_WIDTH;
	while (pgv->winbuf.width % WINBUF_IMG_HCOUNT)
		pgv->winbuf.width++;
	pgv->winbuf.img_width = pgv->winbuf.width / WINBUF_IMG_HCOUNT;
	pgv->winbuf.height = MAIN_WIN_HEIGHT;
	while (pgv->winbuf.height % WINBUF_IMG_VCOUNT)
		pgv->winbuf.height++;
	pgv->winbuf.img_height = pgv->winbuf.height / WINBUF_IMG_VCOUNT;
	if ((pgv->winbuf.img_ptr = mlx_new_image(pgv->mlx.ptr,
		pgv->winbuf.width, pgv->winbuf.height)) == NULL)
		exit_program(pgv);
	if ((pgv->winbuf.img_data.ptr = mlx_get_data_addr(
		pgv->winbuf.img_ptr, &pgv->winbuf.img_data.bpp,
		&pgv->winbuf.img_data.sl,
		&pgv->winbuf.img_data.endian)) == NULL)
		exit_program(pgv);
	i = -1;
	while (++i < WINBUF_IMG_COUNT)
	{
		pgv->winbuf.img[i].x = i % WINBUF_IMG_HCOUNT * pgv->winbuf.img_width;
		pgv->winbuf.img[i].y = i / WINBUF_IMG_HCOUNT * pgv->winbuf.img_height;
	}
}
