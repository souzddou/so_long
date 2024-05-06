/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:13:50 by souzddou          #+#    #+#             */
/*   Updated: 2024/02/16 00:30:24 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_formats(va_list args, char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_printf_char(va_arg(args, int));
	else if (format == 's')
		print_len += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		print_len += ft_print_ptr(va_arg(args, size_t));
	else if (format == 'd' || format == 'i')
		print_len += ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		print_len += ft_print_unsigned(va_arg(args, size_t));
	else if (format == 'x' || format == 'X')
		print_len += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_len += ft_printf_char(format);
	return (print_len);
}

int	ft_printf(const char*s, ...)
{
	unsigned int	i;
	va_list			args;
	int				print_len;

	i = 0;
	print_len = 0;
	if (!s)
		return (-1);
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			print_len += ft_check_formats(args, s[i + 1]);
			i++;
		}
		else
			print_len += ft_printf_char(s[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}
