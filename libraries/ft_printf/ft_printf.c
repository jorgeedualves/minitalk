/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:45:08 by joeduard          #+#    #+#             */
/*   Updated: 2021/07/05 14:45:08 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_types(const char c, int *len, va_list args, t_flags fl)
{
	if (c == 'c')
		print_c(va_arg(args, int), len, fl);
	if (c == 's')
		print_s(va_arg(args, char *), len, fl);
	if (c == 'i' || c == 'd')
		print_i_d(fl, args, len);
	if (c == 'u')
		print_u(fl, args, len);
	if (c == 'p')
		print_p(fl, args, len, c);
	if (c == 'x' || c == 'X')
		print_xX(fl, args, len, c);
	if (c == '%')
		ft_putstr_len("%", len);
	if (ft_strchr(TYPES, c) == 0)
		(*len) = -1;
	return (*len);
}

t_flags	get_flag_width_precision(const char *format, t_flags fl, int *i)
{
	if (format[*i] == '-')
		fl.minus = 1;
	else if (format[*i] == '0' && fl.minus == 0 && fl.width == 0 && fl.dot == 0)
		fl.zero = 1;
	else if (format[*i] == '.')
	{
		fl.dot = 1;
	}
	else if (ft_strchr(NUMBERS, format[*i]))
	{
		if (fl.dot == 1)
			fl.precision = (fl.precision * 10) + (format[*i] - '0');
		else
			fl.width = (fl.width * 10) + (format[*i] - '0');
	}
	else if (format[*i] == '#')
		fl.hash = 1;
	else if (format[*i] == '+')
		fl.plus = 1;
	else if (format[*i] == ' ')
		fl.space = 1;
	return (fl);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;
	t_flags	fl;

	va_start(args, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar_len(format[i++], &len);
		else
		{
			i++;
			fl = ft_clean_flags ();
			while (format[i] && ft_strchr(FLAGS, format[i]))
				fl = get_flag_width_precision(format++, fl, &i);
			handle_types(format[i++], &len, args, fl);
			if (len == -1)
				return (-1);
		}
	}
	va_end(args);
	return (len);
}
