/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivas-q <arivas-q@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:19:57 by arivas-q          #+#    #+#             */
/*   Updated: 2025/02/04 08:21:35 by arivas-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*lastchr;

	lastchr = 0;
	while (*s)
	{
		if (*s == (char)c)
			lastchr = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (lastchr);
}
