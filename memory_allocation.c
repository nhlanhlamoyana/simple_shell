#include "shell.h"

/**
 * _realloc - A pointer to be allocated to double the space
 * @size: The pointer to the number of elements in the old array
 * @ptr: The pointer to the old array
 * Return: Pointer to the new array
 */
char **_realloc(char **ptr, size_t *size)
{
	char **new;
	size_t j;


	new = malloc(sizeof(char *) * ((*size) + 10));
			if (new == NULL)
			{
				free(ptr);
				return (NULL);
			}
			for (j = 0; j < (*size); j++)
			{
				new[j] = ptr[j];
			}
			*size += 10;
			free(ptr);
			return (new);
}
