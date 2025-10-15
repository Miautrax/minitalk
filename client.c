/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivas-q <arivas-q@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:30:32 by arivas-q          #+#    #+#             */
/*   Updated: 2025/10/15 12:55:15 by arivas-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_char(int pid, unsigned char c)
{
    int i;
    int bit;

    i = 7;
    while (i >= 0)
    {
        bit = (c >> i) & 1;
        if (bit == 0)
        {
            if (kill(pid, SIGUSR1) == -1)
                write(2, "Error enviando señal SIGUSR1\n", 29);
        }
        else
        {
            if (kill(pid, SIGUSR2) == -1)
                write(2, "Error enviando señal SIGUSR2\n", 29);
        }
        usleep(50);
        i--;
    }
}

void send_message(int pid, const char *msg)
{
    while (*msg)
    {
        send_char(pid, (unsigned char)*msg);
        msg++;
    }
    send_char(pid, '\0');
}

int main(int argc, char **argv)
{
    int pid;

    if (argc != 3)
    {
        write(2, "Uso: ./client <PID> <mensaje>\n", 32);
        return (1);
    }
    pid = ft_atoi(argv[1]);
    if (pid <= 0)
    {
        write(2, "PID inválido\n", 13);
        return (1);
    }
    send_message(pid, argv[2]);
    return (0);
}
