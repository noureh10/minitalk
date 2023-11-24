/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:16:07 by nechaara          #+#    #+#             */
/*   Updated: 2023/10/30 17:05:11 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_ptr_len(unsigned long long n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static int	ft_put_ptr_hex(unsigned long long n)
{
	if (n >= 16)
	{
		if (ft_put_ptr_hex(n / 16) == -1)
			return (-1);
		if (ft_put_ptr_hex(n % 16) == -1)
			return (-1);
	}
	else
	{
		if (n <= 9)
		{
			if (ft_putchar((n + '0')) == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar((n - 10 + 'a')) == -1)
				return (-1);
		}
	}
	return (0);
}

int	ft_put_ptr(unsigned long long ptr)
{
	int	len;

	len = 2;
	if (write(1, "0x", 2) == -1)
		return (-1);
	if (ptr == 0)
	{
		write(1, "0", 1);
		len++;
	}
	else
	{
		if (ft_put_ptr_hex(ptr) == -1)
			return (-1);
		len += ft_hex_ptr_len(ptr);
	}
	return (len);
}
