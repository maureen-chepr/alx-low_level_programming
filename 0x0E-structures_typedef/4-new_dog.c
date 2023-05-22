#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - function that creates a new dog
 * @name: pointer to name string
 * @age: age of the dog
 * @owner: pointer to owner string
 *
 * Return: pointer to the newly created dog, or NULL if the function fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog;
	int count = 0, new_name = 0, new_owner = 0;

	new_dog = malloc(sizeof(*new_dog));
	if (new_dog == NULL || name == NULL || owner == NULL)
	{
		return (NULL);
	}
	while (name[new_name])
		new_name++;
	while (owner[new_owner])
		new_owner++;
	new_dog->name = malloc(new_name + 1);
	new_dog->owner = malloc(new_owner + 1);

	if (new_dog->name == NULL || new_dog->owner == NULL)
	{
		free(new_dog->owner);
		free(new_dog->name);
		free(new_dog);
		return (NULL);
	}
	while (count < new_name)
	{
		new_dog->name[count] = name[count];
		count++;
	}
	new_dog->name[count] = '\0';
	new_dog->age = age;

	count = 0;
	while (count < new_owner)
	{
		new_dog->owner[count] = owner[count];
		count++;
	}
	new_dog->owner[count] = '\0';
	return (new_dog);
}
