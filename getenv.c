#include "main.h"

/**
 * _getenv- getenv custom
 * @name: variable name
 * Return: value
 */

char *_getenv(const char *name)
{
	char *env;
	int len;
	int i;

	if (name == NULL)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
		env = environ[i];
		len = strlen(name);
		if (strncmp(env, name, len) == 0 && env[len] == '=')
			return (env + len + 1);
	}
	return (NULL);
}
