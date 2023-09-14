#include "shell.h"

/**
 * main - Shell entry point.
 * @argc: Shell Argument counter.
 * @argv: Shell Argument Vector.
 * Return: Returns Errno.
 */
int main(int argc, char **argv)
{
	int mode = isatty(0), cnt = 0, builtin_stats = 0;
	char *buff = NULL, cmmd, **args = NULL, *full_cmmd = NULL;
	size_t buffer_size = 0;
	ssize_t num = 0;

	errno = 0;
	(void)argc;
	while (1)
	{
		cnt++;
		if (mode == 1)
			write(1, "$ ", 2);
		num = getline(&buff, &buffer_size, stdin);
		if (num == -1)
		{
			free(buff);
			exit(errno);
		}
		check_buf(buff);
		args = tokenize(buff);
		if (args[0] == NULL)
		{
			free(args);
			continue;
		}
		if (access(args[0], X_OK) == -1)
		{
			builtin_stats = built_in(args, argv[0], buff);
			if (builtin_stats == 1)
				continue;
			full_cmmd = path_val(dup_path(), args[0]);
			if (full_cmmd == NULL)
			{
				cmmd = (cnt + '0');
				error_msg(argv[0], cmmd, args[0]);
				free(args);
				errno = 127;
				continue;
			}
			exec_s(args, argv, full_cmmd);
			continue;
		}
		execs(args, argv);
	}
	return (errno);
}
