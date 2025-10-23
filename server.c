#include "libft/libft.h"
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

static void	init_bits(unsigned char *c, int *bit, int *is_init)
{
	if (!*is_init)
	{
		*c = 0;
		*bit = 7;
		*is_init = 1;
	}
}

static void	server_handler(int sig, siginfo_t *info, void *unused)
{
	static unsigned char	c;
	static int				bit;
	static int				is_init;
	pid_t					client_pid;

	init_bits(&c, &bit, &is_init);
	(void)unused;
	client_pid = 0;
	if (info)
		client_pid = info->si_pid;
	if (sig == SIGUSR2)
		c |= (1 << bit);
	bit--;
	if (bit < 0)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		c = 0;
		bit = 7;
	}
	if (client_pid)
		kill(client_pid, SIGUSR1);
}

static int	setup_signal_action(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = server_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (-1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (-1);
	return (0);
}

static void	print_server_pid(void)
{
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
}

int	main(void)
{
	if (setup_signal_action() == -1)
	{
		ft_putstr_fd("Error: sigaction\n", 2);
		return (1);
	}
	print_server_pid();
	while (1)
		pause();
	return (0);
}
