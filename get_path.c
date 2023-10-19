#include "main.h"

/**
 * get_path_directories - gets path to files
 *
 * Return: path to file
 */

char **get_path_directories(void)
{
	char *path = getenv("PATH");
	char *path_copy, **directories, *token;
	int dir_count;

	if (path == NULL)
	{
		perror("PATH environment variable not found.");
		return (NULL); }
	path_copy = _strdup(path);
	if (path_copy == NULL)
	{
		perror("Memory allocation failed.");
		return (NULL); }
	directories = NULL;
	token = strtok(path_copy, ":");
	dir_count = 0;
	while (token != NULL)
	{
		directories = (char **)malloc((dir_count + 1) * sizeof(char *));
		if (directories == NULL)
		{
			perror("Memory allocation failed.");
			free(path_copy);
			return (NULL); }
		directories[dir_count] = _strdup(token);
		if (directories[dir_count] == NULL)
		{
			perror("Memory allocation failed.");
			free(path_copy);
			return (NULL); }
		token = strtok(NULL, ":");
		dir_count++; }
	directories = (char **)malloc((dir_count + 1) * sizeof(char *));
	if (directories == NULL)
	{
		perror("Memory allocation failed.");
		free(path_copy);
		return (NULL); }
	directories[dir_count] = NULL;
	free(path_copy);
	return (directories); }
