#include "shell.h"

/**
 * path_val - Returns a valid path.
 * @path: String of multiple directories in the path.
 * @cmmd: Command string.
 * Return: Returns a pointer to string or NULL.
 */

char *path_val(char *path, char *cmmd)
{
	size_t leng = 0;
	int indx = 0;
	char **token_path = NULL, *token = NULL;
	char *full_path = NULL, *temp = NULL;

	if (path == NULL)
		return (NULL);

	temp = strtok(path, "=");
	temp = strtok(NULL, "=");

	token_path = malloc(sizeof(char *) * 30);
	if (token_path == NULL)
	{
		free(path);
		return (NULL);
	}

	token = strtok(temp, ":");
	while (token)
	{
		token_path[indx] = token;
		token = strtok(NULL, ":");
		indx++;
	}
	token_path[indx] = NULL;
	indx = 0;

	while (token_path[indx])
	{
		leng = strlen(token_path[indx]) + strlen(cmmd) + 2;
		full_path = malloc(leng);
		strcpy(full_path, token_path[indx]);
		strcat(full_path, "/");
		strcat(full_path, cmmd);

		if (access(full_path, X_OK) == 0)
		{
			free(token_path);
			free(path);
			return (full_path);
		}
		free(full_path);
		full_path = NULL;
		indx++;
	}

	free(token_path);
	free(path);
	return (NULL);
}
