#include "main.h"

/**
 * myhelp- help fun
 * @arg: arguments
 * Return: 1 on success
 */

int myhelp(char **arg)
{
	int i;

	printf("This my simple shell.\n");
	printf("It is a simplified version of shell,\n");
	printf("and it has the following built in commands:\n");
	printf("cd\nhelp\nexit\n");

	return (1);
}
