# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 17:58:00 by nechaara          #+#    #+#              #
#    Updated: 2023/11/24 18:03:11 by nechaara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I .

SRCS = ft_printf_format.c ft_printf_hex.c ft_printf_lenght.c \
	ft_printf_num.c ft_printf_ptr_hex.c ft_printf_strings.c \
	ft_printf_unsigned_num.c ft_printf.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
