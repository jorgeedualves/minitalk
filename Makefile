CLIENT = client
SERVER = server

SOURCE_DIR = src

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = includes
INCLUDES = $(addprefix -I, $(INCLUDES))

CC = clang
CFLAGS = -Wall -Wextra -Werror
POSIX_FLAGS = -D_POSIX_C_SOURCE=199309L
RM = rm -f

LIBFLAGS = -L$(LIBFT_DIR) -lft

all: $(LIBFT) $(CLIENT) $(SERVER)

bonus: all

%: $(SOURCE_DIR)/%.c
	$(CC) $(CFLAGS) $(POSIX_FLAGS) $< $(INCLUDES) $(LIBFLAGS) -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

run: re
	./$(SERVER)

clean:
	make -C $(LIBFT_DIR) fclean
	$(RM) $(CLIENT) $(SERVER)

fclean: clean

re: fclean all

.PHONY: all fclean re bonus