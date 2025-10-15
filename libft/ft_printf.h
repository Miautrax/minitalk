/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivas-q <arivas-q@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:02:17 by arivas-q          #+#    #+#             */
/*   Updated: 2025/04/07 10:04:25 by arivas-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

void	ft_putstr_cnt(char *str, int *count);
void	ft_puthex_cnt(unsigned long n, int *count, char *base);
void	ft_putuint_cnt(unsigned int n, int *count);
void	ft_putlong_cnt(long n, int *count);
int		put_format(char spec, va_list args, int *count);
int		put_format2(char spec, va_list args, int *count);
void	print_percentaje(int *count);
int		ft_printf(char const *format, ...);

#endif
