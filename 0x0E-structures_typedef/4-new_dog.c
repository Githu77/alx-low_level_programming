#include "dog.h"

/**
*str_cpy - cpies strings
*@dst: destination of string
*@src: source of string to copy
*
*
*
*
*/

void str_cpy(char *dst, char *src)
{
	while (*src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
}

/**
*str_len - gets length of string
*@s: string in question
*Return: length of string
*
*
*
*/

int str_len(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}

/**
*new_dog - new dog
*@name: it's name
*@age: it's age
*@owner: it's owner
*Return: either NULL or pointer to new dog
*
*
*
*/
dog_t *new_dog(char *name, float age, char *owner)
{
	int nlength, olength;
	dog_t *n_dog_p;

	n_dog_p = (dog_t *) malloc(sizeof(dog_t));

	if (n_dog_p == NULL)
	{
		return (NULL);
	}

	nlength = str_len(name);
	olength = str_len(owner);

	n_dog_p->name = (char *) malloc(nlength + 1);
	n_dog_p->owner = (char *) malloc(olength + 1);

	if (n_dog_p->name == NULL || n_dog_p->owner == NULL || age < 0)
	{
		free(n_dog_p);
		free(n_dog_p->name);
		return (NULL);
	}
	str_cpy(n_dog_p->name, name);
	n_dog_p->age = age;
	str_cpy(n_dog_p->owner, owner);

	n_dog_p->age = age;

	return (n_dog_p);
}
