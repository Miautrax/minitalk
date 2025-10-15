#include "minitalk.h"

void	signal_handler(int signum)
{
	static unsigned char	current_char = 0;
	static int				bit_count = 0;

	current_char = current_char << 1;
	if (signum == SIGUSR2)
		current_char = current_char | 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (current_char == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", current_char);
		current_char = 0;
		bit_count = 0;
	}
}

void	setup_signals(void)
{
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
}

int main(void)
{
	ft_printf("PID del servidor: %d\n", getpid());
	setup_signals();
	while (1)
		pause();
	return (0);
}
