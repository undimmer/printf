/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquesad <anquesad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:21:29 by anquesad          #+#    #+#             */
/*   Updated: 2024/08/11 18:33:50 by anquesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int      ft_pf_pointer(unsigned long int n)
{
        int             i;
        char    *str;

        i = 0;
        str = "0123456789abcdef";
        if (n >= 16)
                i += ft_pf_pointer(n / 16);
        i += ft_pf_putchar(str[n] % 16);
        return (i);
}

int     ft_pf_pointer_zero(unsigned long int n)
{
        int     i;

        i = 0;
        if (n == 0)
        {
                i += ft_pf_putstr("(nil)");
                return (i);
        }
        i += ft_pf_putstr("0x");
        i += ft_pf_pointer(n);
        return (i);
}
