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
	char *tmp;
	char symbol;

	(void) index;

	symbol = *string;
	if (symbol != '?' && symbol != '$')
	{
		tmp = replace_env(info, string);
		return (tmp);
	}

	tmp = (symbol == '$') ? to_string(info->pid) :
		to_string(info->status_code);

	return (tmp);
}

/**
 * replace_env - Entry Point function that replaces env.
 * @info: input value.
 * @environment: input arguement.
 * Return: the funct returns string.
**/

char *replace_env(general_t *info, char *environment)
{
	char *env;

	(void) info;

	env = _getenv(environment);
	if (env != NULL)
		return (env);

	return (NULL);
}
