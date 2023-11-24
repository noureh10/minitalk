/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:21:54 by nechaara          #+#    #+#             */
/*   Updated: 2023/10/30 17:01:42 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_hex(unsigned int num, const char format)
{
	if (format == 'x')
	{
		if (ft_putchar((num - 10 + 'a')) == -1)
			return (-1);
	}
	else if (format == 'X')
	{
		if (ft_putchar((num - 10 + 'A')) == -1)
			return (-1);
	}
	return (0);
}

static int	ft_put_hex_v(unsigned int num, const char format)
{
	int	rval;

	rval = 0;
	if (num >= 16)
	{
		if (ft_put_hex_v(num / 16, format) == -1)
			return (-1);
		if (ft_put_hex_v(num % 16, format) == -1)
			return (-1);
	}
	else
	{
		if (num <= 9)
		{
			if (ft_putchar((num + '0')) == -1)
				return (-1);
		}
		else
			rval = ft_format_hex(num, format);
	}
	return (rval);
}

int	ft_put_hex(unsigned int n, const char format)
{
	if (n == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	else
	{
		if (ft_put_hex_v(n, format) == -1)
			return (-1);
	}
	return (ft_hex_num_len(n));
}
