# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/30 19:33:17 by fbonhomm          #+#    #+#              #
#    Updated: 2016/06/11 15:27:45 by flo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_strace

INC = ./inc/

INC_LIB = ./libft/

FLAG = -Werror -Wextra -Wall

SRC = ./src/main.c \
		./src/ft_arg.c \
		./src/ft_check.c \
		./src/ft_init.c \
		./src/ft_path.c \
		./src/ft_ptrace.c \
		./src/getdata.c \
		./src/print_strace.c \
		./src/ft_signal.c \
		./src/ft_open.c \
		./src/ft_read.c \
		./src/flags_open.c \
		./src/ft_mmap.c \
		./src/ft_mprotect.c \
		./src/flags_mmap1.c \
		./src/ft_access.c \
		./src/ft_write.c \
		./src/ft_clone.c \
		./src/sigpro.c \
		./src/print_start.c \
		./src/print_end.c \
		./src/error.c \
		./src/print_opt.c \
		./src/ft_ptrace_opt.c \

all: $(NAME)

$(NAME):
		@make -C libft
		@gcc $(FLAG) $(SRC) -I$(INC) -I$(INC_LIB) ./libft/libft.a -o $(NAME)

clean:
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
