# Minitalk

Implementación básica de Minitalk para School 42 usando las funciones permitidas y la biblioteca `libft` incluida.

Uso:

- En una terminal ejecutar:

  ./server

- En otra terminal ejecutar:

  ./client <PID_del_server> "mensaje a enviar"

Notas:

- El servidor imprime su PID al arrancar.
- El cliente envía cada bit usando señales SIGUSR1 (bit 0) y SIGUSR2 (bit 1).
- Tras enviar cada bit se realiza un pequeño usleep para evitar saturar el servidor.
