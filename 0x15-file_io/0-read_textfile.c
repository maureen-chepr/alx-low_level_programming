#include "main.h"
#include <unistd.h>
#include <fcntl.h>

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
	char *buffer;
	ssize_t file_descriptor, b_read, b_written, total_b_written;

	if (filename == NULL)
		return (0);
	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(file_descriptor);
		return (0);
	}

	b_read = read(file_descriptor, buffer, letters);
	if (b_read == -1)
	{
		free(buffer);
		close(file_descriptor);
		return (0);
	}

	total_b_written = 0;
	while (b_read > 0)
	{
		b_written = write(STDOUT_FILENO, buffer + total_b_written, b_read);
		if (b_written == -1)
		{
			free(buffer);
			close(file_descriptor);
			return (0);
		}
		total_b_written += b_written;
		b_read -= b_written;
	}
	free(buffer);
	close(file_descriptor);
	return (total_b_written);
}
