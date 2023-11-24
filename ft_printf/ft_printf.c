/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:01:39 by nechaara          #+#    #+#             */
/*   Updated: 2023/11/01 14:13:59 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief 
 * La fonction ft_printf réplique le comportement de la méthode printf de la 
 * librairie <stdio.h>, Elle a pour but de traiter un string et de le foramtter
 * selon les flags dans celle ci :
 * 
 * Les caractère de formattage sont les suivants :
 * %c - Affiche un caractère.
 * %s - Affiche un string.
 * %p - Affiche l'argument du pointeur void en hexadécimal.
 * %d - Affiche un nombre en base décimale.
 * %u - Affiche un nombre en base décimale non signé.
 * %x & %X - Affiche un nombre en base héxa avec des lettres min ou max.
 * %% - Affiche un pourcentage.
 * 
 * @param str La chaine de caractères pour le formatage
 * @param ... Les varargs.
 * @return int La taille de en octet de ce qui est imprimé.
 */
int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		lenght;
	int		res;

	i = 0;
	lenght = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			res = ft_formats(args, str[i++ + 1]);
		else
			res = ft_putchar(str[i]);
		if (res == -1)
			return (-1);
		else
			lenght += res;
		i++;
	}
	va_end(args);
	return (lenght);
}
