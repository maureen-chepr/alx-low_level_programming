/**
 * add - adds two integers and returns the result
 * @a: int to be added to b
 * @b: int to be added to a
 * Return: sum of a and b
 */
int add(int a, int b)
{
	int c;

	c = a + b;

	return (c);
}

/**
 * mul - multiplies two integers
 * @a: int to be multiplied by b
 * @b: int to be multiplied by a
 * Return: multiple of a and b
 */

int mul(int a, int b)
{
	return (a * b);
}

/**
 * sub - subtracts two integers
 * @a: int 
 * @b: int 
 * Return: subtraction of a and b
 */

int sub(int a, int b)
{
	return (a - b);

}

/**
 * div - division of two integers
 * @a: int
 * @b: int
 * Return: division of a and b
 */

int div(int a, int b)
{
	if (b != 0)
	return (a / b);
	else
		return (-1);
}

/**
 * mod - modulus of two integers
 * @a: int
 * @b: int
 * Return: division of a and b
 */
int mod(int a, int b)
{
	if (b != 0)
	return (a % b);
	else
		return (-1);
}
