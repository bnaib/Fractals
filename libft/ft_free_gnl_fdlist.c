       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2019.10.07 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.20 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_free_gnl_fdlist(void *content, size_t content_size)
{
	if (content_size > 0)
	{
		free(((t_fdline *)content)->line);
		free((t_fdline *)content);
	}
}
