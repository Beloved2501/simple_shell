#include "text.h"

/**
 * _strlen - this funct Return the length of a string
 *
 * @msg: String.
 *
 * Return: returns the Length of the string
 **/
int _strlen(char *msg)
{
	int i;

	for (i = 0; msg[i] != '\0'; i++)
		;

	return (i);
}

/**
 * _strcat - Concatenates two strings
 *
 * @dest: String concatenate
 * @src: Source string
 *
 * Return: A string concatenate
 */
char *_strcat(char *dest, char *src)
{
	int dest1, i;

	dest1 = _strlen(dest);

	for (i = 0; src[i] != '\0'; i++, dest1++)
		dest[dest1] = src[i];

	dest[dest1] = '\0';

	return (dest);
}

/**
 * _strcpy - tje function to Copy a string to another
 *
 * @dest: Destination copy.
 * @src: Source for copy.
 *
 * Return: the funct Return the value of dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}


/**
 * _strdup - this Points to a newly allocated space in memory
 *
 * @str: String to copy.,
 *
 * Return: the function returns String copied
 **/
char *_strdup(char *str)
{
	int size, i;
	char *dest;

	if (str == NULL)
		return (NULL);

	size = _strlen(str) + 1;
	dest = malloc(size * sizeof(char));
	if (dest == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		*(dest + i) = *(str + i);

	/* (dest + i) = 0; */

	return (dest);
}

/**
 * _strcmp - this function Compare two strings
 *
 * @s1: this is the first String
 * @s2: this is the second String
 *
 * Return: returns Integer
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}

	return (0);
}
