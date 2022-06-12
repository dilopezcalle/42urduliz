/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 13:04:51 by dilopez-          #+#    #+#             */
/*   Updated: 2022/06/12 08:42:02 by dilopez-         ###   ########.fr       */
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

#include <errno.h>

typedef struct s_data
{
	char			*path;
	char			**flags;
	struct s_data	*next;
}	t_data;

void	ft_pipex(int argc, char *argv[], char *envp[]);
void	ft_exit_program(t_data *command_list, int status);
void	ft_print_list(t_data *command_list);

// utils
char	**ft_get_paths(char **paths);
int		ft_check_list(int argc, char *argv[], t_data *command_list);

// create_list
t_data	*ft_create_list(int argc, char *argv[], char **paths);
char	*ft_get_command_path(char *command, char **paths);
void	ft_lstadd(t_data **lst, t_data *new);

// create_pipe
void	ft_create_pipe(t_data *command_list, char *argv[], int argc, char *envp[]);
void	ft_execute_first_child(char *infile, int fd[2], t_data *command_list, char *envp[]);
void	ft_execute_mid_child(int fd[2], t_data *command_list, int file, char *envp[]);
void	ft_execute_parent(char *outfile, int fd[2], t_data *command_list, int pid, char *envp[]);

// ========== libft ==========
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);

void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	**ft_split(char const *s, char c);
char	*ft_split_check_chars(char const *s, char c, int row);
int		ft_split_check_rows(char const *s, char c);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
