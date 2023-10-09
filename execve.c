#include "main.h"

/**
 * exec - shifts the process to execute another program
 * @array: list of the commands that are passed to the prompt
 *
 * Return: NOthing
 */

void exec(char *array[])
{
	if (execve(array[0], array, NULL) == -1)
	{
		perror("./shell: No such file or directory");
	}
}
