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

char *catch_cmd(char *path, char *cmd)
{
	int i;
	char *temp;
	char *good;

	temp = malloc(sizeof(char) * (ft_strlen(cmd)
			+ ft_strlen(path) + 2));
	ft_bzero(temp, ft_strlen(cmd) + ft_strlen(path) + 2);
	i = 0;
	while (path[i])
	{
		temp[i] = path[i];
		i++;
	}
	temp[i] = '/';
	good = ft_strjoin(temp, cmd);
	free(temp);
	return(good);
}

/*
    A function that try the command with the cut_paths
*/
char* parsing(char *envp[], char *arg)
{
	char **cut_paths;
    char **cmd;
    char *exe;
    char *line_path;
    int i;

    line_path = get_path_line(envp);
    cut_paths = ft_split(line_path, ':');
    cmd = ft_split(arg, ' ');
	i = 0;
    while (cut_paths[i])
    {
    	exe = catch_cmd(cut_paths[i], cmd[0]);
		if (access(exe, F_OK) == 0)
		{
			return (exe);
		}
		free(exe);
        i++;
	}
	free(line_path);
	ft_matr_del_and_free(&cmd);
	ft_matr_del_and_free(&cut_paths);
	return (NULL);
}

void   execute(char *envp[], char *arg, t_elems *elms)
{
   char **whole_cmds;
   char *great_cmd;

   great_cmd = parsing(envp, arg);
   if (great_cmd == NULL)
   {
	   error_nf();
   }
   whole_cmds = ft_split(arg, ' ');
   execve(great_cmd, whole_cmds, envp);
}