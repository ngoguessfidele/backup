#include "main.h"

int myprocess(char **arg)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(arg[0], arg) == -1)
			perror("No such path");
	exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("Execution failure");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
