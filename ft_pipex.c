/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <e.djavid@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 22:00:58 by edjavid           #+#    #+#             */
/*   Updated: 2021/09/27 22:01:00 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int ft_pipex(int fd1, int fd2, char **argv, char **envp)
{
	int fd[2];
	int pid;

	//convert argv[2] and argv[3]
	pipe(fd);
	pid = fork();

	if (pid == 0)
	{
		//child process
		printf("child\n");
		execute(envp, argv);
	}
	else
	{
		//parent process
		wait(NULL);
		printf("parent\n");
	}

	return (1);
}

int main(int argc, char **argv, char **envp)
{
	//TODO get arguments and convert them
	//TODO deal with basic errors
	int fd1;
	int fd2;

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[4], O_CREAT | O_RDWR);
	if (fd2 == -1 | fd1 == -1)
	{
		printf("problem\n");
		return (-1);
	}

	ft_pipex(fd1, fd2, argv, envp);
	return (0);
}