/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:54:22 by dilopez-          #+#    #+#             */
/*   Updated: 2022/07/02 11:06:32 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "srcs/get_next_line/get_next_line.h"
# include "minilibx/mlx.h"
# include <sys/errno.h>
# include <stdio.h>

// --------- so_long ----------
typedef struct s_map
{
	char		**ber;
	int			width;
	int			height;
}				t_map;

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_window
{
	void		*reference;
	t_position	size;
}				t_window;

typedef struct s_sprite
{
	void		*reference;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
	t_position	size;
}				t_sprite;

typedef struct s_program
{
	void		*mlx;
	t_map		*map;
	t_window	window;
	t_sprite	wall;
	t_sprite	floor;
	t_sprite	coin;
	t_sprite	exit;
	t_sprite	sprite;
	t_position	sprite_position;
	int			movements;
	int			coins;
}				t_program;

void			ft_so_long(char *map);
int				ft_exit_program(void *param);
void			ft_exit_program_error(char *str);
void			ft_print_perror(char *str, int code);

// sprites
void			ft_put_sprites(t_program *program);
void			ft_create_sprite(t_program *program, t_sprite *sprite,
					char *path);
void			ft_put_chars_sprites(t_program *program, int x, int y);

// hooks
int				ft_press_key(int key, void *param);
void			ft_upgrade_sprites(t_program *program, int x, int y);

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