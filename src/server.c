/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:39:35 by joeduard          #+#    #+#             */
/*   Updated: 2021/11/09 20:24:27 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft.h"

char	*put_first_char(char current)
{
	char	*add;
	int		i;

	i = 0;
	add = (char *)malloc(sizeof(char) + 1);
	if (!add)
		return (NULL);
	add[i++] = current;
	add[i] = '\0';
	return (add);
}

char	*ft_add_current(char *str, char current)
{
	char	*add;
	int		i;

	i = 0;
	if (!str)
		return (put_first_char(current));
	if (!current)
		return (NULL);
	add = (char *)malloc(sizeof(char) * (strlen(str) + 2));
	if (!add)
		return (NULL);
	while (str[i])
	{
		add[i] = str[i];
		i++;
	}
	add[i++] = current;
	add[i++] = '\0';
	return (add);
}

void	sig_handler(int signal, siginfo_t *siginfo, void *context)
{
	static int	bits;
	static char	current;
	static char	*message;

	if (current == 0)
		current = 0xFF;
	if (signal == SIGUSR1)
		current |= 0x80 >> bits;
	else if (signal == SIGUSR2)
		current ^= 0x80 >> bits;
	if (++bits == 8)
	{
		if (current)
			message = ft_add_current(message, current);
		else
		{
			message = print_str(message);
			free(message);
			message = NULL;
		}
		current = 0xFF;
		bits = 0;
	}
	kill(siginfo->si_pid, SIGUSR1);
	(void)context;
}

int	save_actions(void)
{
	struct sigaction	action;

	bzero (&action, sizeof(struct sigaction));
	sigemptyset(&action.sa_mask);
	action.sa_sigaction = sig_handler;
	action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &action, NULL))
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &action, NULL))
		exit(EXIT_FAILURE);
	return (0);
}

int	main(void)
{
	printf("Server running... [PID]: %d\n", getpid());
	save_actions();
	while (1)
		pause();
	return (0);
}
