/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquesad <anquesad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:32:55 by anquesad          #+#    #+#             */
/*   Updated: 2024/08/11 18:32:59 by anquesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_pf_putnbr_base(int n)
{
        int                     i;
        long int        nbr;

        i = 0;
        nbr = n;
        if (nbr < 0)
        {
                i += ft_pf_putchar('-');
                nbr = -nbr;
        }
        if (nbr / 10)
        {
                i += ft_pf_putnbr_base(nbr / 10);
        }
        i += ft_pf_putchar(nbr % 10 + '0');
        return (i);

}

int     ft_pf_putnbr_base_u(unsigned n)
{
        unsigned        i;

        i = 0;

        if (nbr / 10)
        {
                i += ft_pf_putnbr_base_u(nbr / 10);
        }
        i += ft_pf_putchar(nbr % 10 + '0');
        return (i);
}
