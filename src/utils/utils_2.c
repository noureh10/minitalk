/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:50:00 by nechaara          #+#    #+#             */
/*   Updated: 2023/11/23 23:24:44 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	not_valid_pid(siginfo_t *info)
{
	ft_printf("ERROR : cant send sig to pid : %d\n", info->si_pid);
	exit(EXIT_FAILURE);
}

static int	ft_skip_space_give_sign(const char *str, size_t *ipt)
{
	size_t	i;
	int		sign;

	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '-' || str[i + 1] == '+')
			sign = 0;
		else
		{
			if (str[i] == '-')
				sign = -1;
			else
				sign = 1;
		}
		i++;
	}
	*ipt = i;
	return (sign);
}

int	ft_atoi(const char *nptr)
{
	size_t		i;
	int			sign;
	long int	res;
	long int	digit;

	i = 0;
	res = 0;
	sign = ft_skip_space_give_sign(nptr, &i);
	while ((nptr[i]) >= '0' && (nptr[i]) <= '9')
	{
		digit = nptr[i] - '0';
		res = res * 10 + digit;
		i++;
	}
	return ((int)(res * sign));
}
