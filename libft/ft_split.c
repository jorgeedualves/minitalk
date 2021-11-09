/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 22:03:48 by joeduard          #+#    #+#             */
/*   Updated: 2021/10/14 17:02:38 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	n_word;
	int	control;

	i = 0;
	control = 0;
	n_word = 0;
	while (s[i] != '\0' && *s != '\0')
	{
		if (s[i] != c && control == 0)
		{
			control = 1;
			n_word++;
		}
		else if (s[i] == c)
			control = 0;
		i++;
	}
	return (n_word);
}

static char	*string(const char *s, int init, int end)
{
	char	*string;
	int		len;
	int		i;

	len = end - init + 1;
	string = (char *)malloc((len * sizeof(char)));
	if (string == 0)
		return (NULL);
	i = 0;
	while (init < end)
		string[i++] = s[init++];
	string[i] = '\0';
	return (string);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		init_w;
	int		i;
	int		j;

	if (s == 0)
		return (NULL);
	i = -1;
	j = 0;
	init_w = -1;
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (split == 0)
		return (NULL);
	while ((size_t)++i <= ft_strlen(s))
	{
		if (s[i] != c && init_w < 0)
			init_w = i;
		else if ((s[i] == c || (size_t)i == ft_strlen(s)) && init_w >= 0)
		{
			split[j++] = string(s, init_w, i);
			init_w = -1;
		}
	}
	split[j] = NULL;
	return (split);
}
