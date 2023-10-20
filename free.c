#include "main.h"

/**
 * free_buf - Function that fress the memory used by the array
 * @buf: Array of tokens to free
 *
 * Return: Nothing
 */
void free_buf(char **buf)
{
	int i = 0;

	if (!buf || buf == NULL)
		return;
	while (buf[i])
	{
		free(buf[i]);
		i++;
	}
	free(buf);
}

