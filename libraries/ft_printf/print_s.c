/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 11:31:59 by joeduard          #+#    #+#             */
/*   Updated: 2021/07/24 11:31:59 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_s(char *c, int *len, t_flags fl)
{
	int	size;

	size = 0;
	if (c == NULL)
		c = "(null)";
	size = (int)ft_strlen(c);
	if ((fl.precision < size && fl.precision > 0) && fl.width < size)
	{
		while (fl.precision > 0)
		{
			write(1, &*c, 1);
			fl.precision--;
			(*len)++;
			c++;
		}
	}
	else if ((fl.precision == 0 || fl.precision >= size) && fl.width > size)
		print_space_print_s(c, len, fl);
	else if (fl.precision < size && fl.width >= size)
		print_space_cut_s(c, len, fl);
	else if (fl.dot == 1 && fl.precision == 0)
		write(1, "", 0);
	else
		ft_putstr_len(c, len);
}

void	print_space_print_s(char *c, int *len, t_flags fl)
{
	int	size;

	size = (int)ft_strlen(c);
	if (fl.minus == 0)
	{
		while (fl.width > size)
		{
			write(1, " ", 1);
			fl.width--;
			(*len)++;
		}
		ft_putstr_len(c, len);
	}
	else
	{
		ft_putstr_len(c, len);
		while (fl.width > size)
		{
			write(1, " ", 1);
			fl.width--;
			(*len)++;
		}
	}
}

void	print_space_cut_s(char *c, int *len, t_flags fl)
{
	int	size;

	size = (int)ft_strlen(c);
	if (fl.width == size)
		ft_putstr_len(c, len);
	else if (fl.minus == 0)
		print_space_cut_right_s(c, len, fl);
	else
		print_space_cut_left_s(c, len, fl);
}

void	print_space_cut_right_s(char *c, int *len, t_flags fl)
{
	while (fl.width - fl.precision > 0)
	{
		write(1, " ", 1);
		fl.width--;
		(*len)++;
	}
	while (fl.precision > 0)
	{
		write(1, &*c, 1);
		fl.precision--;
		(*len)++;
		c++;
	}
}

void	print_space_cut_left_s(char *c, int *len, t_flags fl)
{
	int	count;

	count = 0;
	while (fl.precision > 0)
	{
		write(1, &*c, 1);
		fl.precision--;
		(*len)++;
		c++;
		count++;
	}
	while (fl.width - (fl.precision + count) > 0)
	{
		write(1, " ", 1);
		fl.width--;
		(*len)++;
	}
}
