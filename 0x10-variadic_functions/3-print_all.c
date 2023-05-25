#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - function that prints anything
 * @format: types of arguments passed to the function
 */

void print_all(const char * const format, ...)
{
	char *str;
       	int i;
	float f;
	char c;
	unsigned int idx = 0;
	int flag = 0;

	va_list lists;
	va_start(lists, format);

	while (format[idx])
	{
		if (format[idx] == 'c')
		{
			c = (char)va_arg(lists, int);
			printf("%c", c);
			flag = 1;
		}
		else if (format[idx] == 'i')
		{
			i = va_arg(lists, int);
			printf("%d", i);
			flag = 1;
		}
		else if (format[idx] == 'f')
		{
			f = (float)va_arg(lists, double);
			printf("%f", f);
			flag = 1;
		}
		else if (format[idx] == 's')
		{
			str = va_arg(lists, char *);
			if (str == NULL)
			{
				printf("(nil)");
			}
			else
			{
				printf("%s", str);
			}
			flag = 1;
		}
		if (format[idx + 1] != '\0' && flag)
		{
			printf(", ");
			flag = 0;
		}
		idx++;
	}
	va_end(lists);
	printf("\n");
}
