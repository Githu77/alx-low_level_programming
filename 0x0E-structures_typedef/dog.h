#ifndef DOG_H
#define DOG_H

#include <stdlib.h>
#include <stdio.h>
/**
*struct dog - datatype for dog
*@name: dog's name
*@age: dog's age
*@owner: dog's owner
*dog_t - new name for struct dog
*
*/

struct dog
{
	char *name;
	float age;
	char *owner;
};


typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
void print_dog(dog_t *d);

#endif
