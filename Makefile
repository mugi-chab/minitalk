# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 11:01:06 by svillalv          #+#    #+#              #
#    Updated: 2022/09/22 14:39:53 by svillalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NORMI = norminette .
COLOR = \033[1;32m

NAME_S = server
NAME_C = client
NAME_S_B = server_bonus
NAME_C_B = client_bonus
LIBFT_FILE = print_libft/libft.a

SRC_S = server.c
SRC_C = client.c
SRC_S_B = server_bonus.c
SRC_C_B = client_bonus.c
SRC_LIBFT = ./print_libft

all: libft $(NAME_S) $(NAME_C)

libft:
	@$(MAKE) -C print_libft/
	@echo "$(COLOR)Libft compiled successfully\n"

$(NAME_S): $(SRC_S)
	@$(CC) $(CFLAGS) ${LIBFT_FILE} -o $@ $(SRC_S)
	@echo "$(COLOR)Server compiled successfully\n"

$(NAME_C): $(SRC_C)
	@$(CC) $(CFLAGS) ${LIBFT_FILE} -o $@ $(SRC_C)
	@echo "$(COLOR)Client compiled successfully\n"

$(NAME_S_B): $(SRC_S_B)
	@$(CC) $(CFLAGS) ${LIBFT_FILE} -o $@ $(SRC_S_B)
	@echo "$(COLOR)Bonus server compiled successfully\n"

$(NAME_C_B): $(SRC_C_B)
	@$(CC) $(CFLAGS) ${LIBFT_FILE} -o $@ $(SRC_C_B)
	@echo "$(COLOR)Bonus client compiled successfully\n"

bonus: libft $(NAME_S_B) $(NAME_C_B)

clean:
	@ $(MAKE) clean -sC $(SRC_LIBFT)

fclean: clean
	@ $(MAKE) fclean -sC $(SRC_LIBFT)
	@rm -f $(NAME_S) $(NAME_C) $(NAME_S_B) $(NAME_C_B)

re: fclean all

.PHONY: all clean re fclean libft
	