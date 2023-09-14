#include "shell.h"

/**
 * put_char -This will Prints a character.
 * @x: Character to be printed.
 * Return: Returns integer.
 */

int put_char(char x)
{
	return (write(2, &x, 1));

}
