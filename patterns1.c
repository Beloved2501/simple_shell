#include "commands.h"
#include "general.h"
#include "memory.h"
#include "text.h"

/**
 * analyze_patterns - the main Entry Point
 * @info: input value.
 * @arguments: input value.
**/

void analyze_patterns(general_t *info, char **arguments)
{
	int i;

	for (i = 0; arguments[i] != NULL; i++)
		arguments[i] = pattern_handler(info, arguments[i]);
}

/**
 * pattern_handler - this is the Entry Point to the funct.
 * @info: input value
 * @string: input value.
 * Return: returns the string
**/

char *pattern_handler(general_t *info, char *string)
{
	int i;

	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == '$' && string[i + 1] != '\0')
			string = replace_value(info, &i, string);
	}

	return (string);
}

/**
 * replace_value - this is the Entry Point to the funct.
 * @info: this is the input value.
 * @index: this is the input value.,
 * @string: input string.
 * Return: the function returns string.,
**/

char *replace_value(general_t *info, int *index, char *string)
{
	int i, new_str, old_str;
	char *val;

	i = *index;
	i++;

	val = replacement(info, index, string + i);
	if (val == NULL)
	{
		string = _strcpy(string, "");

		return (string);
		;
	}

	old_str = _strlen(string);
	new_str = _strlen(val) + 1;

	string = _realloc(string, old_str, new_str);
	string = _strcpy(string, val);

	free_memory_p(val);
	*index = i;
	return (string);
}
