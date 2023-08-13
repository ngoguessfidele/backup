#include "main.h"

/**
 * myloop- loops the shell
 */

void myloop(void)
{
	char *line;
	char **arg;
	int status;

	do {
		printf("myshell$ ");
		line = myreadline();
		arg = mysplitline(line);
		status = myexec(arg);
		free(line);
		free(arg);
	} while (status);
}
