/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:47:48 by dilopez-          #+#    #+#             */
/*   Updated: 2022/05/22 16:07:27 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define FT_PRINTF_H

// ========== Includes ==========

# include <stdio.h>
# include <stddef.h>

// ========== Prototypes ==========

typedef struct s_list
{
	int				number;
	struct s_list	*next;
}	t_list;

void	ft_exit_program(t_list *stack_a, t_list *stack_b, int error);

// ft_get_int_list
int		ft_get_int_list(char *argv[]);
int		ft_add_list(t_list *stack_a, char *str, int index);

// ========== Libft functions ==========

size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	**ft_split(char const *s, char c);
char	*ft_split_check_chars(char const *s, char c, int row);
int		ft_split_check_rows(char const *s, char c);

int		ft_atoi(const char *str);
int		ft_isdigit(int c);

#endif
