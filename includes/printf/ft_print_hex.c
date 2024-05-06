/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:00:05 by souzddou          #+#    #+#             */
/*   Updated: 2024/02/16 00:04:14 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(size_t num, char format)
{
	int	i;

	i = 0;
	if (num <= 9)
	{
		num = num + '0';
		i += write(1, &num, 1);
	}
	else if (num >= 16)
	{
		i += ft_print_hex(num / 16, format);
		i += ft_print_hex(num % 16, format);
	}
	else
	{
		if (format == 'x')
			num = num - 10 + 'a';
		else if (format == 'X')
			num = num - 10 + 'A';
		i += write (1, &num, 1);
	}
	return (i);
}
