/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivas-q <arivas-q@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:08:44 by arivas-q          #+#    #+#             */
/*   Updated: 2025/07/16 08:07:42 by arivas-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>		//open//
# include <unistd.h>	//read, close//
# include <stdlib.h>	//malloc, free//
# include <stddef.h>	//NULL, size_t//
# include <stdio.h>		//prinf, perror//
# include <sys/types.h>	//ssize_t//
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

size_t	gnl_strlen(const char *str);
char	*gnl_strchr(char *s, int c);
char	*safe_strjoin(char *s1, char *s2);
char	*gnl_strjoin(char const *s1, char const *s2);
void	*gnl_memcpy(void *dest, void *src, size_t n);
char	*read_and_store(int fd, char *stash);
char	*extract_line(char	*stash);
char	*clean_stash(char *stash);
char	*get_next_line(int fd);
char	*gnl_strdup(char *s);

#endif
