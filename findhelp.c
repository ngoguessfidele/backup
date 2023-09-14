#include "main.h"

/**
 * get_help- find the help function
 * @datash: the data structure
 * Return: 1 on success
 */
int get_help(data_shell *datash)
{
	if (datash->args[1] == 0)
		help();
	else if (_strcmp(datash->args[1], "setenv") == 0)
		helpSetenv();
	else if (_strcmp(datash->args[1], "env") == 0)
		helpenv();
	else if (_strcmp(datash->args[1], "unsetenv") == 0)
		helpUnset();
	else if (_strcmp(datash->args[1], "help") == 0)
		helpHelp();
	else if (_strcmp(datash->args[1], "exit") == 0)
		helpexit();
	else if (_strcmp(datash->args[1], "cd") == 0)
		helpcd();
	else if (_strcmp(datash->args[1], "alias") == 0)
		helpalias();
	else
		write(STDERR_FILENO, datash->args[0],
				_strlen(datash->args[0]));
	datash->status = 0;
	return (1);
}
