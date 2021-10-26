/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 23:48:55 by joeduard          #+#    #+#             */
/*   Updated: 2021/10/14 16:54:17 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;

	dup = (char *)malloc (ft_strlen (s) + 1);
	if (dup == 0)
		return (0);
	ft_memcpy (dup, s, ft_strlen(s) + 1);
	return (dup);
}
