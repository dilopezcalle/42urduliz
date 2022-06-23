# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 10:37:57 by dilopez-          #+#    #+#              #
#    Updated: 2022/06/12 11:21:18 by dilopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ========== VARIABLES ==========
NAME			=	pipex
DIR_OBJS 		=	objs/
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra


SRCS			=	pipex.c					\
					srcs/ft_pipex_utils.c	\
					srcs/ft_create_list.c	\
					srcs/ft_create_pipe.c	\
					srcs/libft/ft_strlen.c	\
					srcs/libft/ft_strchr.c	\
					srcs/libft/ft_memset.c	\
					srcs/libft/ft_calloc.c	\
					srcs/libft/ft_substr.c	\
					srcs/libft/ft_split.c	\
					srcs/libft/ft_strncmp.c	\
					srcs/libft/ft_strjoin.c	\

SRCS_BONUS		=	pipex_bonus.c			\
					srcs/ft_pipex_utils.c	\
					srcs/ft_create_list.c	\
					srcs/ft_create_pipe.c	\
					srcs/libft/ft_strlen.c	\
					srcs/libft/ft_strchr.c	\
					srcs/libft/ft_memset.c	\
					srcs/libft/ft_calloc.c	\
					srcs/libft/ft_substr.c	\
					srcs/libft/ft_split.c	\
					srcs/libft/ft_strncmp.c	\
					srcs/libft/ft_strjoin.c	\

OBJS			=	$(SRCS:.c=.o)
PREFIXED		=	$(addprefix $(DIR_OBJS), $(OBJS))
OBJS_BONUS		=	$(SRCS_BONUS:.c=.o)
PREFIXED_BONUS	=	$(addprefix $(DIR_OBJS), $(OBJS_BONUS))

ifneq (,$(findstring xterm,${TERM}))
	GREEN := $(shell tput -Txterm setaf 2)
	RESET := $(shell tput -Txterm sgr0)
else
	GREEN := ""
	RESET := ""
endif

# ========== RULES ==========

$(DIR_OBJS)%.o : %.c pipex.h
	@mkdir -p $(DIR_OBJS)/srcs/libft
	@echo "Compiling with $(CC) $(CFLAGS):\t $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(PREFIXED)
	@$(CC) $(CFLAGS) -o $(NAME) $(PREFIXED)
	@echo "${GREEN}Mandatory part compiled!${RESET}"

# ========== FUNCTIONS ==========

all: $(NAME)

clean:
	@rm -rf $(OBJS) $(DIR_OBJS)
	@echo "${GREEN}Cleaned!${RESET}"

fclean: clean
	@rm -rf $(NAME)

re: fclean all

bonus: $(PREFIXED_BONUS)
	@$(CC) $(CFLAGS) -o $(NAME) $(PREFIXED_BONUS)
	@echo "${GREEN}Bonus part compiled!${RESET}"

.PHONY: all clean fclean re
