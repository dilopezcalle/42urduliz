# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 12:54:12 by dilopez-          #+#    #+#              #
#    Updated: 2022/06/27 16:17:28 by dilopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ========== VARIABLES ==========
NAME			=	so_long.a
DIR_OBJS 		=	objs/
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra -g
LINKS			=	-L . -lmlx -framework OpenGL -framework AppKit

SRCS			=	so_long.c									\
					srcs/ft_map.c								\
					srcs/libft/ft_memset.c						\
					srcs/libft/ft_split.c						\
					srcs/get_next_line/get_next_line.c			\
					srcs/get_next_line/get_next_line_utils.c	\

OBJS			=	$(SRCS:.c=.o)
PREFIXED		=	$(addprefix $(DIR_OBJS), $(OBJS))

GREEN			=	"\\x1b[32m"
RED				=	"\\x1b[31m"
YELLOW			=	"\\x1b[33m"
RESET			=	"\\x1b[37m"

# ========== RULES ==========

$(NAME) : print $(PREFIXED)
	@echo "\n$(YELLOW)------------- Compiling minilibx -------------$(RESET)\n"
	@$(MAKE) -C ./minilibx
	@cp ./minilibx/libmlx.a .
	@$(CC) $(CFLAGS) $(LINKS) -o $(NAME) $(PREFIXED)
	@echo "\n${GREEN}---------- Mandatory part compiled! ----------${RESET}\n"

$(DIR_OBJS)%.o : %.c so_long.h
	@mkdir -p $(DIR_OBJS)/srcs/libft $(DIR_OBJS)/srcs/get_next_line
	@echo "Compiling with $(CC) $(CFLAGS):\t $<"
	@$(CC) $(CFLAGS) -c $< -o $@


# ========== FUNCTIONS ==========

print:
	@echo "\n$(YELLOW)---------- Compiling project's files ---------$(RESET)\n"

all: $(NAME)

clean:
	@$(MAKE) -C ./minilibx clean
	@rm -rf $(OBJS) $(DIR_OBJS) so_long.a.dSYM
	@echo "\n${GREEN}------------------ Cleaned! ------------------${RESET}\n"

fclean: clean
	@$(RM) libmlx.a
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re print