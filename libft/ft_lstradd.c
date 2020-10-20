       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2019.09.26 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "libft.h"

void	ft_lstradd(t_list **lst, t_list *n)
{
	t_list	*ptr;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = n;
		return ;
	}
	ptr = *lst;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = n;
}
