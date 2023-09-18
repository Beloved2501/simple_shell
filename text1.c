#include "text.h"
#include "commands.h"
#include "general.h"
#include "memory.h"

/**
 * prompt - this funct Prints the prompt.,
 *
 * @info: Struct of general info.,
 **/
void prompt(general_t *info)
{
	if (info->mode == NON_INTERACTIVE)
		return;

	print("$ ");
}

/**
 * read_prompt - the funct Reads lines in the prompt.,
 *
 * Return: the function returns  Buffer readed or NULL if EOF was found.,
 **/
char *read_prompt()
{
	char *buf;
	int res;
	size_t size;

	buf = NULL;

	res = getline(&buf, &size, stdin);

	if (res == EOF)
	{
		free_memory_p((void *) buf);
		return (NULL);
	}

	return (buf);
}

/**
 * start_prompt - the function Loops the  reading text,
 *
 * @info: Struct of general info.
 *
 * Return: the function returns Buffer readed or NULL if EOF was found.,
 **/
void start_prompt(general_t *info)
{
	char *buff;
	char **arguments;
	char *path;

	signal(SIGINT, sigintHandler);
	while (1)
	{
		prompt(info);

		path = _getenv("PATH");
		is_current_path(path, info);

		info->environment = path;
		buff = read_prompt();
		if (buff == NULL)
		{
			print(info->mode == INTERACTIVE ? "exit\n" : "");
			free(path);
			break;
		}

		info->n_commands++;
		if (buff[0] != '\n')
		{
			arguments = split_words(buff, " \t\n");

			info->arguments = arguments;
			info->buffer = buff;
			analyze_patterns(info, arguments);
			analyze(arguments, info, buff);

			free_memory_pp((void *) arguments);
		}

		free_memory_p((void *) buff);
		free_memory_p((void *) path);
	}

}

/**
 * sigintHandler - this funct is the Handler for SIGINT
 *
 * @sig_num: Unused parameter.,
 **/
void sigintHandler(int sig_num)
{
	(void) sig_num;

	signal(SIGINT, sigintHandler);
	print("\n$ ");
	fflush(stdout);
}
