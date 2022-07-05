# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 12:54:12 by dilopez-          #+#    #+#              #
#    Updated: 2022/07/05 12:41:52 by dilopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ========== VARIABLES ==========
NAME			=	so_long
NAME_BONUS		=	so_long_bonus
DIR_OBJS 		=	objs/
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra -g
LINKS			=	-L . -lmlx -framework OpenGL -framework AppKit

SRCS			=	so_long.c									\
					srcs/get_next_line/get_next_line.c			\
					srcs/get_next_line/get_next_line_utils.c	\
					srcs/libft/ft_memset.c						\
					srcs/libft/ft_split.c						\
					srcs/ft_sprite.c							\
					srcs/ft_hook.c								\
					srcs/ft_map.c								\

SRCS_BONUS		=	so_long_bonus.c								\
					srcs/get_next_line/get_next_line_utils.c	\
					srcs/get_next_line/get_next_line.c			\
					srcs/so_long_bonus_utils.c					\
					srcs/libft/ft_memset.c						\
					srcs/ft_sprite_bonus.c						\
					srcs/libft/ft_split.c						\
					srcs/libft/ft_itoa.c						\
					srcs/ft_hook_bonus.c						\
					srcs/ft_map.c								\

OBJS			=	$(SRCS:.c=.o)
PREFIXED		=	$(addprefix $(DIR_OBJS), $(OBJS))
OBJS_BONUS		=	$(SRCS_BONUS:.c=.o)
PREFIXED_BONUS	=	$(addprefix $(DIR_OBJS), $(OBJS_BONUS))

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

$(DIR_OBJS)%.o : %.c
	@mkdir -p $(DIR_OBJS)/srcs/get_next_line $(DIR_OBJS)/srcs/libft
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
	@rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

bonus: print $(PREFIXED_BONUS)
	@echo "\n$(YELLOW)------------- Compiling minilibx -------------$(RESET)\n"
	@$(MAKE) -C ./minilibx
	@cp ./minilibx/libmlx.a .
	@$(CC) $(CFLAGS) $(LINKS) -o $(NAME_BONUS) $(PREFIXED_BONUS)
	@echo "\n${GREEN}------------ Bonus part compiled! ------------${RESET}\n"

.PHONY: all clean fclean re print bonus