# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 10:37:57 by dilopez-          #+#    #+#              #
#    Updated: 2022/05/26 15:49:20 by dilopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ========== VARIABLES ==========
NAME			=	push_swap.a
DIR_OBJS 		=	objs/
CC				=	clang
CFLAGS			=	-Wall -Werror -Wextra -g

SRCS			=	push_swap.c				\
					srcs/ft_get_int_list.c	\
					srcs/ft_exit_program.c	\
					srcs/ft_swap.c			\
					srcs/ft_push.c			\
					srcs/libft/ft_strlen.c	\
					srcs/libft/ft_memset.c	\
					srcs/libft/ft_calloc.c	\
					srcs/libft/ft_substr.c	\
					srcs/libft/ft_split.c	\
					srcs/libft/ft_atoi.c	\

OBJS			=	$(SRCS:.c=.o)
OBJS_PREFIXED	=	$(addprefix $(DIR_OBJS), $(OBJS))

ifneq (,$(findstring xterm,${TERM}))
	GREEN := $(shell tput -Txterm setaf 2)
	RESET := $(shell tput -Txterm sgr0)
else
	GREEN := ""
	RESET := ""
endif

# ========== RULES ==========

$(DIR_OBJS)%.o : %.c push_swap.h
	@mkdir -p $(DIR_OBJS)/srcs/libft
	@echo "Compiling with $(CC) $(CFLAGS):\t $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS_PREFIXED)
	@ar csr $(NAME) $(OBJS_PREFIXED)
	@echo "${GREEN}Mandatory part compiled!${RESET}"

# ========== FUNCTIONS ==========

all: $(NAME)

clean:
	@rm -rf $(OBJS) $(DIR_OBJS)
	@echo "${GREEN}Cleaned!${RESET}"

fclean: clean
	@rm -f $(NAME)

re: fclean all

out: all
	gcc -g $(CFLAGS) push_swap.a -o push_swap

.PHONY: all clean fclean re out
