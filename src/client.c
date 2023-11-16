/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:10:54 by nechaara          #+#    #+#             */
/*   Updated: 2023/11/16 13:13:07 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

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
	while ((nptr[i])>= '0' && (nptr[i]) <= '9')
	{
		digit = nptr[i] - '0';
		res = res * 10 + digit;
		i++;
	}
	return ((int)(res * sign));
}

void	ft_transmit(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			ft_transmit(pid, argv[2][i]);
			i++;
		}
		ft_transmit(pid, '\n');
	}
	else
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		ft_printf("\033[33mTry: ./client <PID> <MESSAGE>\033[0m\n");
		return (1);
	}
	return (0);
}