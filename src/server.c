/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:39:35 by joeduard          #+#    #+#             */
/*   Updated: 2021/10/30 21:51:48 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"

static int count;

static void sig_handler(int signal, siginfo_t *siginfo, void *context)
{
	printf("sinal recebido %d\n", siginfo->si_pid);
	if (signal == SIGUSR1)
		write(1, "1", 1);
	if (signal == SIGUSR2)
		write(1, "0", 1);
	kill(siginfo->si_pid, SIGUSR1);
	(void)signal;
	(void)context;
}
int	main (void)

{
	struct sigaction action;
	printf("PID: %d\n",getpid());
	bzero(&action, sizeof(struct sigaction));
	sigemptyset(&action.sa_mask);
	action.sa_sigaction = sig_handler;
	action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &action, NULL))
		exit(EXIT_FAILURE);
	while(1)
		pause;
	return (0);
}
