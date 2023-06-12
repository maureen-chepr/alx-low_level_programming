#include "main.h"

/**
 * read_textfile - function that reads a text file and
 * prints it to the POSIX standard output
 * @filename: pointer to file
 * @letters: number of letters it should read and print
 * Return: actual number of letters it could read and print,
 * otherwise 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t bytes_read;
	int ch;
	size_t count;
	FILE *fp = fopen(filename, "r");

	if (filename == NULL)
	{
		return (0);
	}

	if (fp == NULL)
	{
		return (0);
	}
	bytes_read = 0;
	count = 0;

	while ((ch = fgetc(fp)) != EOF && count < letters)
	{
		fputc(ch, stdout);
		bytes_read++;
		count++;
	}
	fclose(fp);

	if (bytes_read < 0)
	{
		return (0);
	}
	return (bytes_read);
}
