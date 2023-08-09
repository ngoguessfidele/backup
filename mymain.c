#include "main.h"
/*
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
};*/

int main(int argc, char **argv)
{
	myloop();

	return (EXIT_SUCCESS);
}
