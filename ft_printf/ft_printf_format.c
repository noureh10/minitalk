/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:27:44 by nechaara          #+#    #+#             */
/*   Updated: 2023/10/30 16:34:33 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char format)
{
	int	lenght;

	lenght = 0;
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_put_ptr(va_arg(args, unsigned long long)));
	else if (format == 'd' || format == 'i')
		return (ft_put_nbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_put_nbr_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_put_hex(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (ft_print_p());
	else
		return (-1);
	return (lenght);
}
