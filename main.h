#ifndef MAIN_H
#define NAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define BUFSIZE 1024
#define DELIM " \t\r\n\a"

/* Function prototypes */

int myexit(char **arg);
int myhelp(char **arg);
int mycd(char **arg);
char *myreadline(void);
int myprocess(char **arg);
int myexec(char **arg);
char **mysplitline(char *line);
void myloop(void);
int mylen(void);

#endif
