/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivas-q <arivas-q@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:56:08 by arivas-q          #+#    #+#             */
/*   Updated: 2025/01/31 09:21:22 by arivas-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*result;

	if (num != 0 && size > SIZE_MAX / num)
		return (NULL);
	result = malloc(num * size);
	if (result == NULL)
		return (NULL);
	else
	{
		ft_bzero(result, (num * size));
		return (result);
	}
}
