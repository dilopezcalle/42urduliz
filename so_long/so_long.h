/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:54:22 by dilopez-          #+#    #+#             */
/*   Updated: 2022/07/01 17:27:22 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include "srcs/get_next_line/get_next_line.h"
# include <stdio.h>
# include <sys/errno.h>

// --------- so_long ----------
typedef struct s_map
{
	char		**ber;
	int			width;
	int			height;
}				t_map;

typedef struct s_vector
{
	int			x;
	int			y;
}				t_vector;

typedef struct s_window
{
	void		*reference;
	t_vector	size;
}				t_window;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
	int			a;
}				t_color;

typedef struct s_image
{
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_program
{
	void		*mlx;
	t_map		*map;
	t_window	window;
	t_image		sprite;
	t_vector	sprite_position;
	int			movements;
	int			coins;
}				t_program;

void			ft_so_long(char *map);
int				ft_exit_program(void);
void			ft_exit_program_error(char *str);
void			ft_print_perror(char *str, int code);

// sprites
void			ft_put_sprites(t_program *program);
void			ft_create_sprite(t_program *program, t_image *sprite,
					char *path);

// hooks
int				ft_press_key(int key, void *param);

// map
void			ft_get_map(t_program *program, char *ber);
int				ft_check_map(t_program *program);
int				ft_check_chars_map(char *row, int width, int pos_row);
void			ft_free_map(t_map **map);

// ---------- libft ----------
void			*ft_memset(void *b, int c, size_t len);

char			**ft_split(char const *s, char c);
char			*ft_split_check_chars(char const *s, char c, int row);
int				ft_split_check_rows(char const *s, char c);

#endif