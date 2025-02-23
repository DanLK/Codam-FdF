NAME = fdf
NAME_PRACTICE = practice
NAME_TEST = test
SRC = input.c memory_clears.c init_points.c init_points_utils.c \
	paint.c lines.c color.c color_utils.c utils.c debug.c debug_utils.c
SRC_MAIN = fdf.c

SRC_DIR = ./src
OBJ_DIR = ./obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJ_MAIN = $(SRC_MAIN:%.c=$(OBJ_DIR)/%.o)

CFLAGS += -Wall -Werror -Wextra
LIBMLX = ./MLX42

HEADERS = -I ./include -I $(LIBMLX)/include 
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -lpthread -lm
LIBFT_NAME = ./libft/libft.a
LIBFT_PATH = ./libft

all: libmlx $(NAME) 

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJ) $(OBJ_MAIN) $(LIBFT_NAME)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_MAIN) $(LIBS) $(LIBFT_NAME) $(HEADERS) -lm

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT_NAME):
	$(MAKE) -C $(LIBFT_PATH)

clean:
	rm -f $(OBJ_MAIN)
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)
	rm -rf $(LIBMLX)/build
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re libmlx practice test