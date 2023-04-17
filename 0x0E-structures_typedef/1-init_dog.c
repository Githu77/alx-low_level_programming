#include "dog.h"

/**
*init_dog - initialize type dogs variables
*@d: dog
*@name: dog's name
*@age: dog's age
*@owner: dog's owner
*
*/

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
	{
		return;
	}
	else
	{
		(*d).name = name;
		(*d).age = age;
		(*d).owner = owner;
	}
}
