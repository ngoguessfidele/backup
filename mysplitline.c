#include "main.h"

char **mysplitline(char *line)
{
	int bufsize = BUFSIZE;
	int i = 0;
	char *token;
	char **tokens_backup;
	char **tokens = malloc(bufsize *sizeof(char *));

	if (!tokens)
	{
		perror("myshell: allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, DELIM);

	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		if (i > bufsize)
		{
			bufsize += BUFSIZE;
			tokens_backup = tokens;
			tokens = realloc(tokens, bufsize *sizeof(char *));
			if (!tokens)
			{
				free(tokens_backup);
				perror("myshell: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIM);
	}
	tokens[i] = NULL;

	return (tokens);
}
