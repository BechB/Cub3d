NAME    =   cub3d
SRCS    =   main.c \
            exec/window.c \
			exec/utils.c \
			exec/key_press.c \
			exec/mini_map.c \
			exec/img_treatment.c \
			exec/init_render.c \
			exec/init_render2.c \
			exec/draw_big_pixel.c \
			exec/render.c \
			parsing/init.c \
			parsing/parsing.c \
			parsing/get_map_file.c \
			parsing/get_map_file_utils.c \
			parsing/split_datas.c \
			parsing/map_checker.c \
			parsing/map_checker2.c \
			parsing/map_checker_utils.c \
			parsing/infos_checker.c \
			parsing/colors_checker.c \
			parsing/colors_checker_utils.c \
			parsing/special_frees.c \
			mini_libft/ft_isalnum.c \
			mini_libft/len_doubletab.c \
			mini_libft/ft_isalpha.c \
			mini_libft/ft_isdigit.c \
			mini_libft/ft_atoi.c \
			mini_libft/ft_memcpy.c \
			mini_libft/ft_putchar.c \
			mini_libft/ft_split.c \
			mini_libft/ft_strchr.c \
			mini_libft/ft_strdup.c \
			mini_libft/ft_strjoin_free.c \
			mini_libft/ft_strlen.c \
			mini_libft/ft_strlen_dtab.c \
			mini_libft/ft_strncmp.c \
			mini_libft/ft_strnstr.c \
			mini_libft/ft_strtrim.c \
			mini_libft/ft_substr.c \
			mini_libft/get_next_line.c \
			mini_libft/get_next_line_utils.c \
			mini_libft/ft_strjoin.c \
			mini_libft/handle_int_limit.c \

OBJS     =   $(SRCS:.c=.o)
CC      = gcc 
MINILIBX_DIR = ./mlx/
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx_Linux.a
CFLAGS = -Wall -Wextra  -Werror -I$(MINILIBX_DIR) -Iinclude -lm -g

${MAIN_PATH}%.o:%.c
	@${CC} ${CFLAGS} -c -I . $< -o ${<:.c=.o} -Iinclude -I./mlx/

all: $(NAME)

$(NAME): $(OBJS)
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME} -L${MINILIBX_DIR} -lmlx_Linux -lXext -lX11 -lm -lz
	@echo "Archivage terminé [cub3d]"

clean:
	@rm -f $(OBJS)
	@echo "Suppression des .o"

fclean: clean
	@rm -f $(OBJS) $(NAME)
	@echo "Suppression du .a effectuée"

re: fclean all

.PHONY : all clean fclean re
