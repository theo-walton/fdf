
NAME = fdf

SRC = \
	$(addprefix src/, \
\
	main.c \
	normalize_string.c \
	add_initial_conditions.c \
	key_release_hooks.c \
	key_press_hooks.c \
	loop_hooks.c \
	close_and_ret.c \
	draw_line.c \
	get_center.c \
	draw_map.c \
	colourfun.c \
	rotate_map.c \
	rotate_coor.c \
	rotate_coor_origin.c \
	get_map.c \
	get_screen_size.c \
	is_valid.c \
	make_map_fit_screen.c \
	line_draw.c \
	set_hooks.c \
	set_colour_based_on_height.c \
	) \
\
	$(addprefix libft/, \
\
	ft_atoi.c \
	ft_replacewhitespace.c \
	ft_memmove.c \
	ft_memalloc.c \
	ft_isspace.c \
	ft_chrcount.c \
	ft_hextoi.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putchar_fd.c \
	ft_putstr.c \
	ft_isdigit.c \
	ft_putstr_fd.c \
	ft_strchr.c \
	ft_strlen.c \
	get_next_line.c \
	ft_securejoin.c \
	ft_shortenstr.c \
	ft_strdup.c \
	ft_strnew.c \
	ft_bzero.c \
	ft_strjoin.c \
	ft_memset.c \
	) \
\

.PHONY: all clean fclean re

OBJ =  \
	$(addprefix obj/, \
\
	main.o \
	normalize_string.o \
	add_initial_conditions.o \
	key_release_hooks.o \
	key_press_hooks.o \
	loop_hooks.o \
	close_and_ret.o \
	draw_line.o \
	get_center.o \
	draw_map.o \
	colourfun.o \
	rotate_map.o \
	rotate_coor.o \
	rotate_coor_origin.o \
	get_map.o \
	get_screen_size.o \
	is_valid.o \
	make_map_fit_screen.o \
	line_draw.o \
	set_hooks.o \
	set_colour_based_on_height.o \
	ft_atoi.o \
	ft_replacewhitespace.o \
	ft_memmove.o \
	ft_memalloc.o \
	ft_isspace.o \
	ft_chrcount.o \
	ft_hextoi.o \
	ft_putnbr.o \
	ft_putnbr_fd.o \
	ft_putchar_fd.o \
	ft_putstr.o \
	ft_isdigit.o \
	ft_putstr_fd.o \
	ft_strchr.o \
	ft_strlen.o \
	get_next_line.o \
	ft_securejoin.o \
	ft_shortenstr.o \
	ft_strdup.o \
	ft_strnew.o \
	ft_bzero.o \
	ft_strjoin.o \
	ft_memset.o \
	) \
\

FLAGS = -Wall -Wextra -Werror

INC = -I ./minilibx -I ./includes -I ./libft/includes

PATH = minilibx -lmlx -framework OpenGL -framework AppKit

MLBX = minilibx/libmlx.a

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC) $(INC)
	/bin/mv *.o obj
	gcc $(FLAGS) -L $(PATH) $(OBJ) $(MLBX) -o $(NAME)

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
