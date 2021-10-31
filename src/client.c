/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:39:29 by joeduard          #+#    #+#             */
/*   Updated: 2021/10/30 21:44:54 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"

static int g_done;

void	wait_server_response(void)
{
	while (g_done == 0)
		;
	g_done = 0;
}

void	send_signal(int bit, int pid, const char *str)
{

	int count;
	
	count = 1 << 7;
	while (count)
	{
		bit = *str & count;
		if (bit)
		{
			if (kill(pid, SIGUSR1))
				exit(EXIT_FAILURE);
		}
		else
		{
			if (kill(pid, SIGUSR2))
			exit(EXIT_FAILURE);
		}
		wait_server_response();
		count >>=1;
	}
}

void	process_str(int pid, const char *str, const char *client)
{
	printf("Sinal enviado\n");
	kill(pid, SIGUSR1);
	while (g_done == 0)
		;
	g_done = 0;
	(void)str;
}

void get_bit(const char *str)
{
	(void)str;

}

void sig_handler(int signum)
{
	g_done = 1;
	(void)signal;
}

int	main (int argc, const char *argv[])
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
	send_bit(pid,argv[2], argv[0]);
	printf("PID Client: %d\n", getpid());
	return (EXIT_SUCCESS);
}
