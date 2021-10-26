/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_7.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 19:18:40 by joeduard          #+#    #+#             */
/*   Updated: 2021/08/06 19:18:40 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_space_string_u(t_flags fl, int *len, int size)
{
	if (fl.minus == 1)
	{
		ft_putstr_len(fl.strNum, len);
		print_space(fl, size, len);
	}
	else
	{
		print_space(fl, size, len);
		ft_putstr_len(fl.strNum, len);
	}
}

void	print_width_space_u(t_flags fl, int *len)
{
	while (fl.width > 1)
	{
		write(1, " ", 1);
		fl.width--;
		(*len)++;
	}
}

void	print_precision_zero_u(t_flags fl, int *len)
{
	while (fl.precision > 0)
	{
		write(1, "0", 1);
		fl.precision--;
		(*len)++;
	}	
}

void	print_simple_zero_xX(t_flags fl, int size, int *len)
{
	while (fl.width - size > 0)
	{
		write(1, "0", 1);
		fl.width--;
		(*len)++;
	}
}

t_flags	ft_clean_flags(void)
{
	t_flags	fl;

	fl.minus = 0;
	fl.zero = 0;
	fl.width = 0;
	fl.dot = 0;
	fl.precision = 0;
	fl.hash = 0;
	return (fl);
}
