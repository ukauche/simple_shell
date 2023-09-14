#include "shell.h"

/**
 * execs - Executes command.
 * @args: Array of user arguments.
 * @argv: Array of command line arguments.
 * Return: Void.
 */

int execs(char **args, char **argv)
{

	int stats;
	pid_t pid;


	pid = fork();
	if (pid < 0)
	{
		perror(argv[0]);
		exit(-1);
	}
	else if (pid == 0)
	{
		execve(args[0], args, environ);
		perror(argv[0]);
		exit(2);
	}
	else
	{
		wait(&stats);
		if (WIFEXITED(stats))
			stats = WEXITSTATUS(stats);

		errno = stats;

		free(args);
	}

	return (stats);
}
