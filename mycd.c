#include "main.h"

/**
 * mycd- cd costum
 * @arg: argumens
 * Return: 1 on success
 */

int mycd(char **arg)
{
	if (arg[1] == NULL)
		perror("myshell: expected arguments to \"cd\"\n");
	else
		if (chdir(arg[1]) != 0)
			perror("No such directory");
	return (1);
}
