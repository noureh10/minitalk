/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:59:18 by nechaara          #+#    #+#             */
/*   Updated: 2023/11/24 00:14:17 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	invalid_pid(void)
{
	ft_printf("\033[33mError\033[0m\n");
	ft_printf("Invalid PID\n");
	exit(1);
}

void	message_recieved(void)
{
	ft_printf("\033[32mMessage recieved\033[0m\n");
	exit(0);
}

void	message_transmitted(void)
{
	ft_printf("\033[32mMessage transmitted\033[0m\n");
}

void	wrong_format(void)
{
	ft_printf("\033[33mError\033[0m\n");
	ft_printf("Try this instead : ./client [PID] [MESSAGE]\n");
	exit(1);
}

void	logo_server(int pid)
{
	ft_printf("\033[0;31m");
	ft_printf("        .__       .__  __         .__   __    \n");
	ft_printf("  _____ |__| ____ |__|/  |______  |  | |  | __\n");
	ft_printf(" /     \\|  |/    \\|  \\   __\\__  \\ |  | |  |/ /\n");
	ft_printf("|  Y Y  \\  |   |  \\  ||  |  / __ \\|  |_|    <\n");
	ft_printf("|__|_|  /__|___|  /__||__| (____  /____/__|_ \\\n");
	ft_printf("      \\/        \\/              \\/          \\/\n");
	ft_printf("                                              \n");
	ft_printf("  ______ ______________  __ ___________       \n");
	ft_printf(" /  ___// __ \\_  __ \\  \\/ // __ \\_  __ \\      \n");
	ft_printf(" \\___ \\ \\  ___/|  | \\/   /\\  ___/|  | \\/      \n");
	ft_printf("/____  >\\___  >__|    \\_/  \\___  >__|         \n");
	ft_printf("     \\/     \\/                 \\/             \n");
	ft_printf("\033[0m");
	ft_printf("\033[0;33mProcess ID : %d \033[0m", pid);
}
