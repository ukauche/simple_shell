#include "shell.h"

/**
 * putss - Prints a given string.
 * @strng: String to be printed.
 * Return: Void.
 */

void putss(char *strng)
{
	while (*strng)
	{
		put_char(*strng);
		strng++;
		}
}
