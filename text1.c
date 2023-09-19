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
	char *buffer;
	int result;
	size_t size;

	buffer = NULL;

	result = getline(&buffer, &size, stdin);

	if (result == EOF)
	{
		free_memory_p((void *) buffer);
		return (NULL);
	}

	return (buffer);
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
	char **argums;
	char *path1;

	signal(SIGINT, sigintHandler);
	while (1)
	{
		prompt(info);

		path1 = _getenv("PATH");
		is_current_path(path1, info);

		info->environment = path1;
		buff = read_prompt();
		if (buff == NULL)
		{
			print(info->mode == INTERACTIVE ? "exit\n" : "");
			free(path1);
			break;
		}

		info->n_commands++;
		if (buff[0] != '\n')
		{
			argums = split_words(buff, " \t\n");

			info->arguments = argums;
			info->buffer = buff;
			analyze_patterns(info, argums);
			analyze(argums, info, buff);

			free_memory_pp((void *) argums);
		}

		free_memory_p((void *) buff);
		free_memory_p((void *) path1);
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
