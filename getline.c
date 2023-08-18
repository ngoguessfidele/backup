#include "main.h"

/**
 * reassign- reassign lineptr
 * @lineptr: line read
 * @n: size of line
 * @buf: buffer
 * @bufsize: buffer size
 */

void reassign(char **lineptr, size_t *n, char *buf, size_t bufsize)
{
	if (*lineptr == NULL)
	{
		if (bufsize > 128)
			*n = bufsize;
		else
			*n = 128;
		*lineptr = buf;
	}
	else if (*n < bufsize)
	{
		if (bufsize > 128)
			*n = bufsize;
		else
			*n = 128;
		*lineptr = buf;
	}
	else
	{
		strcpy(*lineptr, buf);
		free(buf);
	}
}



/**
 * custom_getline- getline implemantation
 * @lineptr: where the line will go
 * @n: size of line
 * @stream: where to read
 * Return: bytes read
 */

ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t index;
	ssize_t red;
	char c = 'a';
	char *buf;
	int one;

	if (index == 0)
		fflush(stream);
	else
		return (-1);
	index = 0;
	buf = malloc(sizeof(char) * 128);
	if (buf == NULL)
		return (-1);
	while (c != '\n')
	{
		one = read(STDIN_FILENO, &c, 1);
		if (one == -1 || (one == 0 && index == 0))
		{
			free(buf);
			return (-1);
		}
		if (one == 0 && index != 0)
		{
			index++;
			break;
		}
		if (index >= 128)
			buf = custom_realloc(buf, index, index + 1);
		buf[index] = c;
		index++;
	}
	buf[index] = '\0';
	reassign(lineptr, n, buf, index);
	red = index;
	if (one != 0)
		index = 0;
	return (red);
}


int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	printf("Enter a line: \n");

	while ((read = custom_getline(&line, &len, stdin)) != -1)
	{
		printf("Read %zu chars:\n", read);
		printf("Line: %s", line);
	}

	free(line);

	return (0);
}
