/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:10:32 by joeduard          #+#    #+#             */
/*   Updated: 2021/10/14 16:48:03 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*aux_dst;
	unsigned char	*aux_src;

	aux_dst = (unsigned char *)dest;
	aux_src = (unsigned char *)src;
	while (n--)
	{
		*(aux_dst++) = *aux_src;
		if (*(aux_src++) == (unsigned char)c)
			return ((char *)aux_dst);
	}
	return (0);
}
