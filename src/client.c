/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:39:29 by joeduard          #+#    #+#             */
/*   Updated: 2021/10/29 16:04:15 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"

static int g_done;

static void send_str(int pid, char *str, const char *client)
{
	printf("Sinal enviado\n");
	kill(pid, SIGUSR1);
	while (g_done == 0)
		;
	g_done = 0;
	(void)str;
}

static void sig_handler(int signum)
{
	g_done = 1;
	(void)signal;
}

int	main (int argc, char *argv[])
{
	struct sigaction action;
	int pid;

	if(argc != 3)
		exit(EXIT_FAILURE);
	bzero(&action,sizeof(struct sigaction));
	action.sa_handler = sig_handler;
	if (sigaction(SIGUSR1, &action, NULL))
		exit(EXIT_FAILURE);
	pid = atoi(argv[1]);
	send_str(pid,argv[2], argv[0]);
	printf("PID Client: %d\n", getpid());
	return (EXIT_SUCCESS);
}
