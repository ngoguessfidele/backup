#include "main.h"

/**
 * myreadline- readline
 * Return: buffer
 */

char *myreadline(void)
{
	int bufsize = BUFSIZE;
	int i = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (!buffer)
	{
		perror("myshell: allocation error\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		c = getchar();
		if (c == EOF || c == '\n')
		{
			buffer[i] = '\0';
			return (buffer);
		}
		else
		{
			buffer[i] = c;
		}
		i++;
		if (i >= bufsize)
		{
			bufsize += BUFSIZE;
			buffer = realloc(buffer, bufsize);
			if (!buffer)
			{
				perror("lsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
