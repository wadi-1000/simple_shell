#include "main.h"

/**
 * _isatty - helps to correctly print "$ "
 * @fd: checks stdin
 *
 * Return: 1 if its terminal 0 otherwise
 */

int _isatty(int fd)
{
	struct stat buf;

	return (fstat(fd, &buf) == 0 && S_ISCHR(buf.st_mode));
}
