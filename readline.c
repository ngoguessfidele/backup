#include "main.h"

/**
 * _readline- reads the input
 * @i_eof: getline return
 * Return: input string
 */
char *_readline(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
