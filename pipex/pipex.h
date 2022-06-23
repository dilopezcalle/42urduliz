/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 13:04:51 by dilopez-          #+#    #+#             */
/*   Updated: 2022/06/18 15:12:08 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>

typedef struct s_data
{
	char			*path;
	char			**flags;
	struct s_data	*next;
}	t_data;

void	ft_pipex(int argc, char *argv[], char *envp[]);
void	ft_exit_program(t_data *command_list, int status);
void	ft_print_perror(char *str, int code);

void	ft_print_list(t_data *command_list);

// utils
int		ft_check_infile(char *argv[]);
int		ft_check_outfile(int argc, char *argv[]);
char	**ft_get_paths(char **paths);
int		ft_check_list(int argc, t_data *command_list);

// create_list
t_data	*ft_create_list(int argc, char *argv[], char **paths);
char	*ft_get_command_path(char *command, char **paths);
void	ft_lstadd(t_data **lst, t_data *new);

// create_pipe
void	ft_create_pipe(t_data *command_list, char *argv[], int argc, \
						char *envp[]);
void	ft_execute_first_child(char *infile, int fd[2], t_data *command_list, \
								char *envp[]);
void	ft_execute_mid_child(char *outfile, int infile, t_data *command_list, \
								char *envp[]);
int		ft_create_mid_pipe(int infile, int fd[2], t_data *command_list, \
							char *envp[]);
void	ft_execute_last_child(char *outfile, int infile, t_data *command_list, \
								char *envp[]);

// ========== libft ==========
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);

void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	**ft_split(char const *s, char c);
int		ft_split_check_rows(char const *s, char c);
char	*ft_split_check_chars(char const *s, char c, int row);
char	*ft_split_generate_str(char const *s, char c, int i);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);

#endif