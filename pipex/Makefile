# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 10:37:57 by dilopez-          #+#    #+#              #
#    Updated: 2022/06/05 12:19:47 by dilopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ========== VARIABLES ==========
NAME			=	pipex
DIR_OBJS 		=	objs/
CC				=	clang
CFLAGS			=	-Wall -Werror -Wextra -g

SRCS			=	pipex.c					\

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

$(DIR_OBJS)%.o : %.c pipex.h
	@mkdir -p $(DIR_OBJS)/srcs/libft
	@echo "Compiling with $(CC) $(CFLAGS):\t $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS_PREFIXED)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS_PREFIXED)
	@echo "${GREEN}Mandatory part compiled!${RESET}"

# ========== FUNCTIONS ==========

all: $(NAME)

clean:
	@rm -rf $(OBJS) $(DIR_OBJS)
	@echo "${GREEN}Cleaned!${RESET}"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
