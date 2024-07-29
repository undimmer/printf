/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquesad <anquesad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:34:47 by anquesad          #+#    #+#             */
/*   Updated: 2024/07/22 16:16:03 by anquesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

# define HEXA_MIN "0123456789abcdef"
# define HEXA_MAY "0123456789ABCDEF"
# define DECIMAL "0123456789"

int     ft_printf(char const *str, ...);
int     ft_strlen(const char *str);
void    ft_pf_putchar(char c, int *resultado);
void    ft_pf_putstr(char *s, int *resultado);
void    ft_pf_pointer(unsigned long long ptr, int *resultado);
void    ft_pf_putnbr_base(long long nbr, char *base, int *resultado);

#endif
