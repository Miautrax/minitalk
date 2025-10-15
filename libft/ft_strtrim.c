/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivas-q <arivas-q@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:17:21 by arivas-q          #+#    #+#             */
/*   Updated: 2025/01/31 09:34:11 by arivas-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim_str;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	end = ft_strlen((char *)s1);
	start = 0;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	trim_str = malloc(sizeof(char) * (end - start + 1));
	if (!trim_str)
		return (0);
	while (start < end)
		trim_str[i++] = s1[start++];
	trim_str[i] = '\0';
	return (trim_str);
}
