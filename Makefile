       # ******************************************************************** #
      #                                              _____ _   __            #
     #    By: Sergey Nikolaev                       / ___// | / /           #
    #    Сontacts: sn.prog@yandex.ru                \__ \/  |/ /           #
   #    Created: 2020.02.22 (YYYY.MM.DD)           ___/ / /|  /           #
  #    Updated: 2020.10.20 (YYYY.MM.DD)           /____/_/ |_/           #
 #                                                                      #
# ******************************************************************** #

NAME	= fractol
FLAGS	= -g
FLAGS1	= -Wall -Wextra -Werror

HFILES		=\
	fractol.h\
	global_variables.h

CFILES	=\
		main.c					hook_keydown.c			fill_winbuf.c\
		exit_program.c			hook_keyup.c			show_winbuf.c\
		load_default_values.c	hook_loop.c				show_fps.c\
		winbuf_img.c			hook_mouse.c			fill_julia.c\
		winbuf_img_mutex.c		hook_wndexit.c			fill_mandelbrot.c\
		draw_thread.c									fill_burningship.c\
		check_mkeys_zoom.c		move_hook.c\
		check_keys_show_steps.c\
		check_keys_move.c\
		\
		get_color_value.c\
		fill_m3.c				fill_j3.c\
		fill_m4.c				fill_j4.c\
		fill_m3and2.c			fill_j3and2.c

LIB_INC		=\
	-I/usr/local/include\
	-I./libft

LIB_BIN		=\
	-L/usr/local/lib -lmlx\
	-L./libft -lft

FW		= -framework OpenGL\
		  -framework AppKit

INC_DIR		= ./inc/
INC			= $(addprefix $(INC_DIR), $(HFILES))

SRC_DIR		= ./src/
SRC			= $(addprefix $(SRC_DIR), $(CFILES))

OBJ_DIR		= ./obj/
OFILES		= $(patsubst %.c, %.o, $(CFILES))
OBJ			= $(addprefix $(OBJ_DIR), $(OFILES))

.PHONY: all clean fclean re

all: checkDir $(NAME)

checkDir:
	if [ ! -d $(OBJ_DIR) ]; then mkdir $(OBJ_DIR); fi

$(NAME): $(OBJ) $(INC)
	make -C ./libft;
	gcc $(FLAGS) -I $(INC_DIR) $(LIB_INC) -o $(NAME) $(OBJ) $(LIB_BIN) $(FW);

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	gcc $(FLAGS) -I $(INC_DIR) $(LIB_INC) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all
