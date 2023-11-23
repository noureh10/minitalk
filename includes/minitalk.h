/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:12:48 by nechaara          #+#    #+#             */
/*   Updated: 2023/11/24 00:20:47 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <sys/types.h>

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "../ft_printf/ft_printf.h"

// case utils
void	invalid_pid(void);
void	message_recieved(void);
void	message_transmitted(void);
void	logo_server(int pid);
void	wrong_format(void);
void	not_valid_pid(siginfo_t *info);
int		ft_atoi(const char *nptr);

#endif