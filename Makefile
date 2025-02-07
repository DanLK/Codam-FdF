NAME = fdf
SRC = practice.c
OBJ = $(SRC:.c=.o)
CFLAGS += -Wall -Werror -Wextra
LIBMLX = ./MLX42

HEADERS = -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -lpthread -lm



all: libmlx $(NAME) 

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBS) $(HEADERS)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	rm -rf $(LIBMLX)/build

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re libmlx