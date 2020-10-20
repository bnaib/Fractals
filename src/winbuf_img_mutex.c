       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.02.22 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.20 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "fractol.h"

void	lock_winbuf_img_mutex(t_global_variables *pgv, int id)
{
	int		i;

	i = -1;
	while (++i < WINBUF_IMG_COUNT)
	{
		if (pthread_mutex_lock(&pgv->winbuf.img[i].mutex[id]))
			exit_program(pgv);
	}
}

void	unlock_winbuf_img_mutex(t_global_variables *pgv, int id)
{
	int		i;

	i = -1;
	while (++i < WINBUF_IMG_COUNT)
	{
		if (pthread_mutex_unlock(&pgv->winbuf.img[i].mutex[id]))
			exit_program(pgv);
	}
}

void	destroy_winbuf_img_mutex(t_global_variables *pgv, int id)
{
	int		i;

	i = -1;
	while (++i < WINBUF_IMG_COUNT)
	{
		if (pgv->winbuf.img[i].mutex_init[id])
			pthread_mutex_destroy(&pgv->winbuf.img[i].mutex[id]);
		if (pgv->winbuf.img[i].mattr_init[id])
			pthread_mutexattr_destroy(&pgv->winbuf.img[i].mattr[id]);
	}
}

void	create_winbuf_img_mutex(t_global_variables *pgv)
{
	int					i;
	int					i1;

	i = -1;
	while (++i < WINBUF_IMG_COUNT)
	{
		i1 = -1;
		while (++i1 < 2)
		{
			if ((pgv->winbuf.img[i].mattr_init[i1] =
				pthread_mutexattr_init(&pgv->winbuf.img[i].mattr[i1])))
				exit_program(pgv);
			else
				pgv->winbuf.img[i].mattr_init[i1] = 1;
			if ((pgv->winbuf.img[i].mutex_init[i1] = pthread_mutex_init(
				&pgv->winbuf.img[i].mutex[i1], &pgv->winbuf.img[i].mattr[i1])))
				exit_program(pgv);
			else
				pgv->winbuf.img[i].mutex_init[i1] = 1;
		}
	}
}
