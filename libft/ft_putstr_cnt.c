/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_cnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivas-q <arivas-q@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:28:47 by arivas-q          #+#    #+#             */
/*   Updated: 2025/03/17 15:28:47 by arivas-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_cnt(char *str, int *count)
{
	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		write(1, str, 1);
		(*count)++;
		str++;
	}
}
