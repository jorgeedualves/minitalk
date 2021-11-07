/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:39:35 by joeduard          #+#    #+#             */
/*   Updated: 2021/11/07 01:28:52 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char *put_firt_char(char current)
{
    char *add;
    int i;

    i = 0;
    add = (char *)malloc(sizeof(char)+ 1);
    if(!add)
        return(NULL);
    add[i++] = current;
    add[i] = "\0";
    return (add);
}

char    *ft_addcurrent (char *str, char current)
{
    char *add;
    int i;

    i = 0;
    if(!current)
        return(put_first_char(current));
    add = (char *)malloc(sizeof(char) * (strlen(str)+ 2));
    if(!add)
    {
        free(str);
        return(NULL);
    }
}  

void *convert_str(char *message)
{
    ft_putstr_fd(message, 1);
    free(message);
    return(NULL);
}
*/
void sig_handler(int signal, siginfo_t *siginfo, void *context)
{
    static int bits = 0;
    static char current;
    static char *message;

    message = 0;

    if (signal == SIGUSR1)
        current |= (0x80 >> bits);
    else if (signal == SIGUSR2)
        current ^= (0x80 >> bits);
    printf("Current: %c \n", (int)current);
   
    if (++bits == 8)
    {
         printf("bit: %d\n", bits);
         bits = 0;
         current = 0xFF;

    }
       
    /*{
    
        if(current)
            message = ft_addcurrent(message, current);
        else
            message = convert_str(message);  
    }
    */
    kill(siginfo->si_pid, SIGUSR1);
    
	(void)context;
}

int save_actions(void)
{
    struct sigaction action;
    bzero(&action, sizeof(struct sigaction));
    sigemptyset(&action.sa_mask);
    action.sa_sigaction = sig_handler;
    action.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR1, &action, NULL))
        exit(EXIT_FAILURE);
    if (sigaction(SIGUSR2, &action, NULL))
		    exit(EXIT_FAILURE);
    return (0);
}
    
int main(void)
{
    printf("Server running... [PID]: %d\n", getpid());
    save_actions();
    while (1)
        pause();
    return (0);
}
