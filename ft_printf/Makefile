# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/08 12:22:53 by dilopez-          #+#    #+#              #
#    Updated: 2022/05/15 16:05:18 by dilopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ========== VARIABLES ==========
NAME			=	libftprintf.a
DIR_OBJS 		=	objs/
CC				=	clang
CFLAGS			=	-Wall -Werror -Wextra

SRCS			=	ft_printf.c				\
					utils/ft_putchar.c		\
					utils/ft_putstr.c		\
					utils/ft_putnull.c		\
					utils/ft_putnbr.c		\
					utils/ft_putunsigned.c	\
					utils/ft_putptr.c		\

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

$(DIR_OBJS)%.o : %.c ft_printf.h
	@mkdir -p $(DIR_OBJS)/utils
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

#out: re
#	gcc $(CFLAGS) libftprintf.a -o a.out

.PHONY: all clean fclean re
