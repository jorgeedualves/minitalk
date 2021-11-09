NAME = minitalk

LIBFT_DIR = libraries/libft
LIBFT = $(LIBFT_DIR)/libft.a

RM = rum -rf

SRC_DIR = src

OBJ = obj

HEADERS = src/minitalk.h

INCLUDE_DIR = includes

SRC_FILES = client.c serve.c

SRC = $(addprefix $(SRC_DIR)/%.c=$(OBJ_DIR/%.o))

CC = clang
CFLAGS = -Wall -Wextra -Werror

LIBFLAGS = -lft

all: $(NAME)

$(NAME): $(OBJ_BONUS_DIR) $(LIBFT) $(OBJ)
	$(CC) $(OBJ) -L$(LIBFT_DIR) $(LIBFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c -I$(LIBFT_DIR) $(INCLUDE_DIR) -o $@ $<

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

run:
	./$(NAME)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus