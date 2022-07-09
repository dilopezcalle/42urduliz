# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 12:54:12 by dilopez-          #+#    #+#              #
#    Updated: 2022/07/09 08:51:24 by dilopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ========== VARIABLES ==========
NAME			=	philo
DIR_OBJS 		=	objs/
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra

SRCS			=	philo.c									\
					srcs/philo_utils.c						\
					srcs/ft_get_args.c						\
					srcs/ft_get_philos.c					\
					srcs/ft_philo_states.c					\

OBJS			=	$(SRCS:.c=.o)
PREFIXED		=	$(addprefix $(DIR_OBJS), $(OBJS))

GREEN			=	"\\x1b[32m"
RED				=	"\\x1b[31m"
YELLOW			=	"\\x1b[33m"
RESET			=	"\\x1b[37m"

# ========== RULES ==========

$(NAME) : print $(PREFIXED)
	@$(CC) $(CFLAGS) -o $(NAME) $(PREFIXED)
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
	@rm -rf $(OBJS) $(DIR_OBJS) philo.dSYM
	@echo "\n${GREEN}------------------ Cleaned! ------------------${RESET}\n"

fclean: clean
	@$(RM) libmlx.a
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re print bonus