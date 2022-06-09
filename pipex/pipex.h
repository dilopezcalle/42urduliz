/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 13:04:51 by dilopez-          #+#    #+#             */
/*   Updated: 2022/06/09 09:32:54 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* to write, read, close, access, pipe, dup, dup2, execve, fork */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

/* malloc, free, exit */
# include <stdlib.h>

/* open, unlink */
# include <fcntl.h>

/* waitpid, wait */
# include <sys/wait.h>

/* strerror */
# include <string.h>

/*to perror*/
# include <stdio.h>

typedef struct s_data
{
	char			*path;
	char			**flags;
	struct s_data	*next;
}	t_data;

// ========== libft ==========
size_t	ft_strlen(const char *s);

void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	**ft_split(char const *s, char c);
char	*ft_split_check_chars(char const *s, char c, int row);
int		ft_split_check_rows(char const *s, char c);

#endif
