/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquesad <anquesad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:41:40 by anquesad          #+#    #+#             */
/*   Updated: 2024/07/29 19:43:25 by anquesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	contador;

	contador = 0;
	while (str[contador])
		contador++;
	return (contador);
}

static void	select_format(va_list arg, int value, int *resultado)
{
	if (value == 'c')
		ft_pf_putchar(va_arg(arg, int), resultado);
	else if (value == 's')
		ft_pf_putstr(va_arg(arg, char *), resultado);
	else if (value == 'p')
		ft_pf_pointer(va_arg(arg, unsigned long long), resultado);
	else if (value == 'd' || value == 'i')
		ft_pf_putnbr_base(va_arg(arg, int), DECIMAL, resultado);
	else if (value == 'u')
		ft_pf_putnbr_base(va_arg(arg, unsigned int), DECIMAL, resultado);
	else if (value == 'x')
		ft_pf_putnbr_base(va_arg(arg, unsigned int), HEXA_MIN, resultado);
	else if (value == 'X')
		ft_pf_putnbr_base(va_arg(arg, unsigned int), HEXA_MAY, resultado);
	else if (value == '%')
		ft_pf_putchar('%', resultado);
	else
		*resultado = -1;
}

int	ft_printf(char const *str, ...)
{
	va_list	arg;
	int		i;
	int		resultado ;

	i = 0;
	resultado = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_pf_putchar(str[i], &resultado);
		else if (str[i + 1])
			select_format(arg, str[++i], &resultado);
		i++;
	}
	va_end(arg);
	return (resultado);
}
