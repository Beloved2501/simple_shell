#include "builtins.h"

/**
 * builtins - function that create builtins
 * @info: variable declared
 * @arguments: Arguments passed in the program
 * Return: If the command passed is a builtins
 * return TRUE if not return FALSE
 **/
int builtins(general_t *info, char **arguments)
{
	int status;

	status = check_builtin(info, arguments);
	if (status == _FALSE)
		return (_FALSE);

	return (_TRUE);
}

/**
 * check_builtin - function that check if the command is a builtin
 * @info: Arguments passed in the program
 * @arguments: Arguments passed in the program
 * Return: If the command is an actual builtin, return TRUE
 * if not FALSE
 **/
int check_builtin(general_t *info, char **arguments)
{
	int i, size;
	builtin_t builtins[] = {
		{"exit", bin_exit},
		{"env", bin_env}
	};

	size = sizeof(builtins) / sizeof(builtins[0]);
	for (i = 0; i < size; i++)
	{
		if (_strcmp(info->command, builtins[i].command) == 0)
		{
			builtins[i].func(info, arguments);
			return (_TRUE);
		}
	}

	return (_FALSE);
}
