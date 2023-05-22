#ifndef STRUCTDOG_H
#define STRUCTDOG_H
/**
 * struct dog - description
 * @name: First type
 * @age: Second type
 * @owner: Third type
 *
 * Description: Longer description
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};
/**
 * dog_t - typedef for struct dog
 */
typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
#endif
