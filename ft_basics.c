/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquesad <anquesad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:31:37 by anquesad          #+#    #+#             */
/*   Updated: 2024/07/29 19:38:11 by anquesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pf_putchar(char c, int *resultado)
{
	if (*resultado == -1)
		return ;
	if (write(1, &c, 1) == -1)
		*resultado = -1;
	else
		*resultado += 1;
}

void	ft_pf_putstr(char *s, int *resultado)
{
	int		i;

	i = -1;
	if (!s)
		s = "(null)";
	while (s[++i])
		ft_pf_putchar(s[i], resultado);
}

void	ft_pf_putnbr_base(long long nbr, char *base, int *resultado)
{
	int		len_base;

	len_base = ft_strlen(base);
	if (*resultado < 0)
	{
		ft_pf_putchar('-', resultado);
		ft_pf_putnbr_base(-nbr, base, resultado);
	}
	if (nbr > ft_strlen(base) - 1)
	{
		ft_pf_putnbr_base(nbr / len_base, base, resultado);
		ft_pf_putnbr_base(nbr % len_base, base, resultado);
	}
	else
		ft_pf_putchar(base[nbr], resultado);
}

void	ft_pf_pointer(unsigned long long ptr, int *resultado)
{
	if (*resultado == -1)
		return ;
	if (ptr == 0)
	{
		ft_pf_putstr("(null)", resultado);
		return ;
	}
	ft_pf_putstr("0x", resultado);
	ft_pf_putnbr_base(ptr, HEXA_MIN, resultado);
}
