#include "shell.h"

/**
 * dup_path - Gets and duplicates the path.
 * Return: Strings of PATH Variable.
 */

char *dup_path(void)
{
	char *dups = NULL;
	int x;

	for (x = 0; environ[x] != NULL; x++)
	{
		if (strncmp(environ[x], "PATH", 4) == 0)
			dups = strdup(environ[x]);
	}
	return (dups);
}
