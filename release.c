#include "memory.h"

/**
 * free_memory_p - Function that prints pointer variable
 * @ptr: Pointer to be freed
 * Return: Return void
 **/
void free_memory_p(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}

	ptr = NULL;
}

/**
 * free_memory_pp - Function that free pointer pointing to address of another
 * @ptr: free double pointer
 * Return: Return void
 **/
void free_memory_pp(void **ptr)
{
	void **tmp;

	for (tmp = ptr; *tmp != NULL; tmp++)
		free_memory_p(*tmp);
	free_memory_p(ptr);
}
