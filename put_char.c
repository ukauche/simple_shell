#include "shell.h"

/**
 * put_char - Prints a character.
 * @x: Character to be printed.
 * Return: Returns an integer.
 */

int put_char(char x)
{
	return (write(2, &x, 1));

}
