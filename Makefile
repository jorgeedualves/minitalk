NAME =
CLIENT = client
SERVER = server

SRC_FILES = server.c client.c
SRC_DIR = src

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = includes
INCLUDES := $(addprefix -I, $(INCLUDES))

CC = clang
CFLAGS = -Wall -Wextra -Werror
POSIX_FLAGS = -D_POSIX_C_SOURCE=199309L
RM = rm -f

LIBFLAGS = -L$(LIBFT_DIR) -lft

all: $(LIBFT) $(CLIENT) $(SERVER)

$(NAME): all

bonus: all

%: $(SRC)/%.c
	$(CC) $(CFLAGS) $(POSIX_FLAGS) $< $(INCLUDES) $(LIBFLAGS) -o $@

client: $(SRC_DIR)/client.c $(LIBFT)
	$(CC) $(CFLAGS) $< $(INCLUDES) $(LIBFLAGS) -o $@

server: $(SRC_DIR)/server.c $(LIBFT)
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