#include "shell.h"

/**
 * putss - Prints a said string.
 * @strng: String being printed.
 * Return: Returns the Void.
 */

void putss(char *strng)
{
	while (*strng)
	{
		put_char(*strng);
		strng++;
		}
}
