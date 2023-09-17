#include "main.h"

/**
 * get_builtin- find the builtin
 * @cmd: the command
 * Return: pointer to builtin
 */
int (*get_builtin(char *cmd))(myshell *)
{
	builtin_t builtin[] = {
		{ "env", _env },
		{ "exit", exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv},
		{ "cd", cd_shell},
		{ "help", findhelp},
		{ NULL, NULL}
	};
	int i;

	for (i = 0; builtin[i].name; i++)
	{
		if (_strcmp(builtin[i].name, cmd) == 0)
			break;
	}
	return (builtin[i].f);
}
