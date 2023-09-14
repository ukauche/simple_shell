#include "shell.h"

/**
 * tokenize - Tokenizes a string.
 * @strng: String to be entered.
 * Return: Returns double pointer of the string.
 */

char **tokenize(char *strng)
{

	int i = 0;
	char *token = NULL, *delim = " \n";
	char **tokenize = NULL;

	tokenize = malloc(sizeof(char *) * 25);
	if (tokenize == NULL)
		return (NULL);

	token = strtok(strng, delim);

	while (token)
	{
		tokenize[i] = token;
		token = strtok(NULL, delim);
		i++;
	}

	tokenize[i] = NULL;
	return (tokenize);
}
