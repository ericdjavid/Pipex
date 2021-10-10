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

void	ft_child_process(char **argv, char **envp, t_elems *elms)
{
	int	fd_in;

	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
		exit_perror("Error", elms);
	dup2(fd_in, 0);
	if (dup2(elms->fd[1], 1) < 0)
		exit_perror("Error with file descriptor", elms);
	close(elms->fd[0]);
	close(elms->fd[1]);
	execute(envp, argv[2], elms);
}

void	ft_child2_process(char **argv, char **envp, t_elems *elms)
{
	int	fd_out;

	fd_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 00664);
	if (fd_out == -1)
		exit_perror("Error : ", elms);
	dup2(fd_out, 1);
	dup2(elms->fd[0], 0);
	close(elms->fd[0]);
	close(elms->fd[1]);
	execute(envp, argv[3], elms);
}

int	ft_pipex(char **argv, char **envp, t_elems *elm)
{
	pid_t	child1;
	pid_t	child2;
	int		status;

	if (pipe(elm->fd) == -1)
		error_deal(errno);
	child1 = fork();
	if (child1 == -1)
		error_deal(errno);
	if (child1 == 0)
		ft_child_process(argv, envp, elm);
	child2 = fork();
	if (child2 == -1)
		error_deal(errno);
	if (child2 == 0)
		ft_child2_process(argv, envp, elm);
	close(elm->fd[0]);
	close(elm->fd[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_elems	elm;

	if (argc != 5)
		error_deal(EINVAL);
	ft_pipex(argv, envp, &elm);
	return (0);
}
