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

char *get_path_line(char **envp)
{
    int size;
    int good_nb;
    int i;

    i = 0;
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
    return (ft_substr(envp[good_nb], 5, size));
}

char *catch_cmd(char **cut_paths, char *cmd)
{
	int i;
	char *temp;
	char *path;

	temp = malloc(sizeof(char) * ft_strlen(cmd) + 2);
	ft_bzero(temp, ft_strlen(cmd) + 2);
	i = 0;
	while (cut_paths[i])
	{


		i++;
	}
}

/*
    A function that try the command with the cut_paths
*/
void parsing(char *envp[], char **argv, char **cut_paths)
{
    char **whole_cmd;
    int i;

    cut_paths = ft_split(get_path_line(envp), ':');
    whole_cmd = ft_split(argv[2], ' ');

	i = 0;
    while (cut_paths[i])
    {
    //	char *exe = catch_cmd(cut_paths, whole_cmd[0]);
	//	printf("arg is %s", exe);
	//	free(exe);
     //   char *joined = ft_strjoin(cut_paths[i], cmd_ok);
     //   printf("%s\n", joined);
     //   if (execve(joined, whole_cmd, envp) != -1)
     //   {
     //       break;
     //   }
        i++;
	}
	/*
	Free the stuffs
	*/
    ft_matr_del_and_free(&cut_paths);
	ft_matr_del_and_free(&whole_cmd);
}


void    execute(char *envp[], char **argv, t_elems *elms)
{
   char **cut_paths;
   //parsing(envp, argv, elms->cut_paths);
   parsing(envp, argv, cut_paths);
}