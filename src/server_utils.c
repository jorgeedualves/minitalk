/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 01:50:05 by joeduard          #+#    #+#             */
/*   Updated: 2021/11/07 01:51:30 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"

char *print_str(char *str)
{
    printf("\nMessage: %s\n", str);
    return (str);
}