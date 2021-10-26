/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 11:34:01 by joeduard          #+#    #+#             */
/*   Updated: 2021/07/24 11:34:01 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_i_d(t_flags fl, va_list args, int *len)
{
	int	number;
	int	size;

	size = 0;
	number = va_arg(args, int);
	if (number == 0 && fl.dot == 1 && fl.precision == 0)
	{
		fl.strNum = ft_itoa(number);
		size = (int)ft_strlen(fl.strNum);
		print_zero_corner_cases(fl, size, len);
		free(fl.strNum);
	}
	else if (number >= 0)
		print_positive_i_d(fl, number, len);
	else
	{
		number *= -1;
		print_negative_i_d(fl, number, len);
	}	
}

void	print_positive_i_d(t_flags fl, int number, int *len)
{
	int	size;

	fl.strNum = ft_itoa(number);
	size = (int)ft_strlen(fl.strNum);
	if (size == 0 && fl.dot == 1 && fl.precision == 0)
		print_zero_corner_cases(fl, size, len);
	if ((fl.width == 0 || fl.width <= size) && (fl.precision > size))
		print_precision_zero_i_d(fl, size, len);
	else if (fl.width > size && (fl.precision == 0 || fl.precision <= size))
		print_space_or_zero_number_i_d(fl, size, len);
	else if (fl.width > size && fl.precision > size)
		print_corner_cases_i_d(fl, size, len);
	else
	{
		check_for_plus_and_space_i_d(fl, len);
		ft_putstr_len(fl.strNum, len);
	}
	free(fl.strNum);
}

void	print_negative_i_d(t_flags fl, int number, int *len)
{
	int	size;

	if (number == -2147483648)
		fl.strNum = "2147483648";
	else
		fl.strNum = ft_itoa(number);
	size = (int)ft_strlen(fl.strNum) + 1;
	if (fl.width <= size && fl.precision < size)
		print_neg_number_i_d(fl, len);
	else if (fl.precision > size - 1 && fl.width < size)
		print_precision_neg_zero_number_i_d(fl, size, len);
	else if ((fl.width > size || fl.width == 0)
		&& (fl.precision == 0 || fl.precision > size) && fl.zero == 1)
		print_neg_zero_variations_i_d(fl, size, len);
	else if ((fl.width > size && fl.precision != 0) && fl.precision <= size)
		print_neg_corner_cases_i_d(fl, size, len);
	else if (fl.minus == 1 && fl.precision == 0 && fl.width > size)
		print_neg_number_space_i_d(fl, size, len);
	else if (fl.minus == 0 && fl.width > size && fl.dot == 0)
		print_space_neg_number_i_d(fl, size, len);
	else if (fl.width == fl.precision)
		print_width_neg_zero_number_i_d(fl, size, len);
	if (number != -2147483648)
		free(fl.strNum);
}

void	print_corner_cases_i_d(t_flags fl, int size, int *len)
{
	int	i;

	i = 0;
	if (fl.minus == 1)
	{
		if (fl.width == fl.precision)
			print_precision_zero_i_d(fl, size, len);
		else if (fl.width > fl.precision)
			print_zero_number_space_i_d(fl, size, len, &i);
		else
			print_precision_zero_i_d(fl, size, len);
	}
	else
	{	
		print_simple_space_width_precision_i_d(fl, len);
		print_precision_zero_i_d(fl, size, len);
	}
}

void	print_neg_corner_cases_i_d(t_flags fl, int size, int *len)
{
	if (fl.minus == 1 && fl.precision < size)
	{
		print_neg_number_i_d(fl, len);
		while (fl.width - size > 0)
		{
			write(1, " ", 1);
			fl.width--;
			(*len)++;
		}
	}
	else if (fl.minus == 1 && fl.precision == size)
	{
		print_neg_precision_zero_number_i_d(fl, size, len);
		while (fl.width - size > 1)
		{
			write(1, " ", 1);
			fl.width--;
			(*len)++;
		}
	}
	else if (fl.minus == 1 && fl.precision >= size)
		print_neg_prec_zero_number_space_i_d(fl, size, len);
	else
		print_space_neg_number_i_d(fl, size, len);
}
