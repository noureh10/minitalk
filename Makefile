# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 15:54:28 by nechaara          #+#    #+#              #
#    Updated: 2023/11/24 00:00:57 by nechaara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server
SRC_DIR = src
UTILS_DIR = $(SRC_DIR)/utils

BNAME_CLIENT = $(addsuffix _bonus, $(NAME_CLIENT))
BNAME_SERVER = $(addsuffix _bonus, $(NAME_SERVER))
BSRC_DIR = $(addsuffix _bonus, $(SRC_DIR))
BUTILS_DIR = $(BSRC_DIR)/utils

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): ft_printf
	@gcc -Iincludes -o $(NAME_CLIENT) $(SRC_DIR)/client.c $(UTILS_DIR)/utils_1.c $(UTILS_DIR)/utils_2.c -L./ft_printf -lftprintf

$(NAME_SERVER): ft_printf
	@gcc -Iincludes -o $(NAME_SERVER) $(SRC_DIR)/server.c $(UTILS_DIR)/utils_1.c $(UTILS_DIR)/utils_2.c -L./ft_printf -lftprintf

bonus: $(BNAME_CLIENT) $(BNAME_SERVER)

$(BNAME_CLIENT): ft_printf
	@gcc -Iincludes -o $(BNAME_CLIENT) $(BSRC_DIR)/client.c $(BUTILS_DIR)/utils_1.c $(BUTILS_DIR)/utils_2.c -L./ft_printf -lftprintf

$(BNAME_SERVER): ft_printf
	@gcc -Iincludes -o $(BNAME_SERVER) $(BSRC_DIR)/server.c $(BUTILS_DIR)/utils_1.c $(BUTILS_DIR)/utils_2.c -L./ft_printf -lftprintf

ft_printf:
	@make -C ft_printf

clean:
	@make -C ft_printf clean

fclean: clean
	@make -C ft_printf fclean
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@rm -f $(BNAME_CLIENT) $(BNAME_SERVER)

re: fclean all

.PHONY: all clean fclean re ft_printf

