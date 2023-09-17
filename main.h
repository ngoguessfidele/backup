#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

extern char **environ;

/**
 * struct data- data structure
 * @av: vector of arguments
 * @input: line from user
 * @args: tokens
 * @status: shell status
 * @counter: count lines
 * @_environ: environment
 * @pid: process ID
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} myshell;

/**
 * struct sep_list_s- linked list
 * @separator: ; | &
 * @next: node
 * Description: stores separators
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s- linked list
 * @line: command line
 * @next: node
 * Description: store command lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct r_var_list- linked list
 * @len_var: lenght
 * @val: the value
 * @len_val: value length
 * @next: node
 * Description: stores variables
 */
typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;

/**
 * struct builtin_s- builtins commands
 * @name: the name
 * @f: pointer to builtin function
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(myshell *data);
} builtin_t;

/**lists*/
sep_list *add_sep_node_end(sep_list **head, char sep);
void free_sep_list(sep_list **head);
line_list *add_line_node_end(line_list **head, char *line);
void free_line_list(line_list **head);
r_var *add_rvar_node(r_var **head, int lvar, char *var, int lval);
void free_rvar_list(r_var **head);

/* strings */
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);
void rev_string(char *s);

/* memory */
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

/* synthax errors */
int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
int first_char(char *input, int *i);
void print_syntax_error(myshell *data, char *input, int i, int bool);
int check_syntax_error(myshell *data, char *input);

/* loop*/
char *uncomment(char *in);
void myloop(myshell *data);

/*readline*/
char *_readline(int *i_eof);

/* splitline */
char *dontprint(char *input, int bool);
void add_nodes(sep_list **head_s, line_list **head_l, char *input);
void go_next(sep_list **list_s, line_list **list_l, myshell *data);
int split_commands(myshell *data, char *input);
char **split_line(char *input);

/* replace variables */
void check_env(r_var **h, char *in, myshell *data);
int check_vars(r_var **h, char *in, char *st, myshell *data);
char *replaced_input(r_var **head, char *input, char *new_input, int nlen);
char *rep_var(char *input, myshell *data);

/* getline */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

/* execute all */
int exec_line(myshell *data);

/* executes commads */
int is_cdir(char *path, int *i);
char *_which(char *cmd, char **_environ);
int is_executable(myshell *data);
int check_error_cmd(char *dir, myshell *data);
int cmd_exec(myshell *data);

/* environment */
char *_getenv(const char *name, char **_environ);
int _env(myshell *data);
char *copy_info(char *name, char *value);
void set_env(char *name, char *value, myshell *data);
int _setenv(myshell *data);
int _unsetenv(myshell *data);

/* cd */
void cd_dot(myshell *data);
void cd_to(myshell *data);
void cd_previous(myshell *data);
void cd_to_home(myshell *data);
int cd_shell(myshell *data);

/* find builtin_ */
int (*get_builtin(char *cmd))(myshell *data);

/*exit*/
int exit_shell(myshell *data);

/* numbers */
int get_len(int n);
char *aux_itoa(int n);
int _atoi(char *s);

/* errors */
char *strcat_cd(myshell *, char *, char *, char *);
char *cantcd(myshell *data);
char *notfound(myshell *data);
char *cantexit(myshell *data);
char *error_get_alias(char **args);
char *enverror(myshell *data);
char *error_syntax(char **args);
char *error_permission(char **args);
char *nopermission(myshell *data);
int get_error(myshell *data, int eval);

/* signal */
void get_sigint(int sig);

/* help */
void helpenv(void);
void helpSetenv(void);
void helpUnset(void);
void help(void);
void helpexit(void);
void helpHelp(void);
void helpalias(void);
void helpcd(void);
int findhelp(myshell *data);

#endif
