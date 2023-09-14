#include "shell.h"

/**
 * check_buf - Checks if string comment.
 * @buff: The string to be checked
 * Return: Returns void.
 */

void check_buf(char *buff)
{
	int x = 0;

	while (buff[x])
	{
		if (x > 0 && buff[x] == '#' && buff[x - 1] != ' ')
			break;

		if (buff[x] == '#')
		{
			buff[x] = '\0';
			break;
		}

		x++;
	}
}
