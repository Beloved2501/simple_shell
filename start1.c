#include "general.h"
#include "main.h"
#include "text.h"

/**
 * start - this func Handles the mode.,
 * Description: the Mode can be INTERACTIVE or NON_INTERACTIVE.,
 *
 * @info: Struct of info about the shell.,
 **/
void start(general_t *info)
{
	start_prompt(info);
}
