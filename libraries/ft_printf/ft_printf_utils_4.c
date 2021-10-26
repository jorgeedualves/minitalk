/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 19:17:18 by joeduard          #+#    #+#             */
/*   Updated: 2021/08/06 19:17:18 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_zero_i_d(t_flags fl, int size, int *len)
{
	if (fl.precision > 0)
	{
		while (fl.precision - size > 0)
		{
			write(1, "0", 1);
			fl.precision--;
			(*len)++;
		}
	}
	else
	{		
		while (fl.width - size > 0)
		{
			write(1, "0", 1);
			fl.width--;
			(*len)++;
		}
	}
}

void	print_width_zero_i_d(t_flags fl, int size, int *len)
{
	while (fl.width - size > 0)
	{
		write(1, "0", 1);
		fl.width--;
		(*len)++;
	}
	check_for_plus_and_space_i_d(fl, len);
	ft_putstr_len(fl.strNum, len);
}

void	print_precision_zero_i_d(t_flags fl, int size, int *len)
{
	while (fl.precision - size > 0)
	{
		write(1, "0", 1);
		fl.precision--;
		(*len)++;
	}
	check_for_plus_and_space_i_d(fl, len);
	ft_putstr_len(fl.strNum, len);
}

void	print_zero_number_space_i_d(t_flags fl, int size, int *len, int *i)
{
	print_precision_zero_i_d(fl, size, len);
	while (fl.width - (fl.precision + *i) > 0)
	{
		write(1, " ", 1);
		fl.width--;
		(*len)++;
	}
}

void	print_neg_zero_variations_i_d(t_flags fl, int size, int *len)
{
	if (fl.width > fl.precision && fl.dot == 1)
	{
		while (fl.width - (fl.precision + 1) > 0)
		{
			write(1, " ", 1);
			fl.width--;
			(*len)++;
		}
		print_precision_neg_zero_number_i_d(fl, size, len);
	}
	else if (fl.width == fl.precision && fl.dot == 1)
		print_width_neg_zero_number_i_d(fl, size, len);
	else if (fl.width < fl.precision && fl.dot == 1)
		print_precision_neg_zero_number_i_d(fl, size, len);
	else
	{
		ft_putchar_len('-', len);
		print_zero_i_d(fl, size, len);
		ft_putstr_len(fl.strNum, len);
	}
}
