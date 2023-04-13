NAME= fdf
SRC= fdf.c fdf_grid.c fdf_draw1.c fdf_draw2.c fdf_mvm.c fdf_color.c fdf_bonus.c fdf_bonus2.c
SRCPATH= ./cfiles/
OBJ= $(SRC:.c=.o)
OBJS= $(addprefix $(OBJPATH), $(OBJ))
SRCS= $(addprefix $(SRCPATH), $(SRC))
OBJPATH= ./ofiles/

CC= gcc -Wall -Wextra -Werror

all: makelib $(NAME)

makelib:
	make -C ./libft2
	make -C ./mlx_linux

%.o: $(SRCPATH)%.c
	$(CC) -I./hfiles -I./libft2 -I./mlx_linux -o $(OBJPATH)$@ -c $<

$(NAME): $(OBJ)
	$(CC) $(OBJS) -o $(NAME) -Llibft2 -lft -Lmlx_linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz -I./libft2 -I./mlx_linux -I./hfiles

clean:
	rm -f $(OBJS)
	make clean -C ./libft2
	make clean -C ./mlx_linux

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft2

re: fclean all
