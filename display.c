#include "main.h"

/**
 * _putchar - prints a given character
 * @c: character to be printed
 * Return: integer
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}



/**
 * _printf - prints info
 * @s: info to be printed
 * Return: void
 */
int _printf(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
	return (i);
}
