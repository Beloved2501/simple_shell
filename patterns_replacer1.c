#include "general.h"
#include "text.h"
#include "commands.h"

/**
 * replacement - Entry point to the replacement funct.
 * @info: input value
 * @index: input value.,
 * @string: input value.,
 * Return: the funct returns string
**/

char *replacement(general_t *info, int *index, char *string)
{
	char *temp;
	char symbl;

	(void) index;

	symbl = *string;
	if (symbl != '?' && symbl != '$')
	{
		temp = replace_env(info, string);
		return (temp);
	}

	temp = (symbl == '$') ? to_string(info->pid) :
		to_string(info->status_code);

	return (temp);
}

/**
 * replace_env - Entry Point function that replaces env.
 * @info: input value.
 * @environment: input arguement.
 * Return: the funct returns string.
**/

char *replace_env(general_t *info, char *environment)
{
	char *environ;

	(void) info;

	environ = _getenv(environment);
	if (environ != NULL)
		return (environ);

	return (NULL);
}
