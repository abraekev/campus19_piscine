/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:29:30 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/26 15:00:58 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

void	sig_handler_1(int signal)
{
	//write(1, "bit was processed\n", 18);
}

void	sig_handler_2(int signal)
{
	write(1, "EOF processed\n", 14);
}

/*
void	send_char(int pid, char c)
{
	int	i;
	int	bit;

	i = 8;
	while (--i >= 0)
	{
		bit = (c >> i) & 1;
		if (!bit)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		pause();
		usleep(250);
	}
}
*/

void	send_string(int pid, char *s, size_t len)
{
	int	i;
	int	j;
	int	bit;
	
	j = -1;
	while(++j <= len) /*send over characters INCLUDING null string*/
	{
		i = 8;
		while (--i >= 0)
		{
			bit = (s[j] >> i) & 1;
			if (!bit)
				kill(pid, SIGUSR1); // 0
			else
				kill(pid, SIGUSR2); // 1
			pause();
			usleep(400);
		}
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int		pid;
	char	*str;

	if (argc != 3)
		return (ft_printf("Error. Check your arguments.\n"), 0);                
	signal(SIGUSR1, sig_handler_1);
	signal(SIGUSR2, sig_handler_2);	
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (ft_printf("bad pid\n"), 0);
	str = argv[2];
	send_string(pid, str, ft_strlen(str));
	return (0);
}

/*
explaing the sa struct

defining:
struct sigaction	variable_name;
{
name.sa_handler 	= handler_function (used for SIMPLE sighandling, eg. when not using SA_SIGINFO)
name.sa_sigaction	= handler_function (used when dealing with signals with additional info, such as SA_SIGINFO)

name.sa_flags		= 0		(default, simple handling)
name.sa_flags		= SA_SIGINFO 	(extra info)
}

sigemptyset(&name.sa_mask);		(clearing and adding signals to the masked list)
sigaddset(&sa.sa_mask, SIGUSR1);

definition handlers:

SIMPLE
void sig_handler(int signal);

WITH SA_SIGINFO
void sig_handler(int signal, siginfo_t *info, void *context);
*/
