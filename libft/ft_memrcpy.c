       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2019.09.15 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include <string.h>

void	*ft_memrcpy(void *dst, const void *src, size_t n)
{
	if (dst == src)
		return (dst);
	while (n--)
		((char *)dst)[n] = ((char *)src)[n];
	return (dst);
}
