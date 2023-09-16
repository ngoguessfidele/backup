#include "main.h"

/**
 * get_help- find the help function
 * @data: the data structure
 * Return: 1 on success
 */
int get_help(myshell *data)
{
	if (data->args[1] == 0)
		help();
	else if (_strcmp(data->args[1], "setenv") == 0)
		helpSetenv();
	else if (_strcmp(data->args[1], "env") == 0)
		helpenv();
	else if (_strcmp(data->args[1], "unsetenv") == 0)
		helpUnset();
	else if (_strcmp(data->args[1], "help") == 0)
		helpHelp();
	else if (_strcmp(data->args[1], "exit") == 0)
		helpexit();
	else if (_strcmp(data->args[1], "cd") == 0)
		helpcd();
	else if (_strcmp(data->args[1], "alias") == 0)
		helpalias();
	else
		write(STDERR_FILENO, data->args[0],
				_strlen(data->args[0]));
	data->status = 0;
	return (1);
}
