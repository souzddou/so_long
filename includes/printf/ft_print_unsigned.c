/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:00:18 by souzddou          #+#    #+#             */
/*   Updated: 2024/02/15 23:49:17 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int num)
{
	int	i;

	i = 0;
	if (num > 9)
	{
		i += ft_print_unsigned(num / 10);
	}
	i += ft_printf_char((num % 10) + '0');
	return (i);
}
