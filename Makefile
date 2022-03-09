# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 12:19:50 by eelmoham          #+#    #+#              #
#    Updated: 2022/02/24 20:45:23 by eelmoham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap

CHECKER= checker

GNL_FILES=	./chckr/get_next_line/get_next_line.c \
			./chckr/get_next_line/get_next_line_utils.c \

GNL_HEADER=	./chckr/get_next_line/get_next_line.h

HEADER= push_swap.h \

CC= gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = 	push_swap.c \
		push_swap_func.c \
		sort.c \
		rotate.c \
		push.c \
		swap.c \
		reverse.c \
		libft_func.c \
		libft_func_lst.c \
		libft_lst_func2.c \
		index_sort.c

SRCS_CHECKER = 	./chckr/checker.c \
				./chckr/rotate_checker.c \
				./chckr/push_checker.c \
				./chckr/swap_checker.c \
				./chckr/reverse_checker.c \
				./chckr/libft_func_checker.c \
				./chckr/libft_func_lst_checker.c \
				./chckr/libft_lst_func2_checker.c \
				./chckr/checker_func.c
		
OBJS = $(SRCS:.c=.o)
OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)

all: $(NAME)
	@echo "\033[30;1m---> \033[0m PUSH_SWAP  \033[32;1m [OK] \033[0m"
%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)  $(HEADER) 
	@$(CC) $(CFLAGS)  $(OBJS) -o $(NAME)

$(CHECKER): $(OBJS_CHECKER)  $(HEADER) $(GNL_HEADER)
	@$(CC) $(CFLAGS) $(GNL_FILES)  $(OBJS_CHECKER) -o $(CHECKER)
	@echo "\033[30;1m---> \033[0m CHECKER    \033[32;1m [OK] \033[0m"

clean:
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_CHECKER)
	@echo "\033[30;1m---> \033[0m CLEAN      \033[32;1m [OK] \033[0m"


fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(CHECKER)
re: fclean all

.PHONY: all clean fclean re