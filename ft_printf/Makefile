# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/08 12:22:53 by dilopez-          #+#    #+#              #
#    Updated: 2022/05/13 17:01:45 by dilopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ========== VARIABLES ==========
NAME				=	libftprintf.a
DIR_OBJ 			=	Objs/
CC					=	clang
CFLAGS				=	-Wall -Werror -Wextra

SRC					=	ft_printf.c	\
						Utils/ft_putchar.c	\
						Utils/ft_putstr.c		\
						Utils/ft_putnull.c	\

OBJ					=	$(SRC:.c=.o)
OBJECTS_PREFIXED 	=	$(addprefix $(DIR_OBJ), $(OBJ))

ifneq (,$(findstring xterm,${TERM}))
	GREEN := $(shell tput -Txterm setaf 2)
	RESET := $(shell tput -Txterm sgr0)
else
	GREEN := ""
	RESET := ""
endif

# ========== RULES ==========

$(DIR_OBJ)%.o : %.c ft_printf.h
	@mkdir -p $(DIR_OBJ)
	@echo "Compiling: $<"
	@clang $(CC_FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	@ar csr $(NAME) $(OBJ)
	@echo "${GREEN}Mandatory part compiled!${RESET}"

# ========== FUNCTIONS ==========

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo "${GREEN}Cleaned!${RESET}"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
