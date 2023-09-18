#include "builtins.h"

/**
 * bin_env - function that create environment
 * @info: Argument passed in the program
 * @arguments: second arguments passed in the program
 **/
void bin_env(general_t *info, char **arguments)
{
	(void) info;
	(void) arguments;

	get_full_env();
}
