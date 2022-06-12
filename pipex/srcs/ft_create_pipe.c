/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:55:11 by dilopez-          #+#    #+#             */
/*   Updated: 2022/06/12 09:29:15 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_create_pipe(t_data *command_list, char *argv[], int argc, char *envp[])
{
	int	file;
	int	fd[1];
	int	pid;
	int	i;

	i = 0;
	if (pipe(fd) == -1)
	{
		perror("pipe");
		ft_exit_program(command_list, errno);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		ft_exit_program(command_list, errno);
	}
	if (!pid)
	{
		while (i < argc - 3)
		{
			pid = fork();
			
			if (i == 0 && !pid)
				ft_execute_first_child(argv[0], fd, command_list, envp);
			else if (!pid)
			{
				command_list = command_list->next;
				/*
				dup2(file, fd[1]);
				close(fd[1]);
				ft_execute_mid_child(fd, command_list, file, envp);
				*/
			}
			i++;
		}
	}
	else
		ft_execute_parent(argv[argc - 1], fd, command_list, pid, envp);
}

void	ft_execute_first_child(char *infile, int fd[2], t_data *command_list, \
		char *envp[])
{
	int	file;
/*
	printf("fd[0]1: %d\n", fd[0]);
	printf("fd[1]1: %d\n", fd[1]);
*/
	close(fd[0]);
	file = open("infile", O_RDONLY);
	dup2(fd[1], 1);
	dup2(file, 0);
	close(fd[1]);
	close(file);
	execve(command_list->path, command_list->flags, envp);
}

void	ft_execute_mid_child(int fd[2], t_data *command_list, int file, \
		char *envp[])
{
	int	pid;
/*
	printf("fd[0] mid: %d\n", fd[0]);
	printf("fd[1] mid: %d\n", fd[1]);
*/
	pid = fork();	

	if (!pid)
	{
		printf("file mid: %d\n", file);
		close(fd[0]);
		dup2(file, 0);
		dup2(fd[1], 1);
		close(fd[1]);		
		close(file);
		execve(command_list->path, command_list->flags, envp);
		exit(0);
	}
}

void	ft_execute_parent(char *outfile, int fd[2], t_data *command_list, \
		int pid, char *envp[])
{
	int	file;
	int	i;
	
	i = 0;
	close(fd[1]);
	wait(NULL);
/*
	printf("fd[0]l: %d\n", fd[0]);
	printf("fd[1]l: %d\n", fd[1]);
*/
	while (command_list->next != 0)
		command_list = command_list->next;
	file = open(outfile, O_WRONLY);
	dup2(fd[0], 0);
	dup2(file, 1);
	close(fd[0]);
	execve(command_list->path, command_list->flags, envp);
	exit(0);
}
