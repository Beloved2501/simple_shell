#include "general.h"
#include "text.h"

/**
 * _putchar - this funct Prints a char to STDOUT
 *
 * @c: this is the Character to print.,
 *
 * Return: On success 1
 * On error -1
 **/
int _putchar(char c)
{
	return (write(STDOUT, &c, 1));
}

/**
 * print - this funct Prints a mess to STDOUT
 *
 * @msg: this is the Message to print.,
 *
 * Return: On success number of bytes printed
 * On errror -1, and set the error
 **/
int print(char *msg)
{
	return (print_to_fd(msg, STDOUT));
}
