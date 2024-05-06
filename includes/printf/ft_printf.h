/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souzddou <souzddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:28:34 by souzddou          #+#    #+#             */
/*   Updated: 2024/02/16 00:31:42 by souzddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf_char(int c);
int		ft_print_ptr(unsigned long num);
int		ft_print_str(char *s);
int		ft_print_hex(unsigned long n, char format);
int		ft_print_unsigned(unsigned int num);
int		ft_print_nbr(int n);
int		ft_printf(const char*s, ...);

#endif
