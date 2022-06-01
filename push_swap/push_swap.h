/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:47:48 by dilopez-          #+#    #+#             */
/*   Updated: 2022/06/01 10:54:34 by dilopez-         ###   ########.fr       */
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
	int				index;
	struct s_list	*next;
}	t_list;

void		ft_push_swap(t_list *stack_a, t_list *stack_b, char **argv);
int			ft_issorted(t_list **stack_a);
void		ft_lst_index(t_list **stack_a);
int			ft_lstlen(t_list *stack_a);

// sorts
void		ft_sort_3(t_list **stack_a);
void		ft_sort_5(t_list **stack_a, t_list **stack_b);
void		ft_algorithm(t_list **stack_a, t_list **stack_b, int size);
int			ft_get_bits(int size);

void		ft_print_result(t_list *stack_a, t_list *stack_b);
void		ft_exit_program(t_list *stack_a, t_list *stack_b, int status);

// ft_get_int_list
t_list		*ft_get_int_list(char *argv[]);
int			ft_create_list(char *argv, t_list **stack_a, int i);
int			ft_check_alpha(char *str);
int			ft_add_list(t_list *stack_a, char *str, int index);
int			ft_check_repeat(t_list **stack_a, t_list *new, int num);

// swap
void		sa(t_list **stack_a);
void		sb(t_list **stack_b);
void		ss(t_list **stack_a, t_list **stack_b);

// push
void		pb(t_list **stack_a, t_list **stack_b);
void		pa(t_list **stack_a, t_list **stack_b);

// rotate
void		ra(t_list **stack_a);
void		rb(t_list **stack_b);
void		rr(t_list **stack_a, t_list **stack_b);

// reverse rotate
void		rra(t_list **stack_a);
void		rrb(t_list **stack_b);
void		rrr(t_list **stack_a, t_list **stack_b);

// ========== Libft functions ==========

size_t		ft_strlen(const char *s);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_calloc(size_t count, size_t size);
char		*ft_substr(char const *s, unsigned int start, size_t len);

char		**ft_split(char const *s, char c);
char		*ft_split_check_chars(char const *s, char c, int row);
int			ft_split_check_rows(char const *s, char c);

long int	ft_atoi(const char *str);
int			ft_isdigit(int c);

#endif
