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
#define FT_PIPEX_H

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void ft_bzero(void *s, size_t n);
int ft_pipex(int fd1, int fd2, char **argv, char **envp);
int get_word_len(char const *str, char c);
char *ft_strnew(size_t size);
int ft_countwords(char const *str, char c);
char **ft_split(char const *s, char c);
void parsing(char **paths, char **argv);
char *ft_strjoin(char const *s1, char const *s2);
int ft_count(char const *s, int cnts);
char *ft_substr(char const *s, unsigned int start, size_t len);
int ft_strlen(const char *str);

#endif