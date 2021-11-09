/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappendchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:47:24 by joeduard          #+#    #+#             */
/*   Updated: 2021/11/09 18:48:48 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*put_first_char(char c)
{
	char	*add;
	int		index;

	index = 0;
	add = (char *)malloc(sizeof(char) + 1);
	if (!add)
		return (NULL);
	add[index++] = c;
	add[index] = '\0';
	return (add);
}

char	*ft_strappendchar(char *str, char c)
{
	int		index;
	char	*add;

	index = 0;
	if (!str)
		return (put_first_char(c));
	if (!c)
		return (NULL);
	add = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!add)
		return (NULL);
	while (str[index])
	{
		add[index] = str[index];
		index++;
	}
	add[index++] = c;
	add[index] = '\0';
	return (add);
}
