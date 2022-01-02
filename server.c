#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <execinfo.h>
#include "./ft_printf/ft_printf.h"

typedef struct s_str_builder {
	int		bit_count;
	char	c;
}				t_str_builder;

t_str_builder	g_strbuilder;

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	g_strbuilder.c = g_strbuilder.c << 1;
	if (sig == SIGUSR1)
		g_strbuilder.c++;
	g_strbuilder.bit_count += 1;
	if (g_strbuilder.bit_count % 8 == 0)
	{
		if (g_strbuilder.c == '\0')
			ft_putchar('\n');
		else
			ft_putchar(g_strbuilder.c);
		g_strbuilder.c = 0;
	}
}

int	main(void)
{
	struct sigaction	signal_1;
	struct sigaction	signal_0;

	signal_1.sa_sigaction = sig_handler;
	signal_0.sa_sigaction = sig_handler;
	signal_1.sa_flags = SA_SIGINFO;
	signal_0.sa_flags = SA_SIGINFO;
	ft_printf("PID : %d\n", getpid());
	g_strbuilder.bit_count = 0;
	if (sigaction(SIGUSR1, &signal_1, NULL) == -1)
		return (EXIT_FAILURE);
	if (sigaction(SIGUSR2, &signal_0, NULL) == -1)
		return (EXIT_FAILURE);
	while (1)
		pause();
	return (0);
}
