#include "main.h"

/**
 * _free- data structure
 * @datash: the data structure
 */
void _free(data_shell *datash)
{
	unsigned int i;

	for (i = 0; datash->_environ[i]; i++)
	{
		free(datash->_environ[i]);
	}
	free(datash->_environ);
	free(datash->pid);
}

/**
 * _set- initialization
 * @datash: the data structure
 * @av: vector of arguments
 */
void _set(data_shell *datash, char **av)
{
	unsigned int i;

	datash->av = av;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->counter = 1;

	for (i = 0; environ[i]; i++)
		;
	datash->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		datash->_environ[i] = _strdup(environ[i]);
	}

	datash->_environ[i] = NULL;
	datash->pid = aux_itoa(getpid());
}

/**
 * main- Entry point
 * @ac: number of arguments
 * @av: vector of arguments
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	data_shell datash;
	(void) ac;

	signal(SIGINT, get_sigint);
	_set(&datash, av);
	myloop(&datash);
	_free(&datash);
	if (datash.status < 0)
		return (255);
	return (datash.status);
}
