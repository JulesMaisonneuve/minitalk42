#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "./ft_printf/ft_printf.h"

void	send_char(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR1) != 0)
				exit(EXIT_FAILURE);
		}
		else
		{
			if (kill(pid, SIGUSR2) != 0)
				exit(EXIT_FAILURE);
		}
		if (usleep(50) != 0)
			exit(EXIT_FAILURE);
		i--;
	}
}

void	send_string(char *msg, int pid)
{
	if (msg == NULL)
		exit(EXIT_FAILURE);
	while (*msg)
	{
		send_char(*msg, pid);
		msg++;
	}
	send_char('\0', pid);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*msg;

	if (argc != 3)
	{
		ft_printf("Error: args\n");
		return (EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 0 || kill(pid, 0) != 0)
	{
		ft_printf("Error: invalid PID\n");
		return (EXIT_FAILURE);
	}
	msg = argv[2];
	send_string(msg, pid);
	return (EXIT_SUCCESS);
}
