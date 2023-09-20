#include "general.h"
#include "text.h"
#include "error.h"

/**
 * message_selector - function that selects the command
 * @info: Arguments passed
 * Return: Return the error message
 **/
char *message_selector(general_t info)
{
	int i, n_options;
	error_t messages[] = {
		{_ENOENT, _CODE_ENOENT},
		{_EACCES, _CODE_EACCES},
		{_CMD_NOT_EXISTS, _CODE_CMD_NOT_EXISTS},
		{_ILLEGAL_NUMBER, _CODE_ILLEGAL_NUMBER}
	};

	n_options = sizeof(messages) / sizeof(messages[0]);
	for (i = 0; i < n_options; i++)
		if (info.error_code == messages[i].code)
			return (messages[i].message);
	return ("");
}

/**
 * error - Function that print the error
 * @info: Arguments passed
 * Return: Return void
 **/
void error(general_t *info)
{
	char *number;
	char *message;
	char *aux;
	int size_number, size_message;

	number = NULL;
	message = message_selector(*info);
	number = to_string(info->n_commands);

	size_number = _strlen(number);
	size_message = _strlen(info->argv[0]);

	aux = malloc(size_message + size_number + 3);

	aux = _strcpy(aux, info->argv[0]);
	aux = _strcat(aux, ": ");
	aux = _strcat(aux, number);

	message = join_words(aux, info->command, message, ": ");
	print_err(message);

	free(message);
	free(number);
	free(aux);
}

/**
 * error_extra - function that prints error with more information
 * @info: Argument passed in the shell
 * @extra: More information
 * Return: Return void
 **/
void error_extra(general_t *info, char *extra)
{
	char *aux, *aux2, *number, *message;
	int size_extra, size_number, size_message;

	number = NULL;
	message = message_selector(*info);
	number = to_string(info->n_commands);

	size_number = _strlen(number);
	size_message = _strlen(info->argv[0]);
	size_extra = _strlen(extra);

	aux = malloc(size_message + size_number + 3);
	aux = _strcpy(aux, info->argv[0]);
	aux = _strcat(aux, ": ");
	aux = _strcat(aux, number);

	aux2 = malloc(_strlen(message) + size_extra + 3);
	aux2 = _strcpy(aux2, message);
	aux2 = _strcat(aux2, ": ");
	aux2 = _strcat(aux2, extra);

	message = join_words(aux, info->command, aux2, ": ");
	print_err(message);

	free(message);
	free(number);
	free(aux);
	free(aux2);
}
