/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_cnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivas-q <arivas-q@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:30:55 by arivas-q          #+#    #+#             */
/*   Updated: 2025/03/17 15:30:55 by arivas-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_cnt(unsigned long n, int *count, char *base)
{
	if (n >= 16)
		ft_puthex_cnt(n / 16, count, base);
	write(1, &base[n % 16], 1);
	(*count)++;
}
