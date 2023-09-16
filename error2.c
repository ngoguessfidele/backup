#include "main.h"

/**
 * enverror- env error
 * @data: data structure
 * Return: the message
 */
char *enverror(myshell *data)
{
	int length;
	char *error;
	char *ver_str;
	char *msg;

	ver_str = aux_itoa(data->counter);
	msg = ": Unable to add/remove from environment\n";
	length = _strlen(data->av[0]) + _strlen(ver_str);
	length += _strlen(data->args[0]) + _strlen(msg) + 4;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}

	_strcpy(error, data->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, data->args[0]);
	_strcat(error, msg);
	_strcat(error, "\0");
	free(ver_str);

	return (error);
}

/**
 * nopermission- no permission
 * @data: the data structure
 * Return: the message
 */
char *nopermission(myshell *data)
{
	int length;
	char *ver_str;
	char *error;

	ver_str = aux_itoa(data->counter);
	length = _strlen(data->av[0]) + _strlen(ver_str);
	length += _strlen(data->args[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, data->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, data->args[0]);
	_strcat(error, ": Permission denied\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
}
