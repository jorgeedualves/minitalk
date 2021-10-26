/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:35:17 by joeduard          #+#    #+#             */
/*   Updated: 2021/07/06 20:35:17 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "stdlib.h"
# include "string.h"
# include <limits.h>

# define FLAGS			"-0.0123456789#+ "
# define NUMBERS		"0123456789"
# define TYPES			"csidupxX%"
# define HEXALOW	"0123456789abcdef"
# define HEXAUPP	"0123456789ABCDEF" 

typedef struct t_flags
{
	int						minus;
	int						zero;
	int						width;
	int						dot;
	int						precision;
	char					*strNum;
	unsigned long long int	ulli;	
	int						hash;
	int						plus;
	int						space;
}	t_flags;

int		ft_printf(const char *format, ...);

void	ft_putchar_len(char c, int *len);
int		ft_strchr(char *s, char c);
size_t	ft_strlen(const char *s);
void	ft_putstr(char *s);
void	ft_putchar(char c);

void	ft_putnbr(int n);
int		ft_len(int num);
int		ft_to_positive(int num);
char	*ft_itoa(int n);
void	ft_putstr_len(char *s, int *len);

void	print_space(t_flags fl, int size, int *len);
void	print_simple_space_width_i_d(t_flags fl, int size, int *len);
void	print_space_or_zero_number_i_d(t_flags fl, int size, int *len);
void	print_space_neg_number_i_d(t_flags fl, int size, int *len);
void	print_simple_space_width_precision_i_d(t_flags fl, int *len);

void	print_zero_i_d(t_flags fl, int size, int *len);
void	print_width_zero_i_d(t_flags fl, int size, int *len);
void	print_precision_zero_i_d(t_flags fl, int size, int *len);
void	print_zero_number_space_i_d(t_flags fl, int size, int *len, int *i);
void	print_neg_zero_variations_i_d(t_flags fl, int size, int *len);

void	print_precision_neg_zero_number_i_d(t_flags fl, int size, int *len);
void	print_width_neg_zero_number_i_d(t_flags fl, int size, int *len);
void	print_neg_precision_zero_number_i_d(t_flags fl, int size, int *len);
void	print_neg_prec_zero_number_space_i_d(t_flags fl, int size, int *len);
void	print_neg_number_space_i_d(t_flags fl, int size, int *len);

void	print_neg_number_i_d(t_flags fl, int *len);
int		ft_ulen(unsigned int num);
char	*ft_uitoa(unsigned int n);
void	print_zero_string_u(t_flags fl, int *len, int size);
void	print_zero_precision_u(t_flags fl, int size, int *len);

void	print_space_string_u(t_flags fl, int *len, int size);
void	print_width_space_u(t_flags fl, int *len);
void	print_precision_zero_u(t_flags fl, int *len);
void	print_simple_zero_xX(t_flags fl, int size, int *len);
t_flags	ft_clean_flags(void);

void	basic_output_check_hash_xX(t_flags fl, int *len, const char c);
void	check_for_plus_and_space_i_d(t_flags fl, int *len);
void	print_simple_space_precision_i_d(t_flags fl, int size, int *len);
void	print_space_width_greater_than_precision(t_flags fl, int *len);

void	print_c(char c, int *len, t_flags fl);

void	print_s(char *c, int *len, t_flags fl);
void	print_space_print_s(char *c, int *len, t_flags fl);
void	print_space_cut_s(char *c, int *len, t_flags fl);
void	print_space_cut_right_s(char *c, int *len, t_flags fl);
void	print_space_cut_left_s(char *c, int *len, t_flags fl);

void	print_i_d(t_flags fl, va_list args, int *len);
void	print_positive_i_d(t_flags fl, int number, int *len);
void	print_negative_i_d(t_flags fl, int number, int *len);
void	print_corner_cases_i_d(t_flags fl, int size, int *len);
void	print_neg_corner_cases_i_d(t_flags fl, int size, int *len);

void	print_u(t_flags fl, va_list args, int *len);
void	print_corner_cases_width_precision_u(t_flags fl, int *len, int *count);
void	print_width_bigger_than_size_u(t_flags fl, int *len);
void	print_zero_corner_cases(t_flags fl, int size, int *len);
void	print_corner_cases_u(t_flags fl, int size, int *len, int *count);

void	print_p(t_flags fl, va_list args, int *len, const char c);
void	print_no_zero_p(t_flags fl, int *len, int size);
void	print_zero_p(t_flags fl, int *len, int size);
void	ft_putstr_len_p(char *s, int *len);
char	*ft_int_to_hex_p(unsigned long int n, const char c);

void	print_xX(t_flags fl, va_list args, int *len, const char c);
int		ft_len_hex(unsigned long int x);
char	*ft_ullitoa_base(unsigned long long int n, char *base);
void	print_corner_cases_xX(t_flags fl, int size, int *len);
void	print_regular_cases_xX(t_flags fl, int size, int *len);

#endif