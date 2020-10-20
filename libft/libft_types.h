       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2019.09.23 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#ifndef __LIBFT_TYPES_H
# define __LIBFT_TYPES_H
# include <string.h>

typedef struct	s_fdline
{
	int		fd;
	char	*line;
}				t_fdline;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

#endif
