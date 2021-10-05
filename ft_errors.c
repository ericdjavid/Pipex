/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <e.djavid@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:24:16 by edjavid           #+#    #+#             */
/*   Updated: 2021/10/04 16:24:17 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
//TODO TREAT FREES

int	error_deal(int the_errno)
{
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(strerror(the_errno), 2);
	ft_putchar_fd('\n', 2);
	//ft_exit(all, 1);
	exit(EXIT_FAILURE);
}


int	ft_matr_del_and_free(char ***matrix)
{
	int	i;

	i = -1;
	if (!(*matrix))
		return (0);
	while ((*matrix)[++i])
	{
		free((*matrix)[i]);
		(*matrix)[i] = NULL;
	}
	free(*matrix);
	*matrix = NULL;
	return (0);
}

int	exit_perror(char *s, t_elems *elms)
{
	perror(s);
//	ft_matr_del_and_free();
	exit(EXIT_FAILURE);
}