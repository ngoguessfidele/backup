#include "main.h"

int mycd(char **arg)
{
	if (arg[1] == NULL)
		fprintf(stderr, "myshell: expected arguments to \"cd\"\n");
	else
		if (chdir(arg[1]) != 0)
			perror("No such directory");
	return 1;
}
