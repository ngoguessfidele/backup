#include "main.h"

/**
 * finderror- find the error
 * @data: the data structure
 * @eval: error value
 * Return: error
 */
int finderror(myshell *data, int eval)
{
	char *error;

	switch (eval)
	{
		case -1:
			error = enverror(data);
			break;
		case 126:
			error = nopermission(data);
			break;
		case 127:
			error = notfound(data);
			break;
		case 2:
			if (_strcmp("exit", data->args[0]) == 0)
				error = cantexit(data);
			else if (_strcmp("cd", data->args[0]) == 0)
				error = cantcd(data);
			break;
	}
	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}
	data->status = eval;
	return (eval);
}
