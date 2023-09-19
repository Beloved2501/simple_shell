#include "general.h"
#include "text.h"
#include <unistd.h>

/**
 * _putchar_to_fd - the funct to Print a character to a specific file
 * descriptor
 *
 * @c: this is the Char to print.,
 * @fd: this is where to print the character
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 **/
int _putchar_to_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}


/**
 * print_to_fd - function to Print a str.
 *
 * @msg: this is the Str to print in the fd specified.,
 * @fd: File descriptor to print.
 *
 * Return: On success numbers of bytes printed.
 * On error, -1 is returned, and errno is set appropriately.
 **/
int print_to_fd(char *msg, int fd)
{
	int sizes;

	sizes = _strlen(msg);

	return (write(fd, msg, sizes));
}
