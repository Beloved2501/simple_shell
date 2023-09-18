#include "builtins.h"
#include "general.h"

/**
 * bin_exit - function that implement the exit command
 * @info: Arguments passed
 * @arguments: Arguments received
 **/
void bin_exit(general_t *info, char **arguments)
{
	int status_code, status;

	status = _TRUE;
	if (arguments[1] != NULL)
		status = number_controller(info, arguments[1]);

	if (status == _FALSE)
		return;

	status_code = info->status_code;

	free_memory_pp((void **) arguments);
	free_memory_p((void *) info->buffer);
	free_memory_p((void *) info->environment);
	free_memory_p((void *) info);

	exit(status_code);
}

/**
 * number_controller - Function that control the argument exit
 * @info: Arguments passed
 * @number: Argument to be received
 * Return: Return _TRUE if argument valid, _FALSE if not
 **/
int number_controller(general_t *info, char *number)
{
	int _number;

	_number = _atoi(number);

	if (_number < 0 || contains_letter(number))
	{
		info->status_code = 2;
		info->error_code = _CODE_ILLEGAL_NUMBER;
		error_extra(info, number);
		return (_FALSE);
	}

	if (_number > 255)
		info->status_code = _number % 256;
	else
		info->status_code = _number;

	return (_TRUE);
}
