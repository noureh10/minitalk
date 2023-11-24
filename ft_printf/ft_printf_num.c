/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:08:07 by nechaara          #+#    #+#             */
/*   Updated: 2023/11/24 18:01:55 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_size(int nb)
{
	int	size;

	size = 0;
	if (nb < 0)
	{
		nb = nb * (-1);
		size = 1;
	}
	if (nb == 0)
		size = 1;
	else
	{
		while (nb)
		{
			nb = nb / 10;
			size++;
		}
	}
	return (size);
}

/**
 * @brief
 * La fonction ft_itoa prend en paramètre un entier et retourne 
 * un string.
 * @param n Le chiffre à convertir
 * @return char* Retourne la chaine de caractère.
 */
char	*ft_itoa(int n)
{
	int		i;
	long	nb;
	char	*res;
	int		isneg;

	i = count_size(n);
	res = (char *) malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	nb = (long) n;
	isneg = 0;
	if (nb < 0)
	{
		nb = nb * (-1);
		res[0] = '-';
		isneg = 1;
	}
	res[i] = '\0';
	while (i > isneg)
	{
		res[i - 1] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	return (res);
}

int	ft_put_nbr(int n)
{
	char	*num;
	int		res;

	num = ft_itoa(n);
	res = ft_putstr(num);
	if (!num || res == -1)
	{
		free(num);
		return (-1);
	}
	free(num);
	return (res);
}
