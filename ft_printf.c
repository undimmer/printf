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

/* Esta función calcula la longitud de una cadena de carácteres */

int	ft_strlen(const char *str)
{
	int	contador;

	contador = 0;
	while (str[contador])  		// Incrementa el contador hasta encontrar el carácter nulo
		contador++;
	return (contador);		// Devuelve el número de carácteres en la cadena (sin contar el /0)
}

/* Función estática que controla los tipos de formato que pueden pasar por el ft_printf */

static void	select_format(va_list arg, int value, int *resultado)
{
	if (value == 'c')
		ft_pf_putchar(va_arg(arg, int), resultado);				// Imprime un carácer
	else if (value == 's')
		ft_pf_putstr(va_arg(arg, char *), resultado);				// Imprime una cadena de caracteres
	else if (value == 'p')
		ft_pf_pointer(va_arg(arg, unsigned long long), resultado);		// Imprime un puntero
	else if (value == 'd' || value == 'i')
		ft_pf_putnbr_base(va_arg(arg, int), DECIMAL, resultado);		// Imprime un entero decimal
	else if (value == 'u')
		ft_pf_putnbr_base(va_arg(arg, unsigned int), DECIMAL, resultado);	// Imprime un entero sin signo
	else if (value == 'x')
		ft_pf_putnbr_base(va_arg(arg, unsigned int), HEXA_MIN, resultado);	// Imprime un entero en hexadecimal en minúsculas
	else if (value == 'X')
		ft_pf_putnbr_base(va_arg(arg, unsigned int), HEXA_MAY, resultado);	// Imprime un entero en hexadecimal en mayúsculas
	else if (value == '%')
		ft_pf_putchar('%', resultado);						// Imprime un porcentaje literal
	else
		*resultado = -1;
}

/* Función principal que realiza el comportamiento de printf */

int	ft_printf(char const *str, ...)
{
	va_list	arg;							// Declara una variable para almacenar los argumentos
	int		i;
	int		resultado ;

	i = 0;
	resultado = 0;
	va_start(arg, str);						// Aquí de inicializa la lista de argumentos
	while (str[i])
	{
		if (str[i] != '%')					// Si el carácter no es '%', imprime carácter tal cuál
			ft_pf_putchar(str[i], &resultado);
		else if (str[i + 1])					// Si es '%', procesa el siguiente carácter como un especificador de formato
			select_format(arg, str[++i], &resultado);
		i++;							// Avanza al siguiente carácter de la cadena
	}
	va_end(arg);							// Finaliza el procesamiento de la lista de argumentos
	return (resultado);						// Devolviendo el resultado acumulado
}
