#include "memory.h"

/**
 * _realloc - the funct Reallocates a mem blck using malloc and free functns.
 *
 * @ptr: the Pointer that points to the memory previously allocated.
 * @old_size: this is Size in bytes, of the allocated space for ptr.,
 * @new_size: this is the New size in bytes of the new memo block.,
 *
 * Return: the function returns Memory reallocated
 **/
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	char *s, *aux;
	unsigned int a;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		s = malloc(new_size);
		if (s == NULL)
			return (NULL);

		return (s);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	s = malloc(new_size);
	if (s == NULL)
		return (NULL);

	aux = ptr;
	for (a = 0; a < old_size; a++)
		s[a] = aux[a];

	free(ptr);

	return (s);
}
