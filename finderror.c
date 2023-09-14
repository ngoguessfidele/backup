#include "main.h"

/**
 * get_error- find the error
 * @datash: the data structure
 * @eval: error value
 * Return: error
 */
int get_error(data_shell *datash, int eval)
{
	char *error;

	switch (eval)
	{
		case -1:
			error = enverror(datash);
			break;
		case 126:
			error = nopermission(datash);
			break;
		case 127:
			error = notfound(datash);
			break;
		case 2:
			if (_strcmp("exit", datash->args[0]) == 0)
				error = cantexit(datash);
			else if (_strcmp("cd", datash->args[0]) == 0)
				error = cantcd(datash);
			break;
	}
	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}
	datash->status = eval;
	return (eval);
}
