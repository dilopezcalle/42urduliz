/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:55:11 by dilopez-          #+#    #+#             */
/*   Updated: 2022/06/15 13:02:18 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <unistd.h>
#include <fcntl.h>

void	ft_create_pipe(t_data *command_list, char *argv[], int argc, \
						char *envp[])
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
	{
		ft_print_perror("pipe", 32);
		ft_exit_program(command_list, 2);
	}
	pid = fork();
	if (pid == -1)
	{
		ft_print_perror("fork", 10);
		ft_exit_program(command_list, 2);
	}
	else if (!pid)
		ft_execute_first_child(argv[0], fd, command_list, envp);
	else
	{
		close(fd[1]);
		wait(NULL);
		ft_execute_mid_child(argv[argc - 1], fd[0], command_list, envp);
	}
}

void	ft_execute_first_child(char *infile, int fd[2], t_data *command_list, \
								char *envp[])
{
	int	file;

	close(fd[0]);
	file = open(infile, O_RDONLY);
	dup2(file, 0);
	dup2(fd[1], 1);
	close(fd[1]);
	close(file);
	execve(command_list->path, command_list->flags, envp);
	exit(0);
}

void	ft_execute_mid_child(char *outfile, int infile, t_data *command_list, \
								char *envp[])
{
	int	fd[2];

	if (pipe(fd) == -1)
	{
		ft_print_perror("pipe", 32);
		ft_exit_program(command_list, 2);
	}
	command_list = command_list->next;
	while (command_list != 0)
	{
		if (pipe(fd) == -1)
		{
			ft_print_perror("pipe", 32);
			ft_exit_program(command_list, 2);
		}
		if (command_list->next != 0)
			infile = ft_create_mid_pipe(infile, fd, command_list, envp);
		else
		{
			close(fd[1]);
			close(fd[0]);
			ft_execute_last_child(outfile, infile, command_list, envp);
		}
		command_list = command_list->next;
	}
}

int	ft_create_mid_pipe(int infile, int fd[2], t_data *command_list, \
						char *envp[])
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		ft_print_perror("fork", 10);
		ft_exit_program(command_list, 2);
	}
	else if (!pid)
	{
		close(fd[0]);
		dup2(infile, 0);
		dup2(fd[1], 1);
		close(fd[1]);
		close(infile);
		execve(command_list->path, command_list->flags, envp);
		exit(0);
	}
	else
	{
		close(fd[1]);
		infile = dup(fd[0]);
		close(fd[0]);
	}
	return (infile);
}

void	ft_execute_last_child(char *outfile, int infile, t_data *command_list, \
							char *envp[])
{	
	int	pid;
	int	file;

	pid = fork();
	if (pid == -1)
	{
		ft_print_perror("fork", 10);
		ft_exit_program(command_list, 2);
	}
	else if (!pid)
	{
		file = open(outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		dup2(infile, 0);
		dup2(file, 1);
		close(infile);
		close(file);
		execve(command_list->path, command_list->flags, envp);
		exit(0);
	}
}
