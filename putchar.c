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
