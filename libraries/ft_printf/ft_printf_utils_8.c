/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_8.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 14:32:44 by joeduard          #+#    #+#             */
/*   Updated: 2021/08/07 14:32:44 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_for_plus_and_space_i_d(t_flags fl, int *len)
{
	if (fl.plus == 1)
		ft_putchar_len('+', len);
	else if (fl.space == 1 && fl.plus == 0)
		ft_putchar_len(' ', len);
}

void	basic_output_check_hash_xX(t_flags fl, int *len, const char c)
{
	if (fl.hash == 1 && c == 'X' && fl.ulli != 0)
	{
		ft_putstr_len("0X", len);
		ft_putstr_len(fl.strNum, len);
	}
	else if (fl.hash == 1 && c == 'x' && fl.ulli != 0)
	{
		ft_putstr_len("0x", len);
		ft_putstr_len(fl.strNum, len);
	}
	else
		ft_putstr_len(fl.strNum, len);
}

void	print_simple_space_precision_i_d(t_flags fl, int size, int *len)
{
	while (fl.precision - size > 0)
	{
		write(1, " ", 1);
		fl.precision--;
		(*len)++;
	}
}

void	print_space_width_greater_than_precision(t_flags fl, int *len)
{
	while (fl.width > fl.precision)
	{
		write(1, " ", 1);
		fl.width--;
		(*len)++;
	}
}
