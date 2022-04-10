# ========== VARIABLES ==========
NAME	= ./libft.a
CFLAGS	= -Wall -Werror -Wextra
SRC		= ./ft_isalpha.c	\
		  ./ft_isdigit.c	\
		  ./ft_isalnum.c	\
		  ./ft_isascii.c	\
		  ./ft_isprint.c	\
		  ./ft_strlen.c		\
		  ./ft_memset.c		\
		  ./ft_bzero.c		\
		  ./ft_memcpy.c		\
		  ./ft_memmove.c	\
		  ./ft_strlcpy.c	\
		  ./ft_strlcat.c	\
		  ./ft_toupper.c	\
		  ./ft_tolower.c	\
		  ./ft_strchr.c		\
		  ./ft_strrchr.c	\
		  ./ft_strncmp.c	\
		  ./ft_memchr.c		\
		  ./ft_memcmp.c		\
		  ./ft_strnstr.c	\
		  ./ft_atoi.c		\
		  ./ft_calloc.c		\
		  ./ft_strdup.c		\

OBJ		= $(SRC:.c=.o)

# ========== RULES ==========

$(NAME) : $(OBJ)
	ar -csr $(NAME) $(OBJ)

# ========== FUNCTIONS ==========

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
