#include "main.h"
char *mybuiltin_cmd[] =
{
	"cd",
	"help",
	"exit"
};

int (*mybuiltin_fun[])(char **) =
{
	&mycd,
	&myhelp,
	&myexit
};

int mylen(void)
{
	return (sizeof(mybuiltin_cmd) / sizeof(char*));
}

int myexec(char **arg)
{
	int i;

	if (arg[0] == NULL)
		return (1);
	for (i = 0; i < mylen(); i++)
		if (strcmp(arg[0], mybuiltin_cmd[i]) == 0)
			return ((*mybuiltin_fun[i])(arg));
	return (myprocess(arg));
}
