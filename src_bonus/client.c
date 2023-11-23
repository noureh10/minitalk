/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:10:54 by nechaara          #+#    #+#             */
/*   Updated: 2023/11/23 23:47:26 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	g_bit;

/**
 * @brief 
 * The ft_transmit function sends a signal to the server using the kill()
 * function. The signal is either SIGUSR1 or SIGUSR2 depending on the bit
 * value.
 * @param pid The server's process ID
 * @param i The character to be sent
 */
void	ft_transmit_char(int pid, char i)
{
	int	bit;

	if (kill(pid, 0) < 0)
		invalid_pid();
	bit = 7;
	while (bit >= 0)
	{
		g_bit = 0;
		if (i & (0x01 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		--bit;
		while (g_bit == 0)
			usleep(50);
	}
}

/**
 * @brief 
 * The ft_transmit_string function sends a string to the server using the
 * ft_transmit_char function. The string is sent character by character.
 * @param pid The server's process ID
 * @param str The string to be sent
 */
void	ft_transmit_string(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_transmit_char(pid, str[i++]);
	ft_transmit_char(pid, '\0');
}

/**
 * @brief Handles signal control for the minitalk application.
 *
 * This function is a signal handler designed for use in the client program.
 * It is responsible for controlling the behavior of the program when specific
 * signals are received. In particular, it sets a global variable `g_bit` to 1
 * when a SIGUSR1 signal is received, and it calls the function 
 * `message_received()` when a SIGUSR2 signal is received.
 *
 * @param sig The signal number received.
 */
void	ft_signal_control(int sig)
{
	if (sig == SIGUSR1)
		g_bit = 1;
	else if (sig == SIGUSR2)
		message_recieved();
}

/**
 * @brief Main function for a program that transmits a string using signals.
 * 
 * @param argc The number of command-line arguments.
 * @param argv An array of strings representing the command-line arguments.
 * @return int The exit status of the program.
 */
int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
		wrong_format();
	signal(SIGUSR1, ft_signal_control);
	signal(SIGUSR2, ft_signal_control);
	pid = ft_atoi(argv[1]);
	if (!pid)
		invalid_pid();
	ft_transmit_string(pid, argv[2]);
	while (1)
		sleep(1);
}
