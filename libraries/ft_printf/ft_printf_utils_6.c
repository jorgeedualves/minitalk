/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_6.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 19:18:13 by joeduard          #+#    #+#             */
/*   Updated: 2021/08/06 19:18:13 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_neg_number_i_d(t_flags fl, int *len)
{
	ft_putchar_len('-', len);
	ft_putstr_len(fl.strNum, len);
}

int	ft_ulen(unsigned int num)
{
	size_t	len;

	if (num <= 0)
		len = 1;
	else
		len = 0;
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*result;

	len = ft_ulen(n);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (result == NULL)
		return (0);
	result[len] = '\0';
	len--;
	while (len >= 0)
	{
		result[len] = '0' + (n % 10);
		n = n / 10;
		len--;
	}
	return (result);
}

void	print_zero_string_u(t_flags fl, int *len, int size)
{	
	if (fl.minus == 0)
	{
		while (fl.width - size > 0)
		{
			write(1, "0", 1);
			fl.width--;
			(*len)++;
		}
		ft_putstr_len(fl.strNum, len);
	}
	else if (fl.minus == 1)
	{
		ft_putstr_len(fl.strNum, len);
		print_space(fl, size, len);
	}
}

void	print_zero_precision_u(t_flags fl, int size, int *len)
{
	while (fl.precision - size > 0)
	{
		write(1, "0", 1);
		fl.precision--;
		(*len)++;
	}
	ft_putstr_len(fl.strNum, len);
}
