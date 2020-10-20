       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.02.22 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.20 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "fractol.h"

static char		*show_fps_get_str(int fps, int afps)
{
	char	*str[5];
	int		i;

	str[0] = ft_itoa(fps);
	str[1] = ft_itoa(afps);
	str[2] = NULL;
	if (str[0] != NULL)
		str[2] = ft_strjoin("FPS: ", str[0]);
	str[3] = NULL;
	if (str[2] != NULL)
		str[3] = ft_strjoin(str[2], " / ");
	str[4] = NULL;
	if (str[3] != NULL)
		str[4] = ft_strjoin(str[3], str[1]);
	i = -1;
	while (++i < 4)
	{
		if (str[i] != NULL)
			free(str[i]);
	}
	return (str[4]);
}

void			show_fps(t_global_variables *pgv)
{
	static time_t	t[3] = {0, 0, 0};
	static int		frames[2] = {0, 0};
	static int		fps[2] = {0, 0};
	char			*str;

	frames[0]++;
	frames[1]++;
	if (time(&t[2]) - t[1] >= AFPS_TIMEOUT)
	{
		fps[1] = frames[1] / (t[2] - t[1]);
		frames[1] = 0;
		t[1] = t[2];
	}
	if (t[2] - t[0] >= 1)
	{
		fps[0] = frames[0] / (t[2] - t[0]);
		frames[0] = 0;
		t[0] = t[2];
	}
	if (!pgv->info.fps)
		return ;
	str = show_fps_get_str(fps[0], fps[1]);
	mlx_string_put(pgv->mlx.ptr, pgv->mlx.win.ptr, 0, 0, 0xFFFFFF, str);
	free(str);
}
