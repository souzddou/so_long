/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:00:12 by souzddou          #+#    #+#             */
/*   Updated: 2024/02/16 00:06:34 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long num)
{
	int	i;

	i = 0;
	if (num == 0)
	{
		ft_print_str("(nil)");
		return (5);
	}
	i += ft_print_str("0x");
	i += ft_print_hex(num, 'x');
	return (i);
}
