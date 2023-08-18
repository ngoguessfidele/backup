#include "main.h"

/**
 * custom_realloc- reallocate memory
 * @ptr: pointer to previous memeory
 * @size1: old size
 * @size2: new size
 */

void *custom_realloc(void *ptr, unsigned int size1, unsigned int size2)
{
	char *ptr2, *tmp;
	void *newmem;
	unsigned int i;

	if (size1 == size2)
		return (ptr);
	if (ptr == NULL)
	{
		newmem = malloc(size2);
		if (newmem == NULL)
			return (NULL);
		return (newmem);
	}
	if (size2 == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	ptr2 = ptr;
	newmem = malloc(sizeof(*ptr2) * size2);
	if (newmem == NULL)
	{
		free(ptr);
		return (NULL);
	}
	tmp = newmem;
	i = 0;
	while (i < size1 && i < size2)
	{
		tmp[i] = *ptr2++;
		i++;
	}
	free(ptr);
	return (newmem);
}
