#include "main.h"

/**
 * _strcpy - copies string from dest to src
 *  @dest: where the string is to be copied to
 *  @src: where the string is to be copied from
 *
 *  Return: Nothing
 */

void _strcpy(char *dest, const char *src)
{
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
}
