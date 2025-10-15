/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivas-q <arivas-q@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:16:54 by arivas-q          #+#    #+#             */
/*   Updated: 2025/01/31 09:22:29 by arivas-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_num_length(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*itoa_body(int n)
{
	size_t	num_len;
	size_t	i;
	char	*str;

	num_len = get_num_length(n);
	str = malloc(sizeof(char) * (num_len + 1));
	if (!str)
		return (NULL);
	str[num_len] = '\0';
	i = num_len - 1;
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	if (n == 0)
		str[i] = '0';
	while (n > 0)
	{
		str[i--] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (itoa_body(n));
}
