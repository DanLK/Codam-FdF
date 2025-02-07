NAME = fdf
NAME_PRACTICE = practice
SRC = input.c
SRC_MAIN = fdf.c
SRC_PRACTICE = practice.c

SRC_DIR = ./src
OBJ_DIR = ./obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJ_MAIN = $(SRC_MAIN:%.c=$(OBJ_DIR)/%.o)
OBJ_PRACTICE = $(SRC_PRACTICE:%.c=$(OBJ_DIR)/%.o)

CFLAGS += -Wall -Werror -Wextra
LIBMLX = ./MLX42

HEADERS = -I ./include -I $(LIBMLX)/include 
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -lpthread -lm
LIBFT_NAME = ./libft/libft.a
LIBFT_PATH = ./libft

all: libmlx $(NAME) 

practice: libmlx $(NAME_PRACTICE)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJ) $(OBJ_MAIN) $(LIBFT_NAME)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_MAIN) $(LIBS) $(LIBFT_NAME) $(HEADERS)

$(NAME_PRACTICE): $(OBJ) $(OBJ_PRACTICE) $(LIBFT_NAME)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_PRACTICE) $(LIBS) $(LIBFT_NAME) $(HEADERS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT_NAME):
	$(MAKE) -C $(LIBFT_PATH)

clean:
	rm -f $(OBJ_MAIN)
	rm -f $(OBJ_PRACTICE)
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)
	rm -rf $(LIBMLX)/build
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_PRACTICE)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: clean all

.PHONY: all clean fclean re libmlx practice