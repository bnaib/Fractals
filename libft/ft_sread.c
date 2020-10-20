       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2019.09.25 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include <unistd.h>
#include <string.h>

ssize_t		ft_sread(int fd, void *buf, ssize_t n)
{
	ssize_t		l;
	ssize_t		rr;

	l = 0;
	while (l < n && (rr = read(fd, buf + l, n - l)) > 0)
		l += rr;
	if (rr == -1)
		return (-1);
	return (l);
}
