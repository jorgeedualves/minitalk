/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 11:14:35 by joeduard          #+#    #+#             */
/*   Updated: 2021/07/24 11:14:35 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(char c, int *len, t_flags fl)
{
	if (fl.minus == 0 && fl. width > 0)
	{
		while (fl.width > 1)
		{
			write(1, " ", 1);
			fl.width--;
			(*len)++;
		}
		ft_putchar_len(c, len);
	}
	else if (fl.minus == 1)
	{
		ft_putchar_len(c, len);
		while (fl.width > 1)
		{
			write(1, " ", 1);
			fl.width--;
			(*len)++;
		}
	}
	else
		ft_putchar_len(c, len);
}
