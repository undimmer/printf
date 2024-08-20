/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquesad <anquesad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:18:39 by anquesad          #+#    #+#             */
/*   Updated: 2024/08/11 18:24:08 by anquesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define HEXA_MIN "0123456789abdef"
# define HEXA_MAY "01236456789ABDEF"
# define DECIMAL "0123456789"

int                     ft_pf_putchar(int c);
int                     ft_pf_putstr(char *s);
int                     ft_pf_putnbr_base(int n);
int                     ft_pf_putnbr_base_u(unsigned n);
int                     ft_pf_pointer_zero(unsigned long long n);
int                     ft_printf(char const *str, ...);
int                     select_format(va_list arg, char c);
int                     ft_putnbr_unsigned(unsigned int n, char *str);

#endif
