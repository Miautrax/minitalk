#include "libft/libft.h"
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

volatile sig_atomic_t	g_ack = 0;

static void	ack_handler(int sig)
{
	(void)sig;
	g_ack = 1;
}

static int	send_char(pid_t pid, unsigned char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_ack = 0;
		if (c & (1 << (7 - bit)))
		{
			if (kill(pid, SIGUSR2) == -1)
				return (-1);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				return (-1);
		}
		while (!g_ack)
			pause();
		bit++;
	}
	return (0);
}

static int	parse_args(int argc, char **argv, pid_t *pid)
{
	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client <PID> <message>\n", 2);
		return (-1);
	}
	*pid = (pid_t)ft_atoi(argv[1]);
	if (*pid <= 0)
	{
		ft_putstr_fd("Error: invalid PID\n", 2);
		return (-1);
	}
	return (0);
}

static int	send_message(pid_t pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		if (send_char(pid, (unsigned char)msg[i]) == -1)
			return (-1);
		i++;
	}
	if (send_char(pid, '\0') == -1)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sa;

	if (parse_args(argc, argv, &pid) == -1)
		return (1);
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = ack_handler;
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_putstr_fd("Error: cannot set signal handler\n", 2);
		return (1);
	}
	if (send_message(pid, argv[2]) == -1)
	{
		ft_putstr_fd("Error: failed to send message\n", 2);
		return (1);
	}
	return (0);
}
