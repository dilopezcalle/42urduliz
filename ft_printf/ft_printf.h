/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:25:36 by dilopez-          #+#    #+#             */
/*   Updated: 2022/05/11 16:14:48 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// ========== Includes ==========

# include <stdio.h>
# include <stdarg.h>

// ========== Prototypes ==========

int	ft_printf(char const *format, ...);

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnull(void);

#endif
