#include "text.h"

/**
 * print_err - this function  is used to Print a message to STDERR
 *
 * @msg: this is the Message to print
 *
 * Return: the No. of bytes printed
 **/
int print_err(char *msg)
{
	return (print_to_fd(msg, STDERR));
}
