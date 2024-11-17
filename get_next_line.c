/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoriyam <kmoriyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:00:59 by kmoriyam          #+#    #+#             */
/*   Updated: 2024/11/17 22:18:15 by kmoriyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

int	ft_getchar(fd)
{
	static char	buf[BUFFER_SIZE];
	static char	*buf_next;
	static int	n;

	if (n == 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
			return (0);
		buf_next = buf;
		printf("n = %d\n", n);
	}
	if (n >= 0)
	{
		n--;
		return ((unsigned char) *buf_next++);
	}
	return (EOF);
}

char	*ft_strjoin_char(const char *s, const char c)
{
	char	*combined_str;
	int		i_s;
	char	*c_to_s;

	if (!s)
		return (NULL);
	write(1, "1\n", 2);
	combined_str  = (char *)malloc(ft_strlen(s) + 1 + 1);
	if (!combined_str)
		return (NULL);
	write(1, "1-2\n", 4);
	c_to_s = (char *)malloc(1);
	if (!c_to_s)
		return (NULL);
	write(1, "1-3\n", 4);
	c_to_s[0] = c;
	i_s = 0;
	while (s[i_s])
	{
		combined_str[i_s] = s[i_s];
		i_s++;
	}
	write(1, "1-4\n", 4);
	combined_str[i_s] = c_to_s[0];
	combined_str[i_s + 1] = '\0';
	return (combined_str);
}
char	*get_next_line(int fd)
{
	// int read_bytes;
	// char read_buf[BUFFER_SIZE];
	static char	*save = "";
	// char	*str1;
	// char	*str2;


	while (1)
	{
		if (ft_getchar(fd) == '\n')
		{
			return (save);
			// read_bytes = read(fd, read_buf, BUFFER_SIZE);
			// if (read_bytes == -1)
			// 	return (NULL);
		}
		else
		{
			write(1, "2\n", 2);
			save = ft_strjoin_char(save, ft_getchar(fd));
			write(1, "3\n", 2);
		}
	}
	// return (read_buf);
}

#include <fcntl.h>

int	main()
{
	int fd;
	int i;
	// char *s;
	char c;

	fd = open("memo.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	i = 0;
	// while (get_next_line(fd))
	while (1)
	{
		// s = get_next_line(fd);
		c = ft_getchar(fd);
		// printf("gnl: s = %s\n", s);
		printf("gch: c = %c\n", c);

		if (!get_next_line(fd))
			return (1);
	}
	// while (i < 1)
	// {
	// 	printf("gnl: %s\n", get_next_line(fd));
	// 	i++;
	// }
	close(fd);
}
