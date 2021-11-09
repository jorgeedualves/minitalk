/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 00:43:15 by joeduard          #+#    #+#             */
/*   Updated: 2021/11/08 17:17:57 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define _POSIX_SOURCE

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <string.h>
# include <strings.h>
# include <stdlib.h>
# include "../libraries/libft/libft.h"
// # include "../libraries/ft_printf/ft_printf.h"

char	*print_str(char *str);

#endif