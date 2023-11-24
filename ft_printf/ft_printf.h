/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:02:16 by nechaara          #+#    #+#             */
/*   Updated: 2023/11/01 14:13:57 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

// Taille pour les différents formats
int		ft_u_num_len(unsigned int n);
int		ft_num_len(int n);
int		ft_hex_num_len(unsigned int n);

// Fonctions pour l'affichage des différents format ssur la sortie standard
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_put_ptr(unsigned long long ptr);
int		ft_put_nbr(int n);
int		ft_put_nbr_unsigned(unsigned int n);
int		ft_put_hex(unsigned int n, const char format);
int		ft_print_p(void);

// Fonctions principales
int		ft_printf(const char *str, ...);
int		ft_formats(va_list args, const char format);

#endif 