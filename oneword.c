
#include <stdio.h>
char *ft_one_word(int fd)
{
	char word[1];
	int n;

	n = read(fd, word, 1);
	return word;
}

char *zzz_get_next_line(int fd)
{
	char *word;
	char *line;

	word = (char *)malloc(1);
	word = ft_one_word(fd);
	if (word == EOF)
		return (NULL);
	line = ft_strjoin_char(line, word);
}