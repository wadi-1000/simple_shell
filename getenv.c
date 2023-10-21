#include "main.h"

/**
 * _getenv - gets environment
 * @name: where environment is gotten from
 *
 * Return: environment
 */

char *_getenv(char *name)
{
	int i = 0;
	
	while (environ[i] != NULL)
	{
		if (_strcmp(environ[i], name) == 0 && environ[i][_strlen(name)] == '=')
		{
			return environ[i] + _strlen(name) + 1;
		}
		i++;
	}
	return (NULL);
}
