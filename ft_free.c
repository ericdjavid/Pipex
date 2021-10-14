/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <e.djavid@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:32:38 by edjavid           #+#    #+#             */
/*   Updated: 2021/10/14 12:32:39 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	free_all(char *line_path, char **cmd, char **cut_paths)
{
	free(line_path);
	ft_matr_del_and_free(&cmd);
	ft_matr_del_and_free(&cut_paths);
}
