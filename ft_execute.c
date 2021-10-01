/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <e.djavid@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 00:50:00 by edjavid           #+#    #+#             */
/*   Updated: 2021/09/28 00:50:01 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

/*
PARSING
*/
void parsing(char *envp[], char **argv)
{
    char *paths;
    char **cut_paths;
    int size;

    size = ft_strlen(envp[10]);
    paths = ft_substr(envp[10], 5, size);
    cut_paths = ft_split(paths, ':');
    free(paths);

    int i = 0;
    while (cut_paths[i])
    {
        free(cut_paths[i]);
        i++;
    }
    free(cut_paths);
}
