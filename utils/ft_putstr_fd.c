/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:03:15 by edjavid           #+#    #+#             */
/*   Updated: 2020/12/01 12:03:17 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_pipex.h"

void		ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (s && *s)
		ft_putchar_fd(*s++, fd);
}
