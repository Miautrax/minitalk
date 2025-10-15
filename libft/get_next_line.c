/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivas-q <arivas-q@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:07:52 by arivas-q          #+#    #+#             */
/*   Updated: 2025/07/16 08:07:04 by arivas-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*safe_strjoin(char *s1, char *s2)
{
	char	*result;

	if (!s1)
		result = gnl_strdup(s2);
	else
		result = gnl_strjoin(s1, s2);
	if (!result)
	{
		free(s1);
		return (NULL);
	}
	free(s1);
	return (result);
}

char	*read_and_store(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!gnl_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = safe_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*extract_line(char	*stash)
{
	int		i;
	char	*line;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	gnl_memcpy(line, stash, i);
	line[i] = '\0';
	return (line);
}

char	*clean_stash(char *stash)
{
	char	*new_stash;
	size_t	len;
	char	*newline_ptr;

	newline_ptr = gnl_strchr(stash, '\n');
	if (!newline_ptr)
	{
		free(stash);
		return (NULL);
	}
	newline_ptr++;
	len = gnl_strlen(newline_ptr);
	if (len == 0)
	{
		free(stash);
		return (NULL);
	}
	new_stash = malloc(len + 1);
	if (!new_stash)
		return (NULL);
	gnl_memcpy(new_stash, newline_ptr, len);
	new_stash[len] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) == -1)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = read_and_store(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}

/*
int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return (1);
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}
*/
