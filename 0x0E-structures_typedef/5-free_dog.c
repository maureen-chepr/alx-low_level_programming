#include <stdlib.h>
#include "dog.h"
/**
 * void_dog - function that frees dogs.
 * @d:pointer
 */

void free_dog(dog_t *d)
{
	if (d == NULL)
        exit(98);

	free(d->name);
	free(d->owner);
	free(d);
}
