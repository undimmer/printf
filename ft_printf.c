/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquesad <anquesad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:09:53 by anquesad          #+#    #+#             */
/*   Updated: 2024/08/11 18:21:36 by anquesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     select_format(va_list arg, char c)
{
        int     i;

        i = 0;
        if (c == 'c')
                i += ft_pf_putchar(va_arg(arg, int));
        else if (c == 's')
                i += ft_pf_putstr(va_arg(arg, char *));
        else if (c == 'p')
                i += ft_pf_pointer_zero((unsigned long long)va_arg(arg, void *));
        else if (c == 'd' || c == 'i')
                i += ft_pf_putnbr_base(va_arg(arg, int));
        else if (c == 'u')
                i += ft_pf_putnbr_base_u(va_arg(arg, unsigned));
        else if (c == 'x')
                i += ft_pf_putnbr_base(va_arg(arg, int));
        else if (c == 'X')
                i += ft_pf_putnbr_base(va_arg(arg, int));
        else
                i += ft_pf_putchar(c);
        return (i);
}

int     ft_printf(char const *str, ...)
{
        va_list arg;
        int             i;
        int             contador;

        i = 0;
        contador = 0;
        va_start(arg, str);
        while (str[i])
        {
                if (str[i] == '%')
                        contador += select_format(arg, str[i + 1]);
                else
                        contador += ft_pf_putchar(str[i]);
                i++;
        }
        va_end(arg);
        return (contador);
}
