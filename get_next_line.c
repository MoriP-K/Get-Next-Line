/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoriyam <kmoriyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:00:59 by kmoriyam          #+#    #+#             */
/*   Updated: 2024/11/23 17:22:36 by kmoriyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_getchar(int fd)
{
	static char	buf[BUFFER_SIZE];
	static char	*buf_next;
	static int	n;

	if (n == 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
		{
			n = 0;
			buf_next = buf;
			return (EOF);
		}
		buf_next = buf;
	}
	if (n > 0)
	{
		n--;
		return ((unsigned char)*buf_next++);
	}
	return (EOF);
}

char	*ft_strjoin_char(char *s, char c)
{
	char	*combined_str;
	int		i_s;

	if (!s)
		return (NULL);
	combined_str = (char *)malloc(ft_strlen(s) + 1 + 1);
	if (!combined_str)
	{
		free(s);
		return (NULL);
	}
	i_s = 0;
	while (s[i_s])
	{
		combined_str[i_s] = s[i_s];
		i_s++;
	}
	combined_str[i_s] = c;
	combined_str[i_s + 1] = '\0';
	free(s);
	return (combined_str);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*line_ptr;
	int		c;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = (char *)malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	while (1)
	{
		c = ft_getchar(fd);
		if (c == EOF)
		{
			if (line[0])
			{
				// line_ptr = line;
				// free(line);
				return (line);
			}
			else
			{
				free(line);
				return (NULL);
			}
		}
		line_ptr = ft_strjoin_char(line, (char)c);
		if (!line_ptr)
			return (NULL);
		line = line_ptr;
		if (c == '\n')
			break ;
	}
	return (line);
}

// #include <fcntl.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*s;

// 	fd = open("memo.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// 	while (1)
// 	{
// 		s = get_next_line(fd);
// 		printf("%s", s);
// 		if (!s)
// 		{
// 			break ;
// 		}
// 		free(s);
// 	}
// 	// free(s);
// 	close(fd);
// 	// fd = open("memo.txt", O_RDONLY);
// 	// if (fd == -1)
// 	// 	return (1);
// 	// while (1)
// 	// {
// 	// 	s = get_next_line(fd);
// 	// 	printf("%s", s);
// 	// 	if (!s)
// 	// 	{
// 	// 		break ;
// 	// 	}
// 	// }
// 	// close(fd);
// }
