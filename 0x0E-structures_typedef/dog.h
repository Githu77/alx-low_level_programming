#ifndef DOG_H
#define DOG_H

#include <stdlib.h>
#include <stdio.h>
/**
*struct dog - datatype for dog
*@name: dog's name
*@age: dog's age
*@owner: dog's owner
*
*
*/

struct dog
{
	char *name;
	float age;
	char *owner;
};

/**
*dog_t - new name for struct dog
*
*
*/

typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
void n_dog(dog_t *d);

#endif
