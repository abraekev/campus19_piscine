/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:29:30 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/30 11:34:21 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

// for time recording
#include <time.h>
#include <stdio.h>

double	elapsed_time_ms(struct timespec *start, struct timespec *end)
{
	return ((end->tv_sec - start->tv_sec) * 1000.0
		+ (end->tv_nsec - start->tv_nsec) / 1000000.0);
}


//sigusr1 requires a custom handler,
// but i just need the client to receive the sig to continue.

int	g_sig_received = 0;

void	ft_exit(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

void	sig_handler(int signal)
{
	if (signal == SIGUSR1)
		g_sig_received = 1;
	if (signal == SIGUSR2)
		/*ft_exit("Message was succesfully sent.")*/;
}

void	send_signal(int pid, int bit)
{
	usleep(125);
	if (!bit)
	{
		if (kill(pid, SIGUSR1) == -1)
			ft_exit("Error. Signal was not sent.");
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
			ft_exit("Error. Signal was not sent.");
	}
	while (!g_sig_received)
		pause();
}

void	send_string(int pid, char *s, size_t len)
{
	int	i;
	int	j;
	int	bit;

	j = -1;
	while (++j <= len)
	{
		i = 8;
		while (--i >= 0)
		{
			g_sig_received = 0;
			bit = (s[j] >> i) & 1;
			send_signal(pid, bit);
		}
	}
}

int	main(int argc, char **argv)
{
	struct timespec	start;
	struct timespec	end;
	int				pid;
	char			*str;

	if (argc != 3)
		return (ft_printf("Error. Check your arguments.\n"), 0);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (ft_printf("Error. Bad pid.\n"), 0);
	str = argv[2];
	clock_gettime(CLOCK_MONOTONIC, &start);
	send_string(pid, str, ft_strlen(str));
	clock_gettime(CLOCK_MONOTONIC, &end);
	printf("Elapsed time: %.3f ms\n", elapsed_time_ms(&start, &end));
	return (0);
}

/*
explaing the sa struct

defining:
=========
struct sigaction	variable_name;
{
	name.sa_handler		=	handler_function (used for SIMPLE sighandling,
							eg. when not using SA_SIGINFO)
	name.sa_sigaction	= 	handler_function (used when dealing with signals
   							with additional info, such as SA_SIGINFO)
	name.sa_flags		= 	0			(default, simple handling)
	name.sa_flags		=	SA_SIGINFO 	(extra info)
}

functions used while initiating:
================================
	sigemptyset(&name.sa_mask);	clearing and adding signals to the masked lis,
								sa_mask holds the set of signals that will be
								ignored during the execution of the handler.
	sigaddset(&sa.sa_mask, SIGUSR1);

defining handler functions:
===========================
	SIMPLE:
	void sig_handler(int signal);

	WITH SA_SIGINFO:
	void sig_handler(int signal, siginfo_t *info, void *context);
*/
