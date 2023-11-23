/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:11:02 by nechaara          #+#    #+#             */
/*   Updated: 2023/11/23 23:47:17 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/**
 * @brief Initializes signal handling for custom signals.
 *
 * This function sets up signal handling for user-defined signals, specifically
 * for the signals SIGUSR1 and SIGUSR2. It associates a custom signal handler 
 * function with the specified signal, enabling the program to respond
 * appropriately when these signals are received.
 *
 * @param usg The user-specified signal for which signal handling is to be 
 * initialized. Valid values are SIGUSR1 or SIGUSR2.
 * @param hdl A pointer to the custom signal handler function. The handler
 * should have the following signature: void handler(int, siginfo_t *).
 * It is responsible for processing the received signal.
 */
void	ft_singal_initialization(int usg, void (*hdl)(int, siginfo_t *, void *))
{
	struct sigaction	user_signal;

	user_signal.sa_sigaction = hdl;
	user_signal.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;
	sigemptyset(&user_signal.sa_mask);
	if (usg == SIGUSR1)
		sigaction(SIGUSR1, &user_signal, 0);
	else if (usg == SIGUSR2)
		sigaction(SIGUSR2, &user_signal, 0);
}

/**
 * @brief Signal handler function for receiving binary data via signals.
 * 
 * @param sig The signal number.
 * @param info A pointer to a structure containing additional information about
 * the signal.
 * @param ctx A pointer to the signal context (unused in this function).
 */
void	ft_recieve_signal(int sig, siginfo_t *info, void *ctx)
{
	static char	c = 0;
	static int	bit = -1;

	(void)ctx;
	if (kill(info->si_pid, 0) < 0)
		not_valid_pid(info);
	if (bit < 0 && !c)
		ft_printf("\n");
	if (bit < 0)
		bit = 7;
	if (sig == SIGUSR1)
		c |= (0x01 << bit);
	else if (sig == SIGUSR2)
		c &= ~(0x01 << bit);
	if (c && !bit)
		ft_printf("%c", c);
	else if (!c && !bit)
		kill(info->si_pid, SIGUSR2);
	--bit;
	kill(info->si_pid, SIGUSR1);
}

/**
 * @brief Main function for a server program that initializes signal
 * handlers and runs indefinitely.
 * 
 * @return int The exit status of the program.
 */
int	main(void)
{
	ft_singal_initialization(SIGUSR1, ft_recieve_signal);
	ft_singal_initialization(SIGUSR2, ft_recieve_signal);
	logo_server(getpid());
	while (1)
		sleep(1);
}
