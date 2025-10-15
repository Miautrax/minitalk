/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_cnt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivas-q <arivas-q@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:28:22 by arivas-q          #+#    #+#             */
/*   Updated: 2025/03/17 16:28:22 by arivas-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putuint_cnt(unsigned int n, int *count)
{
	if (n >= 10)
		ft_putuint_cnt(n / 10, count);
	write(1, &"0123456789"[n % 10], 1);
	(*count)++;
}
