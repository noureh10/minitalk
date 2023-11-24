/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_num.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:09:15 by nechaara          #+#    #+#             */
/*   Updated: 2023/10/30 17:03:03 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_unsigned_itoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_u_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n)
	{
		num[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_put_nbr_unsigned(unsigned int n)
{
	int		res;
	char	*sn;

	res = 0;
	if (n == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		res++;
	}
	else
	{
		sn = ft_unsigned_itoa(n);
		res += ft_putstr(sn);
		if (!sn || res == -1)
		{
			free(sn);
			return (-1);
		}
		free(sn);
	}
	return (res);
}
