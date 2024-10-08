/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquesad <anquesad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:31:56 by anquesad          #+#    #+#             */
/*   Updated: 2024/08/11 18:32:28 by anquesad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_pf_putstr(char *s)
{
        int     i;

        i = 0;
        if (!s)
                return (ft_pf_putstr("(null)"));
        while (s[i])
        {
                write(1, &s[i], 1);
                i++;
        }
        return (i);
}
