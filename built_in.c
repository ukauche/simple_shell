#include "shell.h"

/**
 * built_in - Built in command.
 * @args: Arguments.
 * @prog: programe nane.
 * @buff: String to be checked.
 * Return: Returns built in executable.
 */

int built_in(char **args, char *prog, char *buff)
{
	int execute = 0, indx = 0;

	(void)prog;

	if (strcmp(args[0], "exit") == 0)
	{
		free(args);
		free(buff);
		exit(errno);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		while (environ[indx])
		{
			write(1, environ[indx], strlen(environ[indx]));
			write(1, "\n", 1);

			indx++;
		}
		free(args);
		execute = 1;
	}

	return (execute);
}
