/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:28:00 by joeduard          #+#    #+#             */
/*   Updated: 2021/10/14 16:51:01 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*aux_dest;
	unsigned const char	*aux_src;

	aux_dest = dest;
	aux_src = src;
	i = 0;
	while (i < n && dest != src)
	{
		aux_dest[i] = aux_src[i];
		i++;
	}
	return (aux_dest);
}
