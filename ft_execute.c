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
/*
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
            printf("the good path is at line %d\n", i);
            good_nb = i;
            break;
        }
        i++;
    }

    size = ft_strlen(envp[good_nb]);
    paths = ft_substr(envp[good_nb], 5, size);
    cut_paths = ft_split(paths, ':');
    free(paths);

    //pbm, il faut recup tt ce qu'il y a entre les lettres `` et ''
    whole_cmd = ft_split(argv[2], ' ');
    while (*whole_cmd)
    {
        printf("|%s|", *whole_cmd);
        *whole_cmd++;
    }

    /*
    A function that try the command with the cut_paths
    */
   //TODO : make a function that cuts the argv[2] betzween `` and '' and adds '/' before
    char *cmd_ok = "/ls";
    i = 0;

    char *good[] = {"ls", NULL};
    while (cut_paths[i])
    {
        char *joined = ft_strjoin(cut_paths[i], cmd_ok);
        printf("%s\n", joined);

        if(execve(joined, good, envp) != -1)
        {
            //wait(NULL);
            //I don't know why this shit does nt print
            printf("\nThis shitty command worked and good path is %s\n", joined);
            break;
        }
        i++;
    }


    /*
    Free the stuffs
    */
   //cut_paths
    i = 0;
    while (cut_paths[i])
    {
       free(cut_paths[i]);
       i++;
    }
    free(cut_paths);
  
}


int catch_cmd(char *cut_paths, char *cmd)
{

}   

void    execute(char *envp[], char **argv)
{
   char **cut_paths; 


	parsing(envp, argv, cut_paths);
  
}