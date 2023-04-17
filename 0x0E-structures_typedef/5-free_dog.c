#include "dog.h"
/**
*free_dog - freeing dog
*@d: dog in question
*
*
*
*
*
*/

void free_dog(dog_t *d)
{
	if (d == NULL)
	{
		return;
	}
	else
	{
		free(d->owner);
		free(d->name);
		free(d);
	}
}
