/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:39:29 by joeduard          #+#    #+#             */
/*   Updated: 2021/10/28 22:49:25 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"

static void send_str(int pid, char *str)
{
	printf("String do terminal: %s\n", str);
	kill(pid, SIGUSR1);
	(void)str;
}

static void handler(int signum)
{
	printf("sinal no handle!\n");
}

int	main (int argc, char *argv[])
{
	struct sigaction action;
	int pid;

	if(argc != 3)
	{
		printf("erro 1\n");
		exit(EXIT_FAILURE);
	}
	bzero(&action,sizeof(struct 	sigaction));
	action.sa_handler = handler;
	if (sigaction(SIGUSR1, &action, NULL))
	{
		printf("erro 2\n");
		exit(EXIT_FAILURE);
	}
	pid = atoi(argv[1]);
	send_str(pid,argv[2]);

	return (0);
}
