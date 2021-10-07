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

void ft_child_process(char **argv, char **envp, t_elems *elms)
{
	//CHILD 1
	int fd_in;

	fd_in = open(argv[1], O_RDONLY);
	dup2(fd_in, 0); //we read file and STDIN
	if(dup2(elms->fd[1], 1) < 0)// result of cmd 1 is written to STDIN
		exit_perror("Error with file descriptor", elms);
	close(elms->fd[0]);
	close(elms->fd[1]);
	execute(envp, argv[2], elms);

	//execlp("ls", "-la", NULL);

}

void ft_child2_process(char **argv, char **envp, t_elems *elms)
{
	//CHILD 2
	int fd_out;

	fd_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 00664);
	dup2(fd_out, 1);
	dup2(elms->fd[0], 0); // send cmd1 output to cmd2 (STDIN)
	close(elms->fd[0]);
	close(elms->fd[1]);
	execute(envp, argv[3], elms);

}
int ft_pipex(char **argv, char **envp, t_elems *elm)
{
	pid_t 	child1;
	pid_t 	child2;
	int 	status;

	if (pipe(elm->fd) == -1)
		error_deal(errno);
	child1 = fork();
	if (child1 == - 1)
		error_deal(errno);
	if (child1 == 0)
	{
		printf("child\n");
		ft_child_process(argv, envp, elm);
	}
	child2 = fork();
	if (child2 == - 1)
		error_deal(errno);
	if (child2 == 0)
	{
		printf("child2\n");
		ft_child2_process(argv, envp, elm);
	}
	close(elm->fd[0]);
	close(elm->fd[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	//TODO get arguments and convert them
	//TODO deal with basic errors
	t_elems elm;

	//elm.whole_cmd = NULL;
	if (argc != 5)
		error_deal(EINVAL);
	ft_pipex(argv, envp, &elm);
	return (0);
}