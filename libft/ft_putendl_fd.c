/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivas-q <arivas-q@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:17:01 by arivas-q          #+#    #+#             */
/*   Updated: 2025/01/20 13:25:26 by arivas-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t		lens;

	if (!s)
		return ;
	lens = ft_strlen(s);
	write(fd, s, lens);
	write(fd, "\n", 1);
}
