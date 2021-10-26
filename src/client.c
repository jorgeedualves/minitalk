/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:39:29 by joeduard          #+#    #+#             */
/*   Updated: 2021/10/25 16:46:08 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"


static void handler(int signum);

int	main (int argc, char *argv[])
{
	struct sigaction sa;

	if(argc =! 3)
		return(-1);
	sa.sa_handler = handler;
	sigemptype (&sa.sa_mask);	
	sa.sa_flags = 0;
	return (0);
}
