/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:19:57 by dilopez-          #+#    #+#             */
/*   Updated: 2022/06/09 09:26:28 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h> // exit
/*
void	ft_pipex(argv, envp)
{
	
}
*/
int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	int		pid;
	int		file;
	int		out;
	int		stt;
	char	*buff = calloc(100, 1);
	char	*array[] = {"ls", "-l", 0};
	char	*array2[] = {"wc", "-l", 0};

	pipe(fd);
	pid = fork();
	printf("fd[0]: %d\n", fd[0]);
	printf("fd[1]: %d\n", fd[1]);

	if (!pid)
	{
		// hijo
		printf("Entra al hijo\n");
		
		file = open("infile", O_RDONLY);

		dup2(fd[1], 1);
		close(fd[0]);
		dup2(file, 0);
		
		close(fd[1]);
		close(file);
		execve("/bin/ls", array, envp);
	}
	else
	{
		// padre
		printf("Entra al padre\n");
		waitpid(pid, NULL, 0);
		printf("Espera al hijo\n");

		out = open("outfile", O_WRONLY);
		close(fd[1]);
		dup2(fd[0], 0);
		dup2(out, 1);

		close(fd[0]);
		execve("/usr/bin/wc", array2, envp);

		exit(0);
	}
	free(buff);
	return 0;
}
