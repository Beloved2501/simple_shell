#include "commands.h"
#include "text.h"
#include "general.h"
#include <unistd.h>
#include <sys/cdefs.h>
#include <string.h>

/**
 * _getenv - function that create environment
 * @name: variable name for environment
 * Return: On success value of @name, NULL if failed
 **/
char *_getenv(const char *name)
{
	char **env;
	char *aux, *token, *value;
	int size;

	size = _strlen((char *) name);

	env = environ;
	while (*env)
	{
		aux = _strdup(*env);

		token = strtok(aux, "=");
		if (token == NULL)
		{
			free(aux);
			return (NULL);
		}

		if (_strlen(token) != size)
		{
			free(aux);
			env++;
			continue;
		}

		if (_strcmp((char *) name, aux) == 0)
		{
			token = strtok(NULL, "=");
			value = _strdup(token);

			free(aux);
			return (value);
		}

		free(aux);
		env++;
	}

	return (NULL);
}

/**
 * which - function that locate the directory to be used
 * @filename: variable declared
 * @info: Arguments passed in the program
 * Return: pointer string with found path or NULL if failed.
 */
char *which(char *filename, general_t *info)
{
	char *path, *tmp_path, *token;
	char *slash;
	int size;

	(void) info;

	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);

	token = strtok(path, ":");

	size = _strlen(filename) + 2;
	slash = malloc(size * sizeof(char));
	slash = _strcpy(slash, "/");
	slash = _strcat(slash, filename);

	for (; token != NULL; token = strtok(NULL, ":"))
	{
		tmp_path = malloc(_strlen(token) + size);
		tmp_path = _strcpy(tmp_path, token);
		tmp_path = _strcat(tmp_path, slash);

		if (is_executable(tmp_path) == PERMISSIONS)
		{
			free(slash);
			free(path);
			return (tmp_path);
		}
		token = strtok(NULL, ":");

		free(tmp_path);
	}

	free(path);
	free(slash);

	return (NULL);
}

/**
 * is_current_path - function that check arrangement of path
 * @path: variable of path to be checked
 * @info: Arguments passed in the program
 * Return: Return void
 **/
void is_current_path(char *path, general_t *info)
{
	info->is_current_path = _FALSE;

	if (path == NULL)
		return;

	if (path[0] == ':')
		info->is_current_path = _TRUE;
}

/**
 * get_full_env - function that get the environment
 * Return: Return void
 **/
void get_full_env(void)
{
	char **tmp;
	int i;

	i = 0;

	tmp = environ;

	while (tmp[i] != NULL)
	{
		print(tmp[i]);
		_putchar('\n');
		i++;
	}
}
