       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2019.10.01 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

int		ft_isdigit_base(int c, int base)
{
	if (base < 2 || base > 16)
		return (0);
	if (base <= 10)
		return (c >= '0' && c <= '0' - 1 + base);
	else
	{
		return ((c >= '0' && c <= '9')
			|| (c >= 'A' && c <= 'A' - 11 + base)
			|| (c >= 'a' && c <= 'a' - 11 + base));
	}
}
