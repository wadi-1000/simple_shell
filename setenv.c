#include "main.h"

int find_env_var(const char *name);
int environ_size();

/**
 * _fprintf - prints
 * @stream: file operation
 * @format: args
 *
 * Return: length of output
 */

int _fprintf(FILE *stream, const char *format, ...)
{
	char buffer[1024];
	va_list args;
	int i = 0;

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'd')
			{
				int num = va_arg(args, int);
				int j = 0;
				while (num > 0)
				{
					buffer[i++] = num % 10 + '0';
					num /= 10;
					j++;
				}
				while (j-- > 0)
				{
					stream->_IO_write_ptr[-1] = buffer[--i];
					stream->_IO_write_ptr--;
				}
			}
			else if (format[i + 1] == 's')
			{
				char *str = va_arg(args, char *);
				
				while (*str != '\0')
				{
					stream->_IO_write_ptr[-1] = *str++;
					stream->_IO_write_ptr--;
				}
            }
			else
				return (-1);
			i += 2;
		}
		else
		{
			stream->_IO_write_ptr[-1] = format[i++];
			stream->_IO_write_ptr--;
		}
	}
	va_end(args);
	return i;
}

/**
 * _setenv - sets the environment
 * @value: new environment name
 * @overwrite: checks whether variable exists
 *
 * Return: int
 */

int _setenv(const char *name, const char *value, int overwrite)
{
       	int len = strlen(name) + strlen(value) + 2;
	char *env = malloc(len);
	char **new_environ;
	int i, j, k;

	if (env == NULL)
		return (-1);
	i = 0;
	while (name[i] != '\0')
	{
		env[i] = name[i];
		i++;
	}
	env[i] = '=';
	i++;
	j = 0;
	while (value[j] != '\0')
	{
		env[i] = value[j];
		i++;
		j++;
	}
	env[i] = '\0';
	if (overwrite == 0 && find_env_var(name) != -1)
		return (0);
	
	new_environ = malloc(sizeof(char *) * (environ_size() + 2));
	if (new_environ == NULL)
		return (-1);
	k = 0;
	while (environ[k] != NULL)
	{
		new_environ[k] = environ[k];
		k++;
	}
	new_environ[k++] = env;
	new_environ[k] = NULL;
	environ = new_environ;
	return (0);
}

/**
 * environ_size - sets environment size
 *
 * Return: int
 */

int environ_size()
{
	int size = 0;

	while (environ[size] != NULL)
		size++;
	return (size);
}

/**
 * find_env_var - finds env variables
 * @name: pointer to variable strings
 *
 * Return: int
 */

int find_env_var(const char *name)
{
    int i = 0;
    
    while (environ[i] != NULL)
    {
	    if (_strcmp(environ[i], name) == 0)
		    return i;
	    i++;
    }
    return (-1);
}
