/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:00:21 by souzddou          #+#    #+#             */
/*   Updated: 2024/02/15 23:47:25 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		i += ft_print_str("-2147483648");
	else
	{
		if (n < 0)
		{
			i += ft_printf_char('-');
			n = n * -1;
		}
		if (n > 9)
		{
			i += ft_print_nbr(n / 10);
		}
		i += ft_printf_char((n % 10) + '0');
	}
	return (i);
}
