#include "shell.h"

/**
 * error_msg - Prints erro message to standard error.
 * @progm: Name of program.
 * @cnt: Command count.
 * @cmmd: Command to be entered.
 * Return: Void.
 */

void error_msg(char *progm, int cnt, char *cmmd)
{
	putss(progm);
	putss(": ");
	put_char(cnt);
	putss(": ");
	putss(cmmd);
	putss(": not found\n");
}
