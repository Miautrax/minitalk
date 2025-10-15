#ifndef MINITALK_H
#define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/ft_printf.h"
# include "../libft/libft.h"

void	send_char(int pid, unsigned char c);
void	send_message(int pid, const char *msg);
void	signal_handler(int signum);
void	setup_signals(void);

#endif
