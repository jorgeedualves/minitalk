# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/25 20:40:15 by joeduard          #+#    #+#              #
#    Updated: 2021/07/25 20:40:15 by joeduard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf_utils.c ft_printf_utils_2.c ft_printf_utils_3.c ft_printf_utils_4.c \
			ft_printf_utils_5.c ft_printf_utils_6.c ft_printf_utils_7.c ft_printf_utils_8.c \
			ft_printf.c print_c.c print_i_d.c print_p.c print_s.c print_u.c print_xX.c

SRC_BONUS = ft_printf_utils.c ft_printf_utils_2.c ft_printf_utils_3.c ft_printf_utils_4.c \
			ft_printf_utils_5.c ft_printf_utils_6.c ft_printf_utils_7.c ft_printf_utils_8.c \
			ft_printf.c print_c.c print_i_d.c print_p.c print_s.c print_u.c print_xX.c

OBJECTS = $(subst .c,.o,$(SRCS))

OBJECTS_BONUS = $(subst .c,.o,$(SRC_BONUS))

all: $(NAME)

$(NAME): $(SRCS)
	@clang -Wall -Wextra -Werror -c $(SRCS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

bonus: $(OBJECTS_BONUS)

$(OBJECTS_BONUS):
	@gcc -Wall -Wextra -Werror -c $(SRC_BONUS)
	@ar rc $(NAME) $(OBJECTS_BONUS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus
