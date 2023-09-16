#include "main.h"

/**
 * exec_line- handle builtin or command
 * @data: the data structure
 * Return: 1 on success
 */
int exec_line(myshell *data)
{
	int (*builtin)(myshell *data);

	if (data->args[0] == NULL)
		return (1);
	builtin = get_builtin(data->args[0]);
	if (builtin != NULL)
		return (builtin(data));
	return (cmd_exec(data));
}
