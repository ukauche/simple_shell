#include "shell.h"

/**
 * arr_free - Frees array of  allocated string.
 * @argc: Number of ac to be freed.
 * @argv: Dynamically allocated array strings.
 * Return: Return Void.
 */

void arr_free(int argc, char *argv[])
{
	int x = 0;

	if (argv)
	{
		for (; x < argc; x++)
		{
			free(argv[x]);
		}
		free(argv);
	}
}
