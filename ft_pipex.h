/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <e.djavid@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 22:01:16 by edjavid           #+#    #+#             */
/*   Updated: 2021/09/27 22:01:17 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>

typedef struct s_elems
{
	int	fd[2];
}	t_elems;

void	ft_bzero(void *s, size_t n);
int		ft_pipex(char **argv, char **envp, t_elems *elm);
int		get_word_len(char const *str, char c);
char	*ft_strnew(size_t size);
int		ft_countwords(char const *str, char c);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_count(char const *s, int cnts);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strlen(const char *str);
void	execute(char *envp[], char *arg);
char	*catch_cmd(char *paths, char *cmd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		error_deal(int the_errno);
char	*parsing(char *envp[], char *arg);
int		ft_matr_del_and_free(char ***matrix);
int		exit_perror(char *s);
void	error_nf(void);
int		malloc_error(void);
char	*get_path_line(char **envp);
char	*find_the_cmd(char **cut_paths, char **cmd);
void	free_all(char *line_path, char **cmd, char **cut_paths);

#endif
