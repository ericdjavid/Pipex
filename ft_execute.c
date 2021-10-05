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

/*					PARSING
    Find good line of PATH in env var of OS
*/
int good_path_arr(char *str)
{
    if (str && str[0] == 'P' && str[1] == 'A' 
        && str[2] == 'T' && str[3] == 'H')
        return 1;
    return -1;
}

void parsing(char *envp[], char **argv, char **cut_paths)
{
    char *paths;
    int size;
    int good_nb;
    char **whole_cmd;

    int i = 0;
    while (envp[i])
    {
        if(good_path_arr(envp[i]) == 1)
        {
            good_nb = i;
            break;
        }
        i++;
    }
    size = ft_strlen(envp[good_nb]);
    paths = ft_substr(envp[good_nb], 5, size);
    cut_paths = ft_split(paths, ':');
    free(paths);

    whole_cmd = ft_split(argv[2], ' ');

    /*
    A function that try the command with the cut_paths
    */
    char *cmd_ok = "/ls";
    i = 0;
    char *good[] = {"ls", NULL};
    while (cut_paths[i])
    {
        char *joined = ft_strjoin(cut_paths[i], cmd_ok);
        printf("%s\n", joined);
        if (execve(joined, good, envp) != -1)
        {
            break;
        }
        i++;
	}
	ft_putstr_fd("\nthe good path is at line %d\n", 1);

	/*
	Free the stuffs
	*/
    ft_matr_del_and_free(&cut_paths);
	ft_matr_del_and_free(&whole_cmd);
	//cut_paths
    i = 0;
//    while (cut_paths[i])
//    {
//       free(cut_paths[i]);
//       i++;
//    }
//    free(cut_paths);
//
//    i = 0;
//	while (whole_cmd[i])
//	{
//		printf("%s\n", whole_cmd[i]);
//		free(whole_cmd[i]);
//		i++;
//	}
//	free(whole_cmd);

}


int catch_cmd(char *cut_paths, char *cmd)
{

}   

void    execute(char *envp[], char **argv, t_elems *elms)
{
   char **cut_paths;
   //parsing(envp, argv, elms->cut_paths);
   parsing(envp, argv, cut_paths);

}