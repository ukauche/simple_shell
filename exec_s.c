#include "shell.h"

/**
 * exec_s - Executes command.
 * @args: Array of arguments.
 * @argv: Array of command line arguments.
 * @cmmd: Command.
 * Return: Returns Void.
 */

int exec_s(char **args, char **argv, char *cmmd)
{
	int stats;
	pid_t pid;


	pid = fork();
	if (pid < 0)
	{
		perror(cmmd);
		exit(-1);
	}
	else if (pid == 0)
	{
		execve(cmmd, args, environ);
		perror(argv[0]);
		exit(2);
	}
	else
	{
		wait(&stats);

		if (WIFEXITED(stats))
			stats = WEXITSTATUS(stats);
		errno = stats;

		free(cmmd);
		free(args);
	}
	return (stats);
}
